
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UINT WM_MY_REGISTERED_MSG;
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


// CMFCApplication1Dlg �Ի���



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
	//�Զ�����Ϣӳ��
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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_INPUT_EDIT1, str);
	int len = str.GetLength();
	CString strlen;
	strlen.Format(_T("�ַ�������Ϊ%d"), len);

	MessageBox(strlen);
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str("A1");
	GetDlgItem(IDC_TEST_STATIC)->SetWindowText(str);
}

void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str("test");
	GetDlgItem(IDC_GETTEXT_EDIT2)->GetWindowText(str);
	if (!str.IsEmpty()){
		CString cs("�����ǣ�");
		CString temp = cs + str;
		MessageBox(str);
	}else{
		MessageBox(_T("��Ϣ����Ϊ��"));
	}
}


void CMFCApplication1Dlg::OnBnClickedTestButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	test_value = "Test bangding";
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedBandButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	MessageBox(test_value);
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnBnClickedTiaoButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CNextTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedComboListButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CComboBoxDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CHorizonAndVertical dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CTimeDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CListTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDateTestDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::On32771()
{
	// TODO:  �ڴ���������������
	//AfxMessageBox(_T("�򿪱����"));
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("�ı��ĵ�|*.txt|"), this);
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
			AfxMessageBox(_T("����Ϊ��"));
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
	// TODO:  �ڴ˴������Ϣ����������
	CMenu menu;
	menu.LoadMenuW(IDR_MENU2);
	CMenu *pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, pWnd, 0);
}


void CMFCApplication1Dlg::OnBnClickedButton12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CStatusDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CModelMainDialog dialog;
	dialog.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CPictureDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSpyDialog d;
	d.DoModal();
}

LRESULT CMFCApplication1Dlg::OnMyMsg(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("�յ���ϢWM_MY_DEFINE_MSG"));
	return 0;
}
LRESULT CMFCApplication1Dlg::OnMyMsg1(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("�յ���ϢWM_MY_REGISTERED_MSG"));
	return 0;
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PostMessage(WM_MY_DEFINE_MSG,0,0);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PostMessage(WM_MY_REGISTERED_MSG);
	//���淢����Ϣ�õ���PostMessage����SendMessageҲ�ǿ��Ե�.
	/*PostMessage��SendMessage������
		PostMessageֻ������Ϣ�ŵ���Ϣ�����У���ȷ����ʱ���Ƿ���
		SendMessageҪ�ȵ��ܵ���Ϣ����ķ������ż���
		PostMessageִ�к����Ϸ���
		SendMessage����ȵ���Ϣ�������Ż᷵�ء�*/
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CRegisterDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CGetSystemDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CStartBootDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton17()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CThreadDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton18()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CProcessDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton19()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CAnonymousDialog dl;
	dl.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton20()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CImproveProcessPrivilige d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton21()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDemoDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton22()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMySQLDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton23()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSocketDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton24()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CScreenCapDialog d;
	d.DoModal();
}


void CMFCApplication1Dlg::OnBnClickedButton25()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CComputerDialog d;
	d.DoModal();
}
