#include "valarray"
#include "iostream"
#include "string"
#include "memory"
#include "stdafx.h"
#include "vector"
#include "afxwin.h"
#include "comutil.h"

typedef std::valarray<double> ArrayDb;

class People : private std::string {
private:
	std::string name;
	int age;
public:
	const std::string &getName() const {
		return name;
	}
	People() {
		age = 0;
		name = "Nobody";
		std::cout << "Here a new people " << name << " is created.\n";
	}
	explicit People(std::string name_) : name(name_) {
			age = 0;
			std::cout << "Here a new people " << name << " is created.\n";
		}
	~People(){
		std::cout << "Here a people " << name << " is deleted.\n";
	}
};

class Student : private People {
private:
	ArrayDb scores;
public:
	Student() {
		scores = ArrayDb(0);
		std::cout << "Here a new student " << getName() << " is created.\n";
	}

	explicit Student(std::string name) : People(name) {
			scores = ArrayDb(6.0, 5);
			std::cout << "Here a new student " << getName() << " is created.\n";
		}
	double sum() const {
		return scores.sum();
	}

	~Student() {
		std::cout << "Here a student " << getName() << " is deleted.\n";
	}
};

int main(int argc, char** argv) {
	using namespace std;
	
	CString csMsg = L"";
	size_t const WORD_SIZE = 2048;

	HANDLE hRead, hWrite;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	if (!CreatePipe(&hRead, &hWrite, &sa, WORD_SIZE - 1))
	{
		csMsg.Format(L"创建输出管道失败！");
		AfxMessageBox(csMsg);

		CloseHandle(hRead);
		CloseHandle(hWrite);
		return 0;
	}
	
	STARTUPINFO st;
	GetStartupInfo(&st);
	st.cb = sizeof(st);
	st.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	st.wShowWindow = SW_HIDE;

	st.hStdError = hWrite;
	st.hStdOutput = hWrite;
/*	st.hStdInput = GetStdHandle(STD_INPUT_HANDLE);*/

	PROCESS_INFORMATION pi;

	WCHAR wcApp[] = L"";
	WCHAR wcCmd[] = L"tasklist";

/*	WCHAR* lpApp = wcApp;*/
	WCHAR* lpApp = NULL;
	WCHAR* lpCmd = wcCmd;

	if (!CreateProcess(lpApp, lpCmd, NULL, NULL, TRUE, 0, NULL, NULL, &st, &pi))
	{
		csMsg.Format(L"创建进程失败！");
		AfxMessageBox(csMsg);

		CloseHandle(hRead);
		CloseHandle(hWrite);
		return 0;
	}

	WaitForSingleObject(pi.hProcess, 500);

	char chBuffer[WORD_SIZE] = "";
	memset(chBuffer, 0, WORD_SIZE);

	DWORD exitCode = 0;
	GetExitCodeProcess(pi.hProcess, &exitCode);

	DWORD nByteRead = 0, nByteAvail = 0, nByteLeft = 0;

	while (true)
	{
		if (!PeekNamedPipe(hRead, chBuffer, WORD_SIZE - 1, &nByteRead, &nByteAvail, &nByteLeft))
		{
			csMsg.Format(L"预读管道失败！");
			AfxMessageBox(csMsg);

			CloseHandle(hRead);
			CloseHandle(hWrite);
			return 0;
		}

		GetExitCodeProcess(pi.hProcess, &exitCode);

		if (0 == nByteRead)
		{
			if (STILL_ACTIVE != exitCode)
			{
				break;
			}

			continue;
		}

		memset(chBuffer, 0, WORD_SIZE);
		if (!ReadFile(hRead, chBuffer, WORD_SIZE - 1, &nByteRead, NULL))
		{
			csMsg.Format(L"读管道失败！");
			AfxMessageBox(csMsg);

			CloseHandle(hRead);
			CloseHandle(hWrite);
			return 0;
		}

		cout << chBuffer;
		memset(chBuffer, 0, WORD_SIZE);
	}

	

	CloseHandle(hRead);
	CloseHandle(hWrite);
	return 0;
}

