// ThreadDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ThreadDialog.h"
#include "afxdialogex.h"


// CThreadDialog 对话框

IMPLEMENT_DYNAMIC(CThreadDialog, CDialogEx)

CThreadDialog::CThreadDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThreadDialog::IDD, pParent)
{

}

CThreadDialog::~CThreadDialog()
{
}

void CThreadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CThreadDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CThreadDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CThreadDialog 消息处理程序


void CThreadDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.wShowWindow = SW_SHOW;
	si.dwFlags = STARTF_USESHOWWINDOW;

	CreateProcess(_T("C:/Windows/system32/calc.exe"), NULL, NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//运行程序
	pi = { 0 };
	CreateProcess(_T("C:/Windows/explorer.exe"), _T(" D:\\"), NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//打开文件夹 D之前有空格
	pi = { 0 };
	CreateProcess(_T("C:/Program Files/Internet Explorer/iexplore.exe"), _T("www.baidu.com"), NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//打开网址
}
