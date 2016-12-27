// ProcessDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ProcessDialog.h"
#include "afxdialogex.h"


// CProcessDialog 对话框

IMPLEMENT_DYNAMIC(CProcessDialog, CDialogEx)

CProcessDialog::CProcessDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProcessDialog::IDD, pParent)
{

}

CProcessDialog::~CProcessDialog()
{
}

void CProcessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProcessDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CProcessDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProcessDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CProcessDialog 消息处理程序


void CProcessDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	DWORD pid;
	HWND hWnd = ::FindWindow(NULL, _T("计算器"));//找到已存在的窗口句柄
	GetWindowThreadProcessId(hWnd, &pid);//根据窗口句柄获取进程pid
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//PROCESS_ALL_ACCESS访问权限为所有权限 
	if (hProc == NULL)
		AfxMessageBox(_T("OpenProcess failed"));
	else
		AfxMessageBox(_T("OpenProcess ok"));
}


void CProcessDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	TerminateProcess(hProc, 0); //关闭进程句柄为hProc的进程 
}
