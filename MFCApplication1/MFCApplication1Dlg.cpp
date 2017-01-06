
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UINT WM_MY_REGISTERED_MSG;
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, test_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	WM_MY_REGISTERED_MSG = RegisterWindowMessage(_T("c0ks"));
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, test_control);
	DDX_Text(pDX, IDC_EDIT3, test_value);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_TEST_BUTTON4, &CMFCApplication1Dlg::OnBnClickedTestButton4)
	ON_BN_CLICKED(IDC_BAND_BUTTON5, &CMFCApplication1Dlg::OnBnClickedBandButton5)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_TIAO_BUTTON6, &CMFCApplication1Dlg::OnBnClickedTiaoButton6)
	ON_BN_CLICKED(IDC_COMBO_LIST_BUTTON7, &CMFCApplication1Dlg::OnBnClickedComboListButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::OnBnClickedButton11)
	ON_COMMAND(ID_32771, &CMFCApplication1Dlg::On32771)
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	//自定义消息映射
	ON_MESSAGE(WM_MY_DEFINE_MSG, &CMFCApplication1Dlg::OnMyMsg)
	ON_REGISTERED_MESSAGE(WM_MY_REGISTERED_MSG, &CMFCApplication1Dlg::OnMyMsg1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication1Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication1Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCApplication1Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCApplication1Dlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CMFCApplication1Dlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCApplication1Dlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCApplication1Dlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCApplication1Dlg::OnBnClickedButton25)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_INPUT_EDIT1, str);
	int len = str.GetLength();
	CString strlen;
	strlen.Format(_T("字符串数量为%d"), len);

	MessageBox(strlen);
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str("A1");
	GetDlgItem(IDC_TEST_STATIC)->SetWindowText(str);
}

void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str("test");
	GetDlgItem(IDC_GETTEXT_EDIT2)->GetWindowText(str);
	if (!str.IsEmpty()){
		CString cs("内容是：");
		CString temp = cs + str;
		MessageBox(str);
	}else{
		MessageBox(_T("消息内容为空"));
	}
}


void CMFCApplication1Dlg::OnBnClickedTestButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	test_value = "Test bangding";
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedBandButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	MessageBox(test_value);
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnBnClickedTiaoButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	CNextTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedComboListButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	CComboBoxDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	CHorizonAndVertical dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	CTimeDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO:  在此添加控件通知处理程序代码
	CListTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	CDateTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::On32771()
{
	// TODO:  在此添加命令处理程序代码
	//AfxMessageBox(_T("打开被点击"));
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("文本文档|*.txt|"), this);
	dlg.m_ofn.lpstrInitialDir = _T("D:\\");
	if (dlg.DoModal() == IDOK)
	{
		//AfxMessageBox(dlg.GetPathName());
		//CString str = dlg.GetPathName();
		/*FILE * pfile = fopen((LPSTR)(LPCTSTR)str, "r");
		if (pfile){
			TCHAR szBuf[MAX_PATH];
			fread(szBuf, 1, MAX_PATH, pfile);
			GetDlgItem(IDC_EDIT4)->SetWindowText(szBuf);
			fclose(pfile);
		}
		else{
			AfxMessageBox(_T("内容为空"));
		}*/
		CString str;
		CFile f;
		f.Open(dlg.GetPathName(), CFile::modeReadWrite);
		int len = f.GetLength() + 1;
		char *pBuf = new char[len];
		memset(pBuf, 0, len);
		//f.Read(str.GetBuffer(f.GetLength()), f.GetLength());
		f.Read(pBuf, len);
		f.Close();
		str = pBuf;
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);
	}
}


void CMFCApplication1Dlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO:  在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenuW(IDR_MENU2);
	CMenu *pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, pWnd, 0);
}


void CMFCApplication1Dlg::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码
	CStatusDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton13()
{
	// TODO:  在此添加控件通知处理程序代码
	CModelMainDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	// TODO:  在此添加控件通知处理程序代码
	CPictureDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CSpyDialog d;
	d.DoModal();
}

LRESULT CMFCApplication1Dlg::OnMyMsg(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("收到消息WM_MY_DEFINE_MSG"));
	return 0;
}
LRESULT CMFCApplication1Dlg::OnMyMsg1(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("收到消息WM_MY_REGISTERED_MSG"));
	return 0;
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	PostMessage(WM_MY_DEFINE_MSG,0,0);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	PostMessage(WM_MY_REGISTERED_MSG);
	//上面发送消息用的是PostMessage，用SendMessage也是可以的.
	/*PostMessage和SendMessage的区别：
		PostMessage只负责将消息放到消息队列中，不确定何时及是否处理
		SendMessage要等到受到消息处理的返回码后才继续
		PostMessage执行后马上返回
		SendMessage必须等到消息被处理后才会返回。*/
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	CRegisterDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO:  在此添加控件通知处理程序代码
	CGetSystemDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton16()
{
	// TODO:  在此添加控件通知处理程序代码
	CStartBootDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton17()
{
	// TODO:  在此添加控件通知处理程序代码
	CThreadDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton18()
{
	// TODO:  在此添加控件通知处理程序代码
	CProcessDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton19()
{
	// TODO:  在此添加控件通知处理程序代码
	CAnonymousDialog dl;
	dl.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton20()
{
	// TODO:  在此添加控件通知处理程序代码
	CImproveProcessPrivilige d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton21()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDemoDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton22()
{
	// TODO:  在此添加控件通知处理程序代码
	CMySQLDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton23()
{
	// TODO:  在此添加控件通知处理程序代码
	CSocketDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton24()
{
	// TODO:  在此添加控件通知处理程序代码
	CScreenCapDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton25()
{
	// TODO:  在此添加控件通知处理程序代码
	CComputerDialog d;
	d.DoModal();
}
