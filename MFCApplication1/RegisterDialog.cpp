// RegisterDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"

HKEY hKey;//ע���
// CRegisterDialog �Ի���

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


// CRegisterDialog ��Ϣ�������


void CRegisterDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�⼸�����������϶���һ��long���͵ķ���ֵ���������ֵ == ERROR_SUCCESS��
	//	ERROR_SUCCESS��һ��������ֵΪ0����ʾ�ɹ�������ֵ��ʾʧ�ܡ�
	RegCreateKey(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\c0kstest"), &hKey);
}


void CRegisterDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	RegSetValue(hKey, NULL, REG_SZ, _T("c0ks"), 4);
}


void CRegisterDialog::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR chData[5] = _T("c0ks");
	RegSetValueEx(hKey, _T("add"), 0, REG_SZ, (CONST BYTE*)chData, sizeof(chData) / sizeof(TCHAR)* 2);
}


void CRegisterDialog::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LONG valueLen;
	RegQueryValue(hKey, NULL, NULL, &valueLen);
	TCHAR *chData = new TCHAR[valueLen];
	RegQueryValue(hKey, NULL, chData, &valueLen);
	AfxMessageBox(chData);
}


void CRegisterDialog::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DWORD dwType;
	DWORD dwLen;
	RegQueryValueEx(hKey, NULL, NULL, &dwType, NULL, &dwLen);
	TCHAR *chData = new TCHAR[dwLen];
	RegQueryValueEx(hKey, NULL, NULL, &dwType, (LPBYTE)chData, &dwLen);
	AfxMessageBox(chData);
}


void CRegisterDialog::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	RegCloseKey(hKey);
}
