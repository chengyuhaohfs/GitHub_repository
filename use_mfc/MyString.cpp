#include "MyString.h"


CMyString::CMyString(void)
{
}


CMyString::~CMyString(void)
{
}

BOOL CMyString::SplitStr(CString cstr, WCHAR* mark, CStringArray& csArray)
{
	//����Ѱ�ҷָ�㣬��ȡ�÷ָ��ǰ�����ݣ���Ҫ�ָ���ַ������¸�ֵ
	uint n_splitPot = 0;
	CString t_cstr = cstr;
	CString t_element = L"";

	//����Ѱ�ҷָ��
	while ((n_splitPot = t_cstr.Find(mark)) != -1)
	{
		// ȡ�÷ָ��ǰ������
		t_element = t_cstr.Mid(0, n_splitPot);
		t_element.TrimLeft();
		t_element.TrimRight();
		AfxMessageBox(t_element);
		csArray.Add(t_element);
		// ��Ҫ�ָ���ַ������¸�ֵ
		t_cstr = t_cstr.Mid(n_splitPot + 1);
	}
	return TRUE;
}