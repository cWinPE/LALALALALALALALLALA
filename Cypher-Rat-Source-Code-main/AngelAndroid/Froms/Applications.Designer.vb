﻿<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Applications
    Inherits System.Windows.Forms.Form
      <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub
      Private components As System.ComponentModel.IContainer
        <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim DataGridViewCellStyle1 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle2 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle3 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle4 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle5 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Me.DGV0 = New System.Windows.Forms.DataGridView()
        Me.Column1 = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Column6 = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Column9 = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Column2 = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Column3 = New System.Windows.Forms.DataGridViewImageColumn()
        Me.ctx = New System.Windows.Forms.ContextMenuStrip(Me.components)
        Me.OpenToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.RefreshToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.PropertiesToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.SaveToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.SaveAsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.TOpacity = New System.Windows.Forms.Timer(Me.components)
        Me.PB = New System.Windows.Forms.ProgressBar()
        Me.BoxTitle = New System.Windows.Forms.PictureBox()
        Me.DisableToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.EnableToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        CType(Me.DGV0, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.ctx.SuspendLayout()
        CType(Me.BoxTitle, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'DGV0
        '
        Me.DGV0.AllowUserToAddRows = False
        Me.DGV0.AllowUserToDeleteRows = False
        Me.DGV0.AllowUserToResizeColumns = False
        Me.DGV0.AllowUserToResizeRows = False
        DataGridViewCellStyle1.BackColor = System.Drawing.Color.Black
        DataGridViewCellStyle1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(95, Byte), Integer), CType(CType(95, Byte), Integer), CType(CType(250, Byte), Integer))
        DataGridViewCellStyle1.SelectionBackColor = System.Drawing.Color.White
        DataGridViewCellStyle1.SelectionForeColor = System.Drawing.Color.Black
        Me.DGV0.AlternatingRowsDefaultCellStyle = DataGridViewCellStyle1
        Me.DGV0.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells
        Me.DGV0.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells
        Me.DGV0.BackgroundColor = System.Drawing.Color.Black
        Me.DGV0.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.DGV0.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None
        Me.DGV0.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None
        DataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft
        DataGridViewCellStyle2.BackColor = System.Drawing.Color.Black
        DataGridViewCellStyle2.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        DataGridViewCellStyle2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(95, Byte), Integer), CType(CType(95, Byte), Integer), CType(CType(250, Byte), Integer))
        DataGridViewCellStyle2.SelectionBackColor = System.Drawing.Color.White
        DataGridViewCellStyle2.SelectionForeColor = System.Drawing.Color.Black
        DataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.DGV0.ColumnHeadersDefaultCellStyle = DataGridViewCellStyle2
        Me.DGV0.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.DGV0.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.Column1, Me.Column6, Me.Column9, Me.Column2, Me.Column3})
        Me.DGV0.ContextMenuStrip = Me.ctx
        DataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft
        DataGridViewCellStyle3.BackColor = System.Drawing.Color.Black
        DataGridViewCellStyle3.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        DataGridViewCellStyle3.ForeColor = System.Drawing.Color.FromArgb(CType(CType(95, Byte), Integer), CType(CType(95, Byte), Integer), CType(CType(250, Byte), Integer))
        DataGridViewCellStyle3.SelectionBackColor = System.Drawing.Color.White
        DataGridViewCellStyle3.SelectionForeColor = System.Drawing.Color.Black
        DataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.[False]
        Me.DGV0.DefaultCellStyle = DataGridViewCellStyle3
        Me.DGV0.Dock = System.Windows.Forms.DockStyle.Fill
        Me.DGV0.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically
        Me.DGV0.EnableHeadersVisualStyles = False
        Me.DGV0.GridColor = System.Drawing.Color.FromArgb(CType(CType(42, Byte), Integer), CType(CType(42, Byte), Integer), CType(CType(42, Byte), Integer))
        Me.DGV0.Location = New System.Drawing.Point(0, 0)
        Me.DGV0.Margin = New System.Windows.Forms.Padding(4, 4, 4, 4)
        Me.DGV0.Name = "DGV0"
        Me.DGV0.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.[Single]
        DataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft
        DataGridViewCellStyle4.BackColor = System.Drawing.Color.Black
        DataGridViewCellStyle4.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        DataGridViewCellStyle4.ForeColor = System.Drawing.Color.FromArgb(CType(CType(95, Byte), Integer), CType(CType(95, Byte), Integer), CType(CType(250, Byte), Integer))
        DataGridViewCellStyle4.SelectionBackColor = System.Drawing.Color.White
        DataGridViewCellStyle4.SelectionForeColor = System.Drawing.Color.Black
        DataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.DGV0.RowHeadersDefaultCellStyle = DataGridViewCellStyle4
        Me.DGV0.RowHeadersVisible = False
        DataGridViewCellStyle5.BackColor = System.Drawing.Color.Black
        DataGridViewCellStyle5.ForeColor = System.Drawing.Color.FromArgb(CType(CType(95, Byte), Integer), CType(CType(95, Byte), Integer), CType(CType(250, Byte), Integer))
        DataGridViewCellStyle5.SelectionBackColor = System.Drawing.Color.White
        DataGridViewCellStyle5.SelectionForeColor = System.Drawing.Color.Black
        Me.DGV0.RowsDefaultCellStyle = DataGridViewCellStyle5
        Me.DGV0.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect
        Me.DGV0.Size = New System.Drawing.Size(552, 263)
        Me.DGV0.TabIndex = 4
        '
        'Column1
        '
        Me.Column1.HeaderText = "App Name"
        Me.Column1.Name = "Column1"
        Me.Column1.Width = 105
        '
        'Column6
        '
        Me.Column6.HeaderText = "Type"
        Me.Column6.Name = "Column6"
        Me.Column6.Width = 67
        '
        'Column9
        '
        Me.Column9.HeaderText = "App ID"
        Me.Column9.Name = "Column9"
        Me.Column9.Width = 80
        '
        'Column2
        '
        Me.Column2.HeaderText = "Install Time"
        Me.Column2.Name = "Column2"
        Me.Column2.Width = 114
        '
        'Column3
        '
        Me.Column3.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None
        Me.Column3.FillWeight = 1.0!
        Me.Column3.HeaderText = ""
        Me.Column3.MinimumWidth = 2
        Me.Column3.Name = "Column3"
        Me.Column3.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Programmatic
        Me.Column3.Width = 2
        '
        'ctx
        '
        Me.ctx.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.ctx.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.OpenToolStripMenuItem, Me.RefreshToolStripMenuItem, Me.PropertiesToolStripMenuItem, Me.EnableToolStripMenuItem, Me.DisableToolStripMenuItem, Me.SaveToolStripMenuItem, Me.SaveAsToolStripMenuItem})
        Me.ctx.Name = "ctx"
        Me.ctx.ShowImageMargin = False
        Me.ctx.Size = New System.Drawing.Size(186, 200)
        '
        'OpenToolStripMenuItem
        '
        Me.OpenToolStripMenuItem.Name = "OpenToolStripMenuItem"
        Me.OpenToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.OpenToolStripMenuItem.Text = "Open"
        '
        'RefreshToolStripMenuItem
        '
        Me.RefreshToolStripMenuItem.Name = "RefreshToolStripMenuItem"
        Me.RefreshToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.RefreshToolStripMenuItem.Text = "Refresh"
        '
        'PropertiesToolStripMenuItem
        '
        Me.PropertiesToolStripMenuItem.Name = "PropertiesToolStripMenuItem"
        Me.PropertiesToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.PropertiesToolStripMenuItem.Text = "Properties"
        '
        'SaveToolStripMenuItem
        '
        Me.SaveToolStripMenuItem.Name = "SaveToolStripMenuItem"
        Me.SaveToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.SaveToolStripMenuItem.Text = "Save"
        Me.SaveToolStripMenuItem.Visible = False
        '
        'SaveAsToolStripMenuItem
        '
        Me.SaveAsToolStripMenuItem.Name = "SaveAsToolStripMenuItem"
        Me.SaveAsToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.SaveAsToolStripMenuItem.Text = "Save As"
        Me.SaveAsToolStripMenuItem.Visible = False
        '
        'TOpacity
        '
        Me.TOpacity.Interval = 1
        '
        'PB
        '
        Me.PB.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.PB.Location = New System.Drawing.Point(0, 263)
        Me.PB.Margin = New System.Windows.Forms.Padding(4, 4, 4, 4)
        Me.PB.Name = "PB"
        Me.PB.Size = New System.Drawing.Size(552, 12)
        Me.PB.TabIndex = 6
        '
        'BoxTitle
        '
        Me.BoxTitle.BackColor = System.Drawing.Color.Black
        Me.BoxTitle.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.BoxTitle.ErrorImage = Nothing
        Me.BoxTitle.InitialImage = Nothing
        Me.BoxTitle.Location = New System.Drawing.Point(0, 275)
        Me.BoxTitle.Margin = New System.Windows.Forms.Padding(4, 4, 4, 4)
        Me.BoxTitle.Name = "BoxTitle"
        Me.BoxTitle.Size = New System.Drawing.Size(552, 22)
        Me.BoxTitle.TabIndex = 7
        Me.BoxTitle.TabStop = False
        '
        'DisableToolStripMenuItem
        '
        Me.DisableToolStripMenuItem.Name = "DisableToolStripMenuItem"
        Me.DisableToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.DisableToolStripMenuItem.Text = "Disable"
        '
        'EnableToolStripMenuItem
        '
        Me.EnableToolStripMenuItem.Name = "EnableToolStripMenuItem"
        Me.EnableToolStripMenuItem.Size = New System.Drawing.Size(185, 24)
        Me.EnableToolStripMenuItem.Text = "Enable"
        '
        'Applications
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(552, 297)
        Me.Controls.Add(Me.DGV0)
        Me.Controls.Add(Me.PB)
        Me.Controls.Add(Me.BoxTitle)
        Me.Margin = New System.Windows.Forms.Padding(4, 4, 4, 4)
        Me.Name = "Applications"
        Me.Opacity = 0R
        Me.ShowIcon = False
        Me.Text = "Applications"
        CType(Me.DGV0, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ctx.ResumeLayout(False)
        CType(Me.BoxTitle, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents DGV0 As DataGridView
    Friend WithEvents ctx As ContextMenuStrip
    Friend WithEvents OpenToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents SaveToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents SaveAsToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents TOpacity As Timer
    Friend WithEvents PB As ProgressBar
    Friend WithEvents BoxTitle As PictureBox
    Friend WithEvents PropertiesToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents RefreshToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents Column1 As DataGridViewTextBoxColumn
    Friend WithEvents Column6 As DataGridViewTextBoxColumn
    Friend WithEvents Column9 As DataGridViewTextBoxColumn
    Friend WithEvents Column2 As DataGridViewTextBoxColumn
    Friend WithEvents Column3 As DataGridViewImageColumn
    Friend WithEvents EnableToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents DisableToolStripMenuItem As ToolStripMenuItem
End Class
