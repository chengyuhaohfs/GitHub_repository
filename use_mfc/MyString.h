#pragma once

#include "afxwin.h"

class CMyString
{
public:
	CMyString(void);
	~CMyString(void);
	BOOL SplitStr(CString cstr, CString mark, CStringArray& csArray);
	BOOL FindStr(CString cstr, CString cs_start, CString cs_end, CString& cs_strget);
};

#ifndef uint
#define uint unsigned int
#endif