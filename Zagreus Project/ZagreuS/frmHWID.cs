using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Management;
using System.Runtime.CompilerServices;
using System.Text;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using Microsoft.Win32;
using ZagreuS.My;

namespace ZagreuS;

[DesignerGenerated]
public class frmHWID : Form
{
	private IContainer components;

	[CompilerGenerated]
	[DebuggerBrowsable(DebuggerBrowsableState.Never)]
	[AccessedThroughProperty("btnReg")]
	private Button _btnReg;

	private string hwidX;

	[field: AccessedThroughProperty("GroupBox7")]
	internal virtual GroupBox GroupBox7
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("GroupBox3")]
	internal virtual GroupBox GroupBox3
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("txtPass")]
	internal virtual TextBox txtPass
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("GroupBox2")]
	internal virtual GroupBox GroupBox2
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("txtHWID")]
	internal virtual TextBox txtHWID
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("GroupBox1")]
	internal virtual GroupBox GroupBox1
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	[field: AccessedThroughProperty("txtUser")]
	internal virtual TextBox txtUser
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	internal virtual Button btnReg
	{
		[CompilerGenerated]
		get
		{
			return _btnReg;
		}
		[MethodImpl(MethodImplOptions.Synchronized)]
		[CompilerGenerated]
		set
		{
			EventHandler value2 = btnReg_Click;
			Button button = _btnReg;
			if (button != null)
			{
				button.Click -= value2;
			}
			_btnReg = value;
			button = _btnReg;
			if (button != null)
			{
				button.Click += value2;
			}
		}
	}

	[field: AccessedThroughProperty("PictureBox2")]
	internal virtual PictureBox PictureBox2
	{
		get; [MethodImpl(MethodImplOptions.Synchronized)]
		set;
	}

	public frmHWID()
	{
		base.Load += frmHWID_Load;
		base.FormClosing += frmHWID_FormClosing;
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
		System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ZagreuS.frmHWID));
		this.GroupBox7 = new System.Windows.Forms.GroupBox();
		this.GroupBox3 = new System.Windows.Forms.GroupBox();
		this.txtPass = new System.Windows.Forms.TextBox();
		this.GroupBox2 = new System.Windows.Forms.GroupBox();
		this.txtHWID = new System.Windows.Forms.TextBox();
		this.GroupBox1 = new System.Windows.Forms.GroupBox();
		this.txtUser = new System.Windows.Forms.TextBox();
		this.btnReg = new System.Windows.Forms.Button();
		this.PictureBox2 = new System.Windows.Forms.PictureBox();
		this.GroupBox7.SuspendLayout();
		this.GroupBox3.SuspendLayout();
		this.GroupBox2.SuspendLayout();
		this.GroupBox1.SuspendLayout();
		((System.ComponentModel.ISupportInitialize)this.PictureBox2).BeginInit();
		base.SuspendLayout();
		this.GroupBox7.Controls.Add(this.GroupBox3);
		this.GroupBox7.Controls.Add(this.GroupBox2);
		this.GroupBox7.Controls.Add(this.GroupBox1);
		this.GroupBox7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 0);
		this.GroupBox7.ForeColor = System.Drawing.Color.Black;
		this.GroupBox7.Location = new System.Drawing.Point(12, 157);
		this.GroupBox7.Name = "GroupBox7";
		this.GroupBox7.Size = new System.Drawing.Size(300, 274);
		this.GroupBox7.TabIndex = 202;
		this.GroupBox7.TabStop = false;
		this.GroupBox3.Controls.Add(this.txtPass);
		this.GroupBox3.Location = new System.Drawing.Point(12, 138);
		this.GroupBox3.Name = "GroupBox3";
		this.GroupBox3.Size = new System.Drawing.Size(277, 130);
		this.GroupBox3.TabIndex = 200;
		this.GroupBox3.TabStop = false;
		this.GroupBox3.Text = "Password";
		this.txtPass.BackColor = System.Drawing.SystemColors.Control;
		this.txtPass.Location = new System.Drawing.Point(20, 33);
		this.txtPass.Multiline = true;
		this.txtPass.Name = "txtPass";
		this.txtPass.Size = new System.Drawing.Size(242, 74);
		this.txtPass.TabIndex = 192;
		this.GroupBox2.Controls.Add(this.txtHWID);
		this.GroupBox2.Location = new System.Drawing.Point(12, 19);
		this.GroupBox2.Name = "GroupBox2";
		this.GroupBox2.Size = new System.Drawing.Size(277, 48);
		this.GroupBox2.TabIndex = 200;
		this.GroupBox2.TabStop = false;
		this.GroupBox2.Text = " HWID";
		this.txtHWID.Location = new System.Drawing.Point(20, 19);
		this.txtHWID.Name = "txtHWID";
		this.txtHWID.ReadOnly = true;
		this.txtHWID.Size = new System.Drawing.Size(242, 20);
		this.txtHWID.TabIndex = 188;
		this.GroupBox1.Controls.Add(this.txtUser);
		this.GroupBox1.Location = new System.Drawing.Point(12, 84);
		this.GroupBox1.Name = "GroupBox1";
		this.GroupBox1.Size = new System.Drawing.Size(277, 48);
		this.GroupBox1.TabIndex = 191;
		this.GroupBox1.TabStop = false;
		this.GroupBox1.Text = "Username";
		this.txtUser.BackColor = System.Drawing.SystemColors.Control;
		this.txtUser.Location = new System.Drawing.Point(20, 19);
		this.txtUser.Name = "txtUser";
		this.txtUser.Size = new System.Drawing.Size(242, 20);
		this.txtUser.TabIndex = 190;
		this.btnReg.Location = new System.Drawing.Point(116, 438);
		this.btnReg.Name = "btnReg";
		this.btnReg.Size = new System.Drawing.Size(75, 28);
		this.btnReg.TabIndex = 201;
		this.btnReg.Text = "Register";
		this.btnReg.UseVisualStyleBackColor = true;
		this.PictureBox2.BackColor = System.Drawing.Color.Black;
		this.PictureBox2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
		this.PictureBox2.Image = (System.Drawing.Image)resources.GetObject("PictureBox2.Image");
		this.PictureBox2.Location = new System.Drawing.Point(-52, 1);
		this.PictureBox2.Name = "PictureBox2";
		this.PictureBox2.Size = new System.Drawing.Size(431, 150);
		this.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
		this.PictureBox2.TabIndex = 203;
		this.PictureBox2.TabStop = false;
		base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		base.ClientSize = new System.Drawing.Size(325, 473);
		base.Controls.Add(this.PictureBox2);
		base.Controls.Add(this.GroupBox7);
		base.Controls.Add(this.btnReg);
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
		base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
		base.MaximizeBox = false;
		base.Name = "frmHWID";
		base.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
		this.Text = "Login ";
		this.GroupBox7.ResumeLayout(false);
		this.GroupBox3.ResumeLayout(false);
		this.GroupBox3.PerformLayout();
		this.GroupBox2.ResumeLayout(false);
		this.GroupBox2.PerformLayout();
		this.GroupBox1.ResumeLayout(false);
		this.GroupBox1.PerformLayout();
		((System.ComponentModel.ISupportInitialize)this.PictureBox2).EndInit();
		base.ResumeLayout(false);
	}

	public string dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(string TheText)
	{
		string text = "";
		int num = Strings.Len(TheText);
		checked
		{
			for (int i = 1; i <= num; i++)
			{
				string text2 = Conversions.ToString(Strings.Chr(Strings.Asc(Strings.Mid(Strings.StrReverse(TheText), i, 1)) + 1));
				text += text2;
			}
			return Strings.Trim(text);
		}
	}

	private object cqZcjtUFrXXKYNvNoTYltwK(string ChYgMjXoEEShdoRoK, string EMTwsGVgKuuHHVWdb)
	{
		string text = "";
		int num = Strings.Asc(EMTwsGVgKuuHHVWdb);
		checked
		{
			short num2 = (short)Strings.Len(ChYgMjXoEEShdoRoK);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(ChYgMjXoEEShdoRoK, num3, 1))));
			}
			return text;
		}
	}

	public bool IsAdmin()
	{
		if (MyProject.User.IsAuthenticated && Conversions.ToBoolean(NewLateBinding.LateGet(MyProject.User, null, "IsInRole", new object[1] { gfucUokgDmMRMocusOrgsPZ("(\r\u0004\0\a\0\u001a\u001d\u001b\b\u001d\u0006\u001b\u001a", "iKpsDLiYIfnonVhjMHSMrFo") }, null, null, null)))
		{
			return true;
		}
		return false;
	}

	private object gfucUokgDmMRMocusOrgsPZ(string PbdNtiitFowAgYhqQ, string SGYdcFglKhaYKFlfg)
	{
		string text = "";
		int num = Strings.Asc(SGYdcFglKhaYKFlfg);
		checked
		{
			short num2 = (short)Strings.Len(PbdNtiitFowAgYhqQ);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(PbdNtiitFowAgYhqQ, num3, 1))));
			}
			return text;
		}
	}

	public string SimpleDEncrypt(string TheText)
	{
		string text = "";
		int num = Strings.Len(TheText);
		checked
		{
			for (int i = 1; i <= num; i++)
			{
				string text2 = Conversions.ToString(Strings.Chr(Strings.Asc(Strings.Mid(Strings.StrReverse(TheText), i, 1)) - 1));
				text += text2;
			}
			return Strings.Trim(text);
		}
	}

	private object mwOskFBDRtbvawPTQDkHpVG(string aUrHotljdkrWfsOvN, string cwmXXQjbidWtJZTkd)
	{
		string text = "";
		int num = Strings.Asc(cwmXXQjbidWtJZTkd);
		checked
		{
			short num2 = (short)Strings.Len(aUrHotljdkrWfsOvN);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(aUrHotljdkrWfsOvN, num3, 1))));
			}
			return text;
		}
	}

	public string HexToString(string hex)
	{
		StringBuilder stringBuilder = new StringBuilder(hex.Length / 2);
		checked
		{
			int num = hex.Length - 2;
			for (int i = 0; i <= num; i += 2)
			{
				stringBuilder.Append(Strings.Chr(Convert.ToByte(hex.Substring(i, 2), 16)));
			}
			return stringBuilder.ToString();
		}
	}

	private object IHZdNDsOBQTjaJgKpwtMWCD(string VroCnlEWTZWvPeRTK, string YWjSWHCOZSAWrLVIa)
	{
		string text = "";
		int num = Strings.Asc(YWjSWHCOZSAWrLVIa);
		checked
		{
			short num2 = (short)Strings.Len(VroCnlEWTZWvPeRTK);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(VroCnlEWTZWvPeRTK, num3, 1))));
			}
			return text;
		}
	}

	public string StringToHex(string text)
	{
		checked
		{
			int num = text.Length - 1;
			string text2 = default(string);
			for (int i = 0; i <= num; i++)
			{
				text2 = Conversions.ToString(Operators.ConcatenateObject(text2, NewLateBinding.LateGet(NewLateBinding.LateGet(Strings.Asc(text.Substring(i, 1)), null, "ToString", new object[1] { HwYRJPDeUsIPwotbAMNuCpb("2", "JbThpjBWaljnaVBQQFlaBfq") }, null, null, null), null, "ToUpper", new object[0], null, null, null)));
			}
			return text2;
		}
	}

	private object HwYRJPDeUsIPwotbAMNuCpb(string MFOAYGwPfeNOECGFh, string OhJQHZtHlXpmggKrA)
	{
		string text = "";
		int num = Strings.Asc(OhJQHZtHlXpmggKrA);
		checked
		{
			short num2 = (short)Strings.Len(MFOAYGwPfeNOECGFh);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(MFOAYGwPfeNOECGFh, num3, 1))));
			}
			return text;
		}
	}

	private string getUniqueID(string drive)
	{
		if (Operators.CompareString(drive, string.Empty, TextCompare: false) == 0)
		{
			DriveInfo[] drives = DriveInfo.GetDrives();
			foreach (DriveInfo driveInfo in drives)
			{
				if (driveInfo.IsReady)
				{
					drive = driveInfo.RootDirectory.ToString();
					break;
				}
			}
		}
		if (drive.EndsWith(Conversions.ToString(DUtKARBaGcYrjGvQbkDBLsZ("}\u001b", "GwoagkwTMVCROkCFsdceKio"))))
		{
			drive = drive.Substring(0, checked(drive.Length - 2));
		}
		string volumeSerial = getVolumeSerial(drive);
		string cPUID = getCPUID();
		string serialNumber = getSerialNumber();
		GetMACAddress();
		return cPUID.Substring(0, 2) + volumeSerial.Substring(0, 2) + cPUID.Substring(9, 4) + serialNumber.Substring(0, 4) + cPUID.Substring(2, 4) + volumeSerial.Substring(2, 4) + cPUID.Substring(12) + volumeSerial.Substring(3, 4) + serialNumber.Substring(10, 4) + GetMACAddress().Substring(2, 4);
	}

	private object DUtKARBaGcYrjGvQbkDBLsZ(string IbjqPHtLROdppRHsL, string LFdJvarDXHIQTvMhb)
	{
		string text = "";
		int num = Strings.Asc(LFdJvarDXHIQTvMhb);
		checked
		{
			short num2 = (short)Strings.Len(IbjqPHtLROdppRHsL);
			for (short num3 = 1; num3 <= num2; num3 = (short)unchecked(num3 + 1))
			{
				text += Conversions.ToString(Strings.Chr(num ^ Strings.Asc(Strings.Mid(IbjqPHtLROdppRHsL, num3, 1))));
			}
			return text;
		}
	}

	internal string GetMACAddress()
	{
		ManagementClass managementClass = new ManagementClass("Win32_NetworkAdapterConfiguration");
		ManagementObjectCollection instances = managementClass.GetInstances();
		string text = string.Empty;
		foreach (ManagementObject item in instances)
		{
			if (text.Equals(string.Empty))
			{
				if (Conversions.ToBoolean(item["IPEnabled"]))
				{
					text = item["MacAddress"].ToString();
				}
				item.Dispose();
			}
			text = text.Replace(":", string.Empty);
		}
		return text;
	}

	public static string getSerialNumber()
	{
		string result = string.Empty;
		ManagementObjectSearcher managementObjectSearcher = new ManagementObjectSearcher("Select * from Win32_OperatingSystem");
		ManagementObjectCollection managementObjectCollection = managementObjectSearcher.Get();
		foreach (ManagementObject item in managementObjectCollection)
		{
			result = item["SerialNumber"].ToString();
		}
		return result;
	}

	private string getVolumeSerial(string drive)
	{
		ManagementObject managementObject = new ManagementObject("win32_logicaldisk.deviceid=\"" + drive + ":\"");
		managementObject.Get();
		string result = managementObject["VolumeSerialNumber"].ToString();
		managementObject.Dispose();
		return result;
	}

	private string getCPUID()
	{
		string text = "";
		ManagementClass managementClass = new ManagementClass("win32_processor");
		ManagementObjectCollection instances = managementClass.GetInstances();
		foreach (ManagementObject item in instances)
		{
			if (Operators.CompareString(text, "", TextCompare: false) == 0)
			{
				text = item.Properties["processorID"].Value.ToString();
				break;
			}
		}
		return text;
	}

	[MethodImpl(MethodImplOptions.NoOptimization)]
	private void btnReg_Click(object sender, EventArgs e)
	{
		try
		{
			string hex = txtPass.Text.ToString();
			hex = HexToString(hex);
			byte[] bytes = Convert.FromBase64String(hex);
			string @string = Encoding.UTF8.GetString(bytes);
			@string = Strings.StrReverse(@string);
			byte[] bytes2 = Convert.FromBase64String(@string);
			string string2 = Encoding.UTF8.GetString(bytes2);
			string2 = SimpleDEncrypt(string2);
			string2 = Strings.StrReverse(string2);
			string right = txtHWID.Text.ToString() + txtUser.Text.ToString();
			string text = txtHWID.Text.ToString();
			string text2 = "-Yes.It-Is.Registered";
			string expression = text + text2;
			if (Operators.CompareString(string2, right, TextCompare: false) == 0)
			{
				Interaction.MsgBox("Registration Successfully", MsgBoxStyle.Information, "Red3v1l Builder");
				if (MyProject.Forms.Form1.IsAdmin())
				{
					RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Explorer", writable: true);
					registryKey.SetValue(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse("Is Registered")), Strings.StrReverse(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse(expression))), RegistryValueKind.String);
					registryKey.Close();
					registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\\\Microsoft\\\\Windows\\\\CurrentVersion", writable: true);
					registryKey.SetValue(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse("RegisteredName")), Strings.StrReverse(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse(txtUser.Text.ToString()))), RegistryValueKind.String);
					registryKey.Close();
				}
				else if (!MyProject.Forms.Form1.IsAdmin())
				{
					_ = hwidX.ToString() + "-Yes.It-Is.Registered";
					if (MyProject.Computer.FileSystem.FileExists(Application.StartupPath.ToString() + "\\WindowsSettings.ini"))
					{
						FileSystem.Kill(Application.StartupPath.ToString() + "\\WindowsSettings.ini");
						MyProject.Forms.Form1.Show();
						Hide();
					}
					StreamWriter streamWriter = new StreamWriter(Application.StartupPath.ToString() + "\\WindowsSettings.ini");
					string text3 = dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse("13377"));
					string text4 = dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse(hwidX));
					string s = dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("Port") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("=") + text3 + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("<DI>") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("HardwareID") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("=") + text4 + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("<DI>") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("IsReg") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("=") + Strings.StrReverse(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse(expression))) + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("<DI>") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("RegName") + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("=") + Strings.StrReverse(dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf(Strings.StrReverse(txtUser.Text.ToString()))) + dppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdfdppRHssLddfddHsLPHtLROdppRdf("<DI>");
					byte[] bytes3 = Encoding.UTF8.GetBytes(s);
					string text5 = Convert.ToBase64String(bytes3);
					text5 = StringToHex(text5);
					streamWriter.WriteLine(text5);
					streamWriter.Close();
				}
			}
			else
			{
				Interaction.MsgBox("Wrong password", MsgBoxStyle.Exclamation, "Red3v1l Builder");
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			Interaction.MsgBox("Wrong password", MsgBoxStyle.Exclamation, "Red3v1l Builder");
			ProjectData.ClearProjectError();
		}
	}

	private void frmHWID_Load(object sender, EventArgs e)
	{
		hwidX = getUniqueID("C");
		txtHWID.Text = hwidX;
	}

	[MethodImpl(MethodImplOptions.NoOptimization)]
	private void frmHWID_FormClosing(object sender, FormClosingEventArgs e)
	{
		ProjectData.EndApp();
	}
}
