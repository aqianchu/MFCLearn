
// GetScreenPixelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetScreenPixel.h"
#include "GetScreenPixelDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGetScreenPixelDlg �Ի���




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


// CGetScreenPixelDlg ��Ϣ�������

BOOL CGetScreenPixelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_background.SetBkColor(RGB(0,0,0));
	m_background.SetForeColor(RGB(0,0,0));
	m_linkMe.SetBitmapImage(IDB_LINKME);
	m_linkMe.SetURL(_T("http://blog.csdn.net/hty1053240123?viewmode=contents"));

	SetTimer( MOUSE_MOVED, 10, NULL);	// ���10ms����һ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetScreenPixelDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGetScreenPixelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetScreenPixelDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (isFinish)
	{
		//	DWORD   dwPos = GetMessagePos(); 
		//	CPoint point( LOWORD(dwPos),   HIWORD(dwPos) );
		CPoint   point;
		GetCursorPos(&point);
		//	HWND hwnd=::GetForegroundWindow();
		HDC hDC = ::GetDC(NULL);

		// �ٻ�ȡ��ǰ���λ������ֵ
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
	// TODO:  �ڴ����ר�ô����/����û���
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
