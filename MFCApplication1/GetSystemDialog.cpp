// GetSystemDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "GetSystemDialog.h"
#include "afxdialogex.h"


// CGetSystemDialog �Ի���

IMPLEMENT_DYNAMIC(CGetSystemDialog, CDialogEx)

CGetSystemDialog::CGetSystemDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetSystemDialog::IDD, pParent)
{

}

CGetSystemDialog::~CGetSystemDialog()
{
}

void CGetSystemDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetSystemDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetSystemDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGetSystemDialog ��Ϣ�������


void CGetSystemDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CListBox *list = (CListBox*)GetDlgItem(IDC_LIST1);
	CString str;
	str.Format(_T("��Ļ��С%d*%d"), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	list->AddString(str);
	str.Format(_T("�˵�����ť�ߴ�%d*%d"), GetSystemMetrics(SM_CXMENUSIZE), GetSystemMetrics(SM_CYMENUSIZE));
	list->AddString(str);
	str.Format(_T("ͼ��ߴ�%d*%d"), GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
	list->AddString(str);
	str.Format(_T("���ڱ������ĸ߶�%d"), GetSystemMetrics(SM_CYCAPTION));
	list->AddString(str);
	str.Format(_T("ͼ��ߴ�%d*%d"), GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
	list->AddString(str);
}
