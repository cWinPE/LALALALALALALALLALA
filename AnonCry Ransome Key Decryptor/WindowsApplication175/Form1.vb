﻿Imports System
Imports System.Text
Imports System.Security.Cryptography
Imports System.IO
Public Class Form1

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            TextBox2.Text = My.Settings.ky
            TextBox3.Text = My.Settings.iv
        Catch ex As Exception

        End Try
    End Sub
    Public Function DecryptRJ256(ByVal prm_key As String, ByVal prm_iv As String, ByVal prm_text_to_decrypt As String)
        Try
            Dim sEncryptedString As String = prm_text_to_decrypt

            Dim myRijndael As New RijndaelManaged
            myRijndael.Padding = PaddingMode.Zeros
            myRijndael.Mode = CipherMode.CBC
            myRijndael.KeySize = 256
            myRijndael.BlockSize = 256

            Dim key() As Byte
            Dim IV() As Byte

            key = System.Text.Encoding.UTF8.GetBytes(prm_key)
            IV = System.Text.Encoding.UTF8.GetBytes(prm_iv)

            Dim decryptor As ICryptoTransform = myRijndael.CreateDecryptor(key, IV)

            Dim sEncrypted As Byte() = Convert.FromBase64String(sEncryptedString)

            Dim fromEncrypt() As Byte = New Byte(sEncrypted.Length) {}

            Dim msDecrypt As New MemoryStream(sEncrypted)
            Dim csDecrypt As New CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read)

            csDecrypt.Read(fromEncrypt, 0, fromEncrypt.Length)

            Return (System.Text.Encoding.UTF8.GetString(fromEncrypt))
        Catch ex As Exception
            MessageBox.Show(ex.Message)
            Return Nothing
        End Try



    End Function

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Try
            My.Settings.ky = TextBox2.Text
            My.Settings.iv = TextBox3.Text
            My.Settings.Save()
        Catch ex As Exception

        End Try

        Try
            Dim sKy As String = TextBox2.Text   '32 chr shared ascii string (32 * 8 = 256 bit)
            Dim sIV As String = TextBox3.Text   '32 chr shared ascii string (32 * 8 = 256 bit)



            TextBox1.Text = (DecryptRJ256(sKy, sIV, TextBox1.Text))

        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try




    End Sub
End Class
