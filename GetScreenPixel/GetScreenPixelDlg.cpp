
// GetScreenPixelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GetScreenPixel.h"
#include "GetScreenPixelDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CGetScreenPixelDlg 对话框




CGetScreenPixelDlg::CGetScreenPixelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetScreenPixelDlg::IDD, pParent)
	, posx(0)
	, posy(0)
	, red(0)
	, green(0)
	, blue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetScreenPixelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_POSX, posx);
	DDX_Text(pDX, IDC_POSY, posy);
	DDX_Text(pDX, IDC_COLOR_R, red);
	DDX_Text(pDX, IDC_COLOR_G, green);
	DDX_Text(pDX, IDC_COLOR_B, blue);
	DDX_Control(pDX, IDC_STATE, m_colorState);
	DDX_Control(pDX, IDC_BACKCOLOR, m_background);
	DDX_Control(pDX, ID_CONTACT, m_linkMe);
}

BEGIN_MESSAGE_MAP(CGetScreenPixelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGetScreenPixelDlg 消息处理程序

BOOL CGetScreenPixelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_background.SetBkColor(RGB(0,0,0));
	m_background.SetForeColor(RGB(0,0,0));
	m_linkMe.SetBitmapImage(IDB_LINKME);
	m_linkMe.SetURL(_T("http://blog.csdn.net/hty1053240123?viewmode=contents"));

	SetTimer( MOUSE_MOVED, 10, NULL);	// 间隔10ms调用一次

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGetScreenPixelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGetScreenPixelDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGetScreenPixelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetScreenPixelDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (isFinish)
	{
		//	DWORD   dwPos = GetMessagePos(); 
		//	CPoint point( LOWORD(dwPos),   HIWORD(dwPos) );
		CPoint   point;
		GetCursorPos(&point);
		//	HWND hwnd=::GetForegroundWindow();
		HDC hDC = ::GetDC(NULL);

		// 再获取当前鼠标位置像素值
		COLORREF color = ::GetPixel(hDC, point.x, point.y);
		m_colorState.SetBkColor(color);
		posx = point.x;
		posy = point.y;
		red = GetRValue(color);
		green = GetGValue(color);
		blue = GetBValue(color);
		UpdateData(FALSE);
	}
	CDialogEx::OnTimer(nIDEvent);
}



BOOL CGetScreenPixelDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->lParam == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_LBUTTON:
			if (isFinish)
			{
				isFinish = FALSE;
			}
			else {
				isFinish = TRUE;
			}
			break;
		default:
			break;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
