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
	// �ȳ���ֱ������Ŀ¼
	if (!CreateDirectory(csNewDir + L"\\", NULL))
	{
		// ������ʧ��ʱҪ����ɾ���ļ���
		if (!RemoveDirectory(csNewDir))
		{
			// ��ɾ���ļ���ʧ��ʱ��Ҫ��������ļ��к���ɾ��
			CString csFindFile = L"";
			HANDLE hfirstFile = NULL;
			WIN32_FIND_DATAW wFildAtt;

			hfirstFile = FindFirstFile(csNewDir + L"\\*", &wFildAtt);
			if (!hfirstFile)
			{
				csMsg.Format(L"��ȡ�׸��ļ�ʧ�ܣ�", csMsg);
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
						csMsg.Format(L"ɾ���ļ� %s ʧ�ܣ�", csMsg);
						AfxMessageBox(csMsg);
						return FALSE;
					}
				}
			}
			csMsg.Format(L"����·�� %s �ɹ���", csNewDir);
			AfxMessageBox(csMsg);
			return TRUE;
		}
		// �����Ȼʧ�ܣ�Ҫ����Ŀ¼�Ƿ����
		if (!CreateDirectory(csNewDir + L"\\", NULL))
		{
			csMsg.Format(L"����·�� %s ʧ�ܣ�", csNewDir);
			AfxMessageBox(csMsg);
			return FALSE;
		}
		else
		{
			csMsg.Format(L"����·�� %s �ɹ���", csNewDir);
			AfxMessageBox(csMsg);
			return TRUE;
		}
	}
	else
	{
		csMsg.Format(L"����·�� %s �ɹ���", csNewDir);
		AfxMessageBox(csMsg);
		return TRUE;
	}

	return TRUE;
}