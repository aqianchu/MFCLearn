// StartBootDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "StartBootDialog.h"
#include "afxdialogex.h"


// CStartBootDialog 对话框

IMPLEMENT_DYNAMIC(CStartBootDialog, CDialogEx)

CStartBootDialog::CStartBootDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStartBootDialog::IDD, pParent)
{

}

CStartBootDialog::~CStartBootDialog()
{
}

void CStartBootDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStartBootDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CStartBootDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStartBootDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStartBootDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CStartBootDialog 消息处理程序

void CStartBootDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	ExitWindowsEx(EWX_SHUTDOWN, 0);
}


void CStartBootDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	ExitWindowsEx(EWX_REBOOT, 0);
}


void CStartBootDialog::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	ExitWindowsEx(EWX_LOGOFF, 0);
}
