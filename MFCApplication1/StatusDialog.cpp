// StatusDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "StatusDialog.h"
#include "afxdialogex.h"


// CStatusDialog 对话框

IMPLEMENT_DYNAMIC(CStatusDialog, CDialogEx)

CStatusDialog::CStatusDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStatusDialog::IDD, pParent)
{

}

CStatusDialog::~CStatusDialog()
{
}
BOOL CStatusDialog::OnInitDialog()
{
	m_status.Create(this);
	UINT nId[] = { 1000, 1001 };
	m_status.SetIndicators(nId, 2);
	m_status.SetPaneInfo(0, 1000, SBPS_NORMAL, 100);
	m_status.SetPaneInfo(1, 1001, SBPS_STRETCH, 0);
	RECT rect = { 0 };
	GetClientRect(&rect);
	m_status.MoveWindow(0, rect.bottom - 20, rect.right, 20, true);
	return TRUE;
}
void CStatusDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CStatusDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CStatusDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CStatusDialog 消息处理程序


void CStatusDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	int nLen = m_edit.GetWindowTextLengthW();
	CString str;
	str.Format(_T("字数：%d"), nLen);
	m_status.SetPaneText(1, str);
}
