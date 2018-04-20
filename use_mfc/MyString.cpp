#include "MyString.h"


CMyString::CMyString(void)
{
}


CMyString::~CMyString(void)
{
}

BOOL CMyString::SplitStr(CString cstr, WCHAR* mark, CStringArray& csArray)
{
	//依次寻找分割点，并取得分割点前的内容，将要分割的字符串重新赋值
	uint n_splitPot = 0;
	CString t_cstr = cstr;
	CString t_element = L"";

	//依次寻找分割点
	while ((n_splitPot = t_cstr.Find(mark)) != -1)
	{
		// 取得分割点前的内容
		t_element = t_cstr.Mid(0, n_splitPot);
		t_element.TrimLeft();
		t_element.TrimRight();
		AfxMessageBox(t_element);
		csArray.Add(t_element);
		// 将要分割的字符串重新赋值
		t_cstr = t_cstr.Mid(n_splitPot + 1);
	}
	return TRUE;
}