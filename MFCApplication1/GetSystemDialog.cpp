// GetSystemDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "GetSystemDialog.h"
#include "afxdialogex.h"


// CGetSystemDialog 对话框

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


// CGetSystemDialog 消息处理程序


void CGetSystemDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CListBox *list = (CListBox*)GetDlgItem(IDC_LIST1);
	CString str;
	str.Format(_T("屏幕大小%d*%d"), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	list->AddString(str);
	str.Format(_T("菜单栏按钮尺寸%d*%d"), GetSystemMetrics(SM_CXMENUSIZE), GetSystemMetrics(SM_CYMENUSIZE));
	list->AddString(str);
	str.Format(_T("图标尺寸%d*%d"), GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
	list->AddString(str);
	str.Format(_T("窗口标题栏的高度%d"), GetSystemMetrics(SM_CYCAPTION));
	list->AddString(str);
	str.Format(_T("图标尺寸%d*%d"), GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
	list->AddString(str);
}
