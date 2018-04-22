#pragma once
#include "afxwin.h"

class CMyFile
{
public:
	CMyFile();
	~CMyFile();
	BOOL CheckAndCreateDir(CString csNewDir);
};

