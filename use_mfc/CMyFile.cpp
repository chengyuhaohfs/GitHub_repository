#include "CMyFile.h"



CMyFile::CMyFile()
{
}


CMyFile::~CMyFile()
{
}

BOOL CMyFile::CheckAndCreateDir(CString csNewDir)
{
	CString csMsg = L"";
	// 先尝试直接生成目录
	if (!CreateDirectory(csNewDir + L"\\", NULL))
	{
		// 当创建失败时要尝试删除文件夹
		if (!RemoveDirectory(csNewDir))
		{
			// 当删除文件夹失败时，要尝试清空文件夹后再删除
			CString csFindFile = L"";
			HANDLE hfirstFile = NULL;
			WIN32_FIND_DATAW wFildAtt;

			hfirstFile = FindFirstFile(csNewDir + L"\\*", &wFildAtt);
			if (!hfirstFile)
			{
				csMsg.Format(L"获取首个文件失败！", csMsg);
				AfxMessageBox(csMsg);
				return FALSE;
			}
			else if (FindNextFile(hfirstFile, &wFildAtt))
			{
				while (FindNextFile(hfirstFile, &wFildAtt))
				{
					csMsg.Format(L"%s\\%s", csNewDir, wFildAtt.cFileName);
					if (!DeleteFile(csMsg))
					{
						csMsg.Format(L"删除文件 %s 失败！", csMsg);
						AfxMessageBox(csMsg);
						return FALSE;
					}
				}
			}
			csMsg.Format(L"生成路径 %s 成功！", csNewDir);
			AfxMessageBox(csMsg);
			return TRUE;
		}
		// 如果依然失败，要考虑目录是否可用
		if (!CreateDirectory(csNewDir + L"\\", NULL))
		{
			csMsg.Format(L"生成路径 %s 失败！", csNewDir);
			AfxMessageBox(csMsg);
			return FALSE;
		}
		else
		{
			csMsg.Format(L"生成路径 %s 成功！", csNewDir);
			AfxMessageBox(csMsg);
			return TRUE;
		}
	}
	else
	{
		csMsg.Format(L"生成路径 %s 成功！", csNewDir);
		AfxMessageBox(csMsg);
		return TRUE;
	}

	return TRUE;
}