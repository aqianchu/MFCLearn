// ThreadDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ThreadDialog.h"
#include "afxdialogex.h"


// CThreadDialog �Ի���

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


// CThreadDialog ��Ϣ�������


void CThreadDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.wShowWindow = SW_SHOW;
	si.dwFlags = STARTF_USESHOWWINDOW;

	CreateProcess(_T("C:/Windows/system32/calc.exe"), NULL, NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//���г���
	pi = { 0 };
	CreateProcess(_T("C:/Windows/explorer.exe"), _T(" D:\\"), NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//���ļ��� D֮ǰ�пո�
	pi = { 0 };
	CreateProcess(_T("C:/Program Files/Internet Explorer/iexplore.exe"), _T("www.baidu.com"), NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);//����ַ
}
