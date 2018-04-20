#pragma once

#include "afxwin.h"

class CMyString
{
public:
	CMyString(void);
	~CMyString(void);
	BOOL SplitStr(CString cstr, WCHAR* mark, CStringArray& csArray);
};

#ifndef uint
#define uint unsigned int
#endif