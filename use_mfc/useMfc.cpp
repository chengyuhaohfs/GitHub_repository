#include "afxwin.h"
#include "iostream"
#include "MyString.h"

using namespace std;

int main(int argc, char** argv)
{
	CString csMsg = L"Hello world from MFC";
	AfxMessageBox(csMsg);

	// I will split the sentence
	CMyString imystr;
	CStringArray csArray;
	CString cstr = L"hu, fu, sheng";

	csArray.RemoveAll();
	imystr.SplitStr(cstr, L",", csArray);

	CString csFind = L"";
	imystr.FindStr(cstr, L"hu,", L",", csFind);

	cout << "hello world" << endl;

	return 1;
}