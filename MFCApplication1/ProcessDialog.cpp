// ProcessDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ProcessDialog.h"
#include "afxdialogex.h"


// CProcessDialog �Ի���

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


// CProcessDialog ��Ϣ�������


void CProcessDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DWORD pid;
	HWND hWnd = ::FindWindow(NULL, _T("������"));//�ҵ��Ѵ��ڵĴ��ھ��
	GetWindowThreadProcessId(hWnd, &pid);//���ݴ��ھ����ȡ����pid
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//PROCESS_ALL_ACCESS����Ȩ��Ϊ����Ȩ�� 
	if (hProc == NULL)
		AfxMessageBox(_T("OpenProcess failed"));
	else
		AfxMessageBox(_T("OpenProcess ok"));
}


void CProcessDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TerminateProcess(hProc, 0); //�رս��̾��ΪhProc�Ľ��� 
}
