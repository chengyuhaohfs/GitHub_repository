#include "stfafx.h"
#include "iostream"

using namespace std;

int main(int argc, char** argv)
{
	// 打印“hello world”
	CString csMsg = L"Hello world from MFC";
/*	AfxMessageBox(csMsg);*/

	// 获取当前路径
	LPWSTR wCurrentDir = csMsg.GetBuffer(MAX_PATH);
	csMsg.ReleaseBuffer();

	GetCurrentDirectory(MAX_PATH, wCurrentDir);
/*	AfxMessageBox(wCurrentDir);*/

	// 生成指定路径
	CMyFile imyfile;
	CString csNewDir = L"";
	csNewDir.Format(L"%s\\testDir", wCurrentDir);

	if (!imyfile.CheckAndCreateDir(csNewDir))
	{
		return 0;
	}
	
/*
	if (!RemoveDirectory(csNewDir))
	{
		csMsg.Format(L"删除路径 %s 失败！", csNewDir);
		AfxMessageBox(csMsg);
		return 0;
	}*/

	// I will split the sentence
/*
	CMyString imystr;
	CStringArray csArray;
	CString cstr = L"hu, fu, sheng";

	csArray.RemoveAll();
	imystr.SplitStr(cstr, L",", csArray);

	CString csFind = L"";
	imystr.FindStr(cstr, L"hu,", L",", csFind);*/

/*	cout << "hello world" << endl;*/

	return 1;
}