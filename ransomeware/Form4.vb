﻿Imports System.IO

Public Class Form4
    Public Shared listenc As List(Of String) = New List(Of String)()
    Private Sub Form4_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        On Error Resume Next
        Me.Text = "Encrypted Files (" & listenc.Count & ")"
        For Each encfiles In listenc
            ListBox1.Items.Add(encfiles)
        Next
    End Sub

    Private Sub OpenLocationToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles OpenLocationToolStripMenuItem.Click
        Try
            Process.Start("explorer.exe", "/select," + ListBox1.SelectedItem)
        Catch ex As Exception

        End Try

    End Sub

    Private Sub ListBox1_MouseDown(sender As Object, e As MouseEventArgs) Handles ListBox1.MouseDown
        If e.Button = MouseButtons.Right Then ListBox1.SelectedIndex = ListBox1.IndexFromPoint(e.X, e.Y)
    End Sub

End Class