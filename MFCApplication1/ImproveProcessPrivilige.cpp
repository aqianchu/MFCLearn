// ImproveProcessPrivilige.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ImproveProcessPrivilige.h"
#include "afxdialogex.h"


// CImproveProcessPrivilige �Ի���

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
	HANDLE hToken;//�������ƾ��
	TOKEN_PRIVILEGES tkp;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	tkp.PrivilegeCount = 1;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{

		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid))
		{
			if (AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL))
				AfxMessageBox(_T("��Ȩ�ɹ�"));
		}
	}
	if (hToken) CloseHandle(hToken);//�رս������ƾ��
}

BEGIN_MESSAGE_MAP(CImproveProcessPrivilige, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CImproveProcessPrivilige::OnBnClickedButton1)
END_MESSAGE_MAP()


// CImproveProcessPrivilige ��Ϣ�������


void CImproveProcessPrivilige::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	RaisePrivileges();
}
