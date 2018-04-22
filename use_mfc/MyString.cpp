#include "MyString.h"


CMyString::CMyString(void)
{
}


CMyString::~CMyString(void)
{
}

BOOL CMyString::SplitStr(CString cstr, CString mark, CStringArray& csArray)
{
	// �ָ�������ǵ����ַ�
	// ����Ѱ�ҷָ�㣬��ȡ�÷ָ��ǰ�����ݣ���Ҫ�ָ���ַ������¸�ֵ
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
		t_cstr = t_cstr.Mid(n_splitPot + mark.GetLength());
	}
	return TRUE;
}

BOOL CMyString::FindStr(CString cstr, CString cs_start, CString cs_end, CString& cs_strget)
{
	CString csMsg = L"";
	CString tcs_str = cstr;
	// �����ҵ���ʼ�㣬����Ҫ����w_start�ĳ���
	int n_startLen = cs_start.GetLength();
	int n_startPos = tcs_str.Find(cs_start) + n_startLen;
	tcs_str = tcs_str.Mid(n_startPos);
	// Ȼ���ҵ������㣬ͬ��Ҫ��λ���õ��ǰһλ��
	int n_endPos = tcs_str.Find(cs_end);
	// �������λ��ǰһ�����Ҫ�ҵ��ַ����Ľ�β
	int n_strLen = n_endPos;
	// ����ȡ�õ��ַ�����������ʼ���ȡĿ���ַ���
	cs_strget = tcs_str.Mid(0, n_strLen);

	cs_strget.TrimLeft();
	cs_strget.TrimRight();
	csMsg.Format(L"%s length %d", cs_strget, cs_strget.GetLength());
	AfxMessageBox(csMsg);

	return TRUE;
}