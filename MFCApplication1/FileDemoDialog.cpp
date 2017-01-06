// FileDemoDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileDemoDialog.h"
#include "afxdialogex.h"


// CFileDemoDialog 对话框

IMPLEMENT_DYNAMIC(CFileDemoDialog, CDialogEx)

CFileDemoDialog::CFileDemoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileDemoDialog::IDD, pParent)
{

}

CFileDemoDialog::~CFileDemoDialog()
{
}

void CFileDemoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileDemoDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFileDemoDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFileDemoDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFileDemoDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFileDemoDialog 消息处理程序


void CFileDemoDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeCreate);
	file.Close();
}


void CFileDemoDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeWrite);
	CString editstr;
	GetDlgItemText(IDC_EDIT1, editstr);
	if (editstr.IsEmpty()) {
		AfxMessageBox(_T("输入字体不能为空"));
		return;
	}
	int len = WideCharToMultiByte(CP_ACP, 0, editstr, -1, NULL, 0, NULL, NULL);
	char *str = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, editstr, -1, str, len, NULL, NULL);
	//char *str = (LPSTR)(LPCTSTR)editstr;
	file.Write(str, sizeof(str));
	file.Close();
	delete[] str;
	
}


void CFileDemoDialog::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeRead);
	char *str = new char[file.GetLength()];
	file.Read(str, file.GetLength()*sizeof(char));
	file.Close();
	AfxMessageBox(CString(str));
}
