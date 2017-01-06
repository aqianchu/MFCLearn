// ImproveProcessPrivilige.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ImproveProcessPrivilige.h"
#include "afxdialogex.h"


// CImproveProcessPrivilige 对话框

IMPLEMENT_DYNAMIC(CImproveProcessPrivilige, CDialogEx)

CImproveProcessPrivilige::CImproveProcessPrivilige(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImproveProcessPrivilige::IDD, pParent)
{

}

CImproveProcessPrivilige::~CImproveProcessPrivilige()
{
}

void CImproveProcessPrivilige::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CImproveProcessPrivilige::RaisePrivileges()
{
	HANDLE hToken;//进程令牌句柄
	TOKEN_PRIVILEGES tkp;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	tkp.PrivilegeCount = 1;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{

		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid))
		{
			if (AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL))
				AfxMessageBox(_T("提权成功"));
		}
	}
	if (hToken) CloseHandle(hToken);//关闭进程令牌句柄
}

BEGIN_MESSAGE_MAP(CImproveProcessPrivilige, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CImproveProcessPrivilige::OnBnClickedButton1)
END_MESSAGE_MAP()


// CImproveProcessPrivilige 消息处理程序


void CImproveProcessPrivilige::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	RaisePrivileges();
}
