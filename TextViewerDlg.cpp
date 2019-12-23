
// TextViewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextViewer.h"
#include "TextViewerDlg.h"
#include "afxdialogex.h"
#include "FileManager.h"

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
END_MESSAGE_MAP()


// CTextViewerDlg dialog



CTextViewerDlg::CTextViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextViewerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTextViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editctrl_1);
	DDX_Control(pDX, IDC_EDIT2, m_editctrl_2);
	DDX_Control(pDX, IDC_EDIT3, m_editctrl_3);
	DDX_Control(pDX, IDC_EDIT4, m_editctrl_4);
	
}

BEGIN_MESSAGE_MAP(CTextViewerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ShowText_1, &CTextViewerDlg::OnBnClickedShowtext1)
	ON_BN_CLICKED(IDC_ShowText_2, &CTextViewerDlg::OnBnClickedShowtext2)
	ON_BN_CLICKED(IDC_ShowText_3, &CTextViewerDlg::OnBnClickedShowtext3)
	ON_BN_CLICKED(IDC_ShowText_4, &CTextViewerDlg::OnBnClickedShowtext4)
END_MESSAGE_MAP()


// CTextViewerDlg message handlers

BOOL CTextViewerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	//Initialize pointer to zero so that it can be initialized in first call to getInstance
	CFileManager *op; 
	op->getInstance();
	op->ReadData();  

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTextViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTextViewerDlg::OnPaint()
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
HCURSOR CTextViewerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTextViewerDlg::OnBnClickedShowtext1()
{
	// TODO: Add your control notification handler code here
	CFileManager *op;
	op->WriteData(op->array[0]);
	
}


void CTextViewerDlg::OnBnClickedShowtext2()
{
	// TODO: Add your control notification handler code here
	CFileManager *op;
	//op->getInstance();
	
	op->WriteData(op->array[1]);
}


void CTextViewerDlg::OnBnClickedShowtext3()
{
	// TODO: Add your control notification handler code here
	CFileManager *op;
	//op->getInstance();
	
	op->WriteData(op->array[2]);
}


void CTextViewerDlg::OnBnClickedShowtext4()
{
	// TODO: Add your control notification handler code here
	CFileManager *op;
	//op->getInstance();
	op->WriteData(op->array[3]);

	
}
