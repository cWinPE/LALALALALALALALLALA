﻿<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.NotifyIcon1 = New System.Windows.Forms.NotifyIcon(Me.components)
        Me.GrayForm1 = New Pc_Klit_V._3._0.GrayForm()
        Me.GrayButton3 = New Pc_Klit_V._3._0.GrayButton()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.GrayContainer1 = New Pc_Klit_V._3._0.GrayContainer()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.GrayButton2 = New Pc_Klit_V._3._0.GrayButton()
        Me.LinkLabel1 = New System.Windows.Forms.LinkLabel()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.TextBox3 = New System.Windows.Forms.TextBox()
        Me.GrayCheck2 = New Pc_Klit_V._3._0.GrayCheck()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.GrayCheck1 = New Pc_Klit_V._3._0.GrayCheck()
        Me.GrayButton1 = New Pc_Klit_V._3._0.GrayButton()
        Me.GrayForm1.SuspendLayout()
        Me.GrayContainer1.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Timer1
        '
        Me.Timer1.Interval = 11100
        '
        'NotifyIcon1
        '
        Me.NotifyIcon1.Icon = CType(resources.GetObject("NotifyIcon1.Icon"), System.Drawing.Icon)
        Me.NotifyIcon1.Text = "Pc LOckeD v3.2 TURKCODER"
        Me.NotifyIcon1.Visible = True
        '
        'GrayForm1
        '
        Me.GrayForm1.BackColor = System.Drawing.Color.FromArgb(CType(CType(108, Byte), Integer), CType(CType(108, Byte), Integer), CType(CType(108, Byte), Integer))
        Me.GrayForm1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center
        Me.GrayForm1.Controls.Add(Me.GrayButton3)
        Me.GrayForm1.Controls.Add(Me.TextBox1)
        Me.GrayForm1.Controls.Add(Me.Label5)
        Me.GrayForm1.Controls.Add(Me.GrayContainer1)
        Me.GrayForm1.Controls.Add(Me.GrayCheck1)
        Me.GrayForm1.Controls.Add(Me.GrayButton1)
        Me.GrayForm1.Cursor = System.Windows.Forms.Cursors.Default
        Me.GrayForm1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.GrayForm1.ForeColor = System.Drawing.Color.White
        Me.GrayForm1.Icon = Nothing
        Me.GrayForm1.ImeMode = System.Windows.Forms.ImeMode.Off
        Me.GrayForm1.Location = New System.Drawing.Point(0, 0)
        Me.GrayForm1.Name = "GrayForm1"
        Me.GrayForm1.Size = New System.Drawing.Size(530, 276)
        Me.GrayForm1.TabIndex = 0
        Me.GrayForm1.Text = "PASSWORD PANEL"
        '
        'GrayButton3
        '
        Me.GrayButton3.Location = New System.Drawing.Point(501, 1)
        Me.GrayButton3.Name = "GrayButton3"
        Me.GrayButton3.Size = New System.Drawing.Size(27, 17)
        Me.GrayButton3.TabIndex = 7
        Me.GrayButton3.Text = "X"
        '
        'TextBox1
        '
        Me.TextBox1.AcceptsReturn = True
        Me.TextBox1.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.TextBox1.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TextBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox1.ForeColor = System.Drawing.Color.Green
        Me.TextBox1.Location = New System.Drawing.Point(157, 232)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(148, 22)
        Me.TextBox1.TabIndex = 6
        Me.TextBox1.Text = "INPUT PASSWORD"
        Me.TextBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        Me.TextBox1.WordWrap = False
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(41, 243)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(107, 13)
        Me.Label5.TabIndex = 5
        Me.Label5.Text = "SHOW PASSWORD"
        '
        'GrayContainer1
        '
        Me.GrayContainer1.Controls.Add(Me.Label3)
        Me.GrayContainer1.Controls.Add(Me.GrayButton2)
        Me.GrayContainer1.Controls.Add(Me.LinkLabel1)
        Me.GrayContainer1.Controls.Add(Me.TextBox4)
        Me.GrayContainer1.Controls.Add(Me.TextBox3)
        Me.GrayContainer1.Controls.Add(Me.GrayCheck2)
        Me.GrayContainer1.Controls.Add(Me.Label4)
        Me.GrayContainer1.Controls.Add(Me.Label1)
        Me.GrayContainer1.Controls.Add(Me.Label2)
        Me.GrayContainer1.Controls.Add(Me.TextBox2)
        Me.GrayContainer1.Controls.Add(Me.PictureBox1)
        Me.GrayContainer1.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.GrayContainer1.Location = New System.Drawing.Point(12, 30)
        Me.GrayContainer1.Name = "GrayContainer1"
        Me.GrayContainer1.Size = New System.Drawing.Size(506, 182)
        Me.GrayContainer1.TabIndex = 4
        Me.GrayContainer1.Text = "GrayContainer1"
        '
        'Label3
        '
        Me.Label3.Anchor = System.Windows.Forms.AnchorStyles.Left
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.Label3.Location = New System.Drawing.Point(201, 158)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(0, 18)
        Me.Label3.TabIndex = 5
        '
        'GrayButton2
        '
        Me.GrayButton2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center
        Me.GrayButton2.Cursor = System.Windows.Forms.Cursors.Default
        Me.GrayButton2.Location = New System.Drawing.Point(198, 3)
        Me.GrayButton2.Name = "GrayButton2"
        Me.GrayButton2.Size = New System.Drawing.Size(141, 152)
        Me.GrayButton2.TabIndex = 9
        Me.GrayButton2.Text = "CREATE PASSWORD"
        '
        'LinkLabel1
        '
        Me.LinkLabel1.AutoSize = True
        Me.LinkLabel1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.LinkLabel1.LinkColor = System.Drawing.Color.Maroon
        Me.LinkLabel1.Location = New System.Drawing.Point(16, 161)
        Me.LinkLabel1.Name = "LinkLabel1"
        Me.LinkLabel1.Size = New System.Drawing.Size(144, 15)
        Me.LinkLabel1.TabIndex = 7
        Me.LinkLabel1.TabStop = True
        Me.LinkLabel1.Text = "FORGOT PASSWORD"
        '
        'TextBox4
        '
        Me.TextBox4.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TextBox4.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox4.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox4.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.TextBox4.Location = New System.Drawing.Point(345, 75)
        Me.TextBox4.Multiline = True
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(148, 26)
        Me.TextBox4.TabIndex = 6
        Me.TextBox4.WordWrap = False
        '
        'TextBox3
        '
        Me.TextBox3.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TextBox3.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox3.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox3.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.TextBox3.Location = New System.Drawing.Point(345, 120)
        Me.TextBox3.Multiline = True
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(148, 29)
        Me.TextBox3.TabIndex = 6
        Me.TextBox3.WordWrap = False
        '
        'GrayCheck2
        '
        Me.GrayCheck2.Checked = False
        Me.GrayCheck2.Location = New System.Drawing.Point(176, 161)
        Me.GrayCheck2.Name = "GrayCheck2"
        Me.GrayCheck2.Size = New System.Drawing.Size(19, 18)
        Me.GrayCheck2.TabIndex = 3
        Me.GrayCheck2.Text = "GrayCheck1"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(345, 56)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(77, 13)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "Program Name"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(345, 104)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(152, 13)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "CREATE LOGIN PASSWORD"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(345, 5)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(29, 13)
        Me.Label2.TabIndex = 5
        Me.Label2.Text = "Mail "
        '
        'TextBox2
        '
        Me.TextBox2.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TextBox2.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox2.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.TextBox2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.TextBox2.Location = New System.Drawing.Point(345, 26)
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(148, 27)
        Me.TextBox2.TabIndex = 6
        Me.TextBox2.WordWrap = False
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(-30, 3)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(257, 152)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'GrayCheck1
        '
        Me.GrayCheck1.Checked = False
        Me.GrayCheck1.Location = New System.Drawing.Point(16, 243)
        Me.GrayCheck1.Name = "GrayCheck1"
        Me.GrayCheck1.Size = New System.Drawing.Size(19, 18)
        Me.GrayCheck1.TabIndex = 3
        Me.GrayCheck1.Text = "GrayCheck1"
        '
        'GrayButton1
        '
        Me.GrayButton1.Font = New System.Drawing.Font("Microsoft Sans Serif", 18.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.GrayButton1.Location = New System.Drawing.Point(311, 232)
        Me.GrayButton1.Name = "GrayButton1"
        Me.GrayButton1.Size = New System.Drawing.Size(207, 32)
        Me.GrayButton1.TabIndex = 0
        Me.GrayButton1.Text = "LOGIN"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(530, 276)
        Me.Controls.Add(Me.GrayForm1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.KeyPreview = True
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.TransparencyKey = System.Drawing.Color.Fuchsia
        Me.GrayForm1.ResumeLayout(False)
        Me.GrayForm1.PerformLayout()
        Me.GrayContainer1.ResumeLayout(False)
        Me.GrayContainer1.PerformLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents GrayButton1 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents GrayCheck1 As Pc_Klit_V._3._0.GrayCheck
    Friend WithEvents GrayContainer1 As Pc_Klit_V._3._0.GrayContainer
    Friend WithEvents GrayButton2 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents LinkLabel1 As System.Windows.Forms.LinkLabel
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents GrayCheck2 As Pc_Klit_V._3._0.GrayCheck
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents GrayForm1 As Pc_Klit_V._3._0.GrayForm
    Friend WithEvents NotifyIcon1 As System.Windows.Forms.NotifyIcon
    Friend WithEvents GrayButton3 As Pc_Klit_V._3._0.GrayButton
End Class
