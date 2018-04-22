#include "MyString.h"


CMyString::CMyString(void)
{
}


CMyString::~CMyString(void)
{
}

BOOL CMyString::SplitStr(CString cstr, CString mark, CStringArray& csArray)
{
	// 分割符仅能是单个字符
	// 依次寻找分割点，并取得分割点前的内容，将要分割的字符串重新赋值
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
		t_cstr = t_cstr.Mid(n_splitPot + mark.GetLength());
	}
	return TRUE;
}

BOOL CMyString::FindStr(CString cstr, CString cs_start, CString cs_end, CString& cs_strget)
{
	CString csMsg = L"";
	CString tcs_str = cstr;
	// 首先找到起始点，这里要考虑w_start的长度
	int n_startLen = cs_start.GetLength();
	int n_startPos = tcs_str.Find(cs_start) + n_startLen;
	tcs_str = tcs_str.Mid(n_startPos);
	// 然后找到结束点，同样要定位到该点的前一位置
	int n_endPos = tcs_str.Find(cs_end);
	// 结束点的位置前一个点就要找的字符串的结尾
	int n_strLen = n_endPos;
	// 根据取得的字符串长度与起始点获取目标字符串
	cs_strget = tcs_str.Mid(0, n_strLen);

	cs_strget.TrimLeft();
	cs_strget.TrimRight();
	csMsg.Format(L"%s length %d", cs_strget, cs_strget.GetLength());
	AfxMessageBox(csMsg);

	return TRUE;
}