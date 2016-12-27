// AnonymousDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AnonymousDialog.h"
#include "afxdialogex.h"


// CAnonymousDialog 对话框

IMPLEMENT_DYNAMIC(CAnonymousDialog, CDialogEx)

CAnonymousDialog::CAnonymousDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAnonymousDialog::IDD, pParent)
{

}

CAnonymousDialog::~CAnonymousDialog()
{
}

void CAnonymousDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAnonymousDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAnonymousDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAnonymousDialog 消息处理程序
//匿名管道消息
void CAnonymousDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	HANDLE hPWrite, hPRead; //管道的读写句柄
	SECURITY_ATTRIBUTES sa = { 0 }; //安全设置结构体
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);//结构体大小
	sa.bInheritHandle = TRUE;/// /安全描述的对象能否被新创建的进程继承
	sa.lpSecurityDescriptor = NULL;//安全描述符，一般用NULl

	BOOL bCreate;
	bCreate = CreatePipe(&hPRead, &hPWrite, &sa, 0);//创建匿名管道
	if (!bCreate)
	{
		MessageBox(_T("创建管道失败"));
	}

	PROCESS_INFORMATION pi = { 0 };//进程信息结构体
	STARTUPINFO si = { 0 };//指定新进程的主窗口特性的结构体
	si.cb = sizeof(si);
	si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);//输入为默认
	si.hStdOutput = si.hStdError = hPWrite;//输出和出错信息写入管道

	si.wShowWindow = SW_HIDE;//隐藏新进程的窗口
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	TCHAR szCMD[MAX_PATH * 2] = { 0 };

	::GetDlgItemText(this->m_hWnd, IDC_EDIT1, szCMD, MAX_PATH * 2);
	bCreate = CreateProcess(NULL, szCMD, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi);//创建新进程(子进程)

	CloseHandle(pi.hProcess);
	if (!bCreate)
	{
		CloseHandle(hPRead);
		CloseHandle(hPWrite);
		MessageBox(_T("创建进程失败"));
	}
	else
	{
		CString str;
		CloseHandle(hPWrite);//读取之前必须先关闭写的句柄
		char szBuff[4096];
		DWORD dwRead;
		while (true)//循环读取
		{
			memset(szBuff, 0, sizeof(szBuff));
			if (!ReadFile(hPRead, szBuff, 4096, &dwRead, NULL))
				break;
			str += szBuff;
			str += '\n';
			SetDlgItemText(IDC_EDIT2, str);
		}
		CloseHandle(hPRead);//读取完毕关闭读取句柄
	}
}
