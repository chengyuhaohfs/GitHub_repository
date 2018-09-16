
// MFC_diagDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_diag.h"
#include "MFC_diagDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CMFC_diagDlg dialog



CMFC_diagDlg::CMFC_diagDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_diagDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_diagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_diagDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CMFC_diagDlg::OnBnClickedButtonTest)
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTON_HIDE_WINDOWS, &CMFC_diagDlg::OnBnClickedButtonHideWindows)
	ON_COMMAND(ID_ACCELERATOR32771, &CMFC_diagDlg::OnAccelerator32771)
END_MESSAGE_MAP()


// CMFC_diagDlg message handlers

BOOL CMFC_diagDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_haccel = ::LoadAccelerators(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_SELF));
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_diagDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_diagDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_diagDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_diagDlg::OnBnClickedButtonTest()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("This is for test!");
}


void CMFC_diagDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CString strTemp;
	char ch = nChar;
	strTemp.Format("%c", ch);
	SetDlgItemText(IDC_EDIT_CHARACTER, strTemp);
	strTemp.Format("%0x + %d", nChar, nChar);
	SetDlgItemText(IDC_EDIT_ASCII, strTemp);

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMFC_diagDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN)
	{
		pMsg->hwnd = m_hWnd;
	}

	if (pMsg->message >= WM_KEYFIRST && pMsg->message <= WM_KEYLAST)
	{
		HACCEL haccel = m_haccel;
		if (haccel && TranslateAccelerator(m_hWnd, haccel, pMsg))
		{
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFC_diagDlg::OnBnClickedButtonHideWindows()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_LWIN, 0, 0, 0);
	keybd_event(77, 0, 0, 0);
	keybd_event(VK_LWIN, 0, 0x02, 0);
	keybd_event(77, 0, 0x02, 0);
	ShowWindow(SW_MINIMIZE);
}


void CMFC_diagDlg::OnAccelerator32771()
{
	// TODO: Add your command handler code here
	AfxMessageBox("This a hot-key test!");
}
