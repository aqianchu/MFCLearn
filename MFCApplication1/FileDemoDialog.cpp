// FileDemoDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileDemoDialog.h"
#include "afxdialogex.h"


// CFileDemoDialog �Ի���

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


// CFileDemoDialog ��Ϣ�������


void CFileDemoDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeCreate);
	file.Close();
}


void CFileDemoDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeWrite);
	CString editstr;
	GetDlgItemText(IDC_EDIT1, editstr);
	if (editstr.IsEmpty()) {
		AfxMessageBox(_T("�������岻��Ϊ��"));
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString filename = _T("D:/cfile.txt");
	CFile file(filename, CFile::modeRead);
	char *str = new char[file.GetLength()];
	file.Read(str, file.GetLength()*sizeof(char));
	file.Close();
	AfxMessageBox(CString(str));
}
