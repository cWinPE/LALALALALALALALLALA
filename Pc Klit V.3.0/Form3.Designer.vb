﻿<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form3
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form3))
        Me.GrayForm1 = New Pc_Klit_V._3._0.GrayForm()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.GrayButton2 = New Pc_Klit_V._3._0.GrayButton()
        Me.GrayButton1 = New Pc_Klit_V._3._0.GrayButton()
        Me.ListBox2 = New System.Windows.Forms.ListBox()
        Me.ListBox1 = New System.Windows.Forms.ListBox()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GrayForm1.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'GrayForm1
        '
        Me.GrayForm1.BackColor = System.Drawing.Color.FromArgb(CType(CType(108, Byte), Integer), CType(CType(108, Byte), Integer), CType(CType(108, Byte), Integer))
        Me.GrayForm1.Controls.Add(Me.PictureBox1)
        Me.GrayForm1.Controls.Add(Me.Label1)
        Me.GrayForm1.Controls.Add(Me.GrayButton2)
        Me.GrayForm1.Controls.Add(Me.GrayButton1)
        Me.GrayForm1.Controls.Add(Me.ListBox2)
        Me.GrayForm1.Controls.Add(Me.ListBox1)
        Me.GrayForm1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.GrayForm1.ForeColor = System.Drawing.Color.White
        Me.GrayForm1.Icon = Nothing
        Me.GrayForm1.Location = New System.Drawing.Point(0, 0)
        Me.GrayForm1.Name = "GrayForm1"
        Me.GrayForm1.Size = New System.Drawing.Size(1140, 582)
        Me.GrayForm1.TabIndex = 3
        Me.GrayForm1.Text = "PC LOCKED"
        '
        'PictureBox1
        '
        Me.PictureBox1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(12, 45)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(1116, 144)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 4
        Me.PictureBox1.TabStop = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("MS Reference Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.Label1.Location = New System.Drawing.Point(471, 22)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(193, 20)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "LIST DELETED FILES"
        '
        'GrayButton2
        '
        Me.GrayButton2.Enabled = False
        Me.GrayButton2.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(162, Byte))
        Me.GrayButton2.Location = New System.Drawing.Point(770, 530)
        Me.GrayButton2.Name = "GrayButton2"
        Me.GrayButton2.Size = New System.Drawing.Size(171, 45)
        Me.GrayButton2.TabIndex = 2
        Me.GrayButton2.Text = "RECOVER DELETED FILES"
        '
        'GrayButton1
        '
        Me.GrayButton1.Location = New System.Drawing.Point(167, 530)
        Me.GrayButton1.Name = "GrayButton1"
        Me.GrayButton1.Size = New System.Drawing.Size(171, 40)
        Me.GrayButton1.TabIndex = 2
        Me.GrayButton1.Text = "SHOW DELETED FILES"
        '
        'ListBox2
        '
        Me.ListBox2.BackColor = System.Drawing.SystemColors.Desktop
        Me.ListBox2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.ListBox2.FormattingEnabled = True
        Me.ListBox2.Location = New System.Drawing.Point(586, 195)
        Me.ListBox2.Name = "ListBox2"
        Me.ListBox2.Size = New System.Drawing.Size(531, 329)
        Me.ListBox2.TabIndex = 1
        '
        'ListBox1
        '
        Me.ListBox1.BackColor = System.Drawing.SystemColors.Desktop
        Me.ListBox1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.ListBox1.FormattingEnabled = True
        Me.ListBox1.Location = New System.Drawing.Point(19, 195)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(542, 329)
        Me.ListBox1.TabIndex = 1
        '
        'Timer1
        '
        '
        'Form3
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1140, 582)
        Me.Controls.Add(Me.GrayForm1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "Form3"
        Me.Text = "Form3"
        Me.TransparencyKey = System.Drawing.Color.Fuchsia
        Me.GrayForm1.ResumeLayout(False)
        Me.GrayForm1.PerformLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents GrayButton2 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents GrayForm1 As Pc_Klit_V._3._0.GrayForm
    Friend WithEvents GrayButton1 As Pc_Klit_V._3._0.GrayButton
    Friend WithEvents ListBox2 As System.Windows.Forms.ListBox
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
End Class
