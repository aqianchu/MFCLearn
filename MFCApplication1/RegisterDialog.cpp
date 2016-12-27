// RegisterDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"

HKEY hKey;//注册表
// CRegisterDialog 对话框

IMPLEMENT_DYNAMIC(CRegisterDialog, CDialogEx)

CRegisterDialog::CRegisterDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDialog::IDD, pParent)
{

}

CRegisterDialog::~CRegisterDialog()
{
}

void CRegisterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegisterDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRegisterDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRegisterDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRegisterDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRegisterDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CRegisterDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CRegisterDialog::OnBnClickedButton6)
END_MESSAGE_MAP()


// CRegisterDialog 消息处理程序


void CRegisterDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//这几个函数基本上都有一个long类型的返回值，如果返回值 == ERROR_SUCCESS，
	//	ERROR_SUCCESS是一个常量，值为0，表示成功，其他值表示失败。
	RegCreateKey(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\c0kstest"), &hKey);
}


void CRegisterDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	RegSetValue(hKey, NULL, REG_SZ, _T("c0ks"), 4);
}


void CRegisterDialog::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR chData[5] = _T("c0ks");
	RegSetValueEx(hKey, _T("add"), 0, REG_SZ, (CONST BYTE*)chData, sizeof(chData) / sizeof(TCHAR)* 2);
}


void CRegisterDialog::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	LONG valueLen;
	RegQueryValue(hKey, NULL, NULL, &valueLen);
	TCHAR *chData = new TCHAR[valueLen];
	RegQueryValue(hKey, NULL, chData, &valueLen);
	AfxMessageBox(chData);
}


void CRegisterDialog::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	DWORD dwType;
	DWORD dwLen;
	RegQueryValueEx(hKey, NULL, NULL, &dwType, NULL, &dwLen);
	TCHAR *chData = new TCHAR[dwLen];
	RegQueryValueEx(hKey, NULL, NULL, &dwType, (LPBYTE)chData, &dwLen);
	AfxMessageBox(chData);
}


void CRegisterDialog::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	RegCloseKey(hKey);
}
