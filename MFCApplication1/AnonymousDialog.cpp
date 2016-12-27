// AnonymousDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AnonymousDialog.h"
#include "afxdialogex.h"


// CAnonymousDialog �Ի���

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


// CAnonymousDialog ��Ϣ�������
//�����ܵ���Ϣ
void CAnonymousDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HANDLE hPWrite, hPRead; //�ܵ��Ķ�д���
	SECURITY_ATTRIBUTES sa = { 0 }; //��ȫ���ýṹ��
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);//�ṹ���С
	sa.bInheritHandle = TRUE;/// /��ȫ�����Ķ����ܷ��´����Ľ��̼̳�
	sa.lpSecurityDescriptor = NULL;//��ȫ��������һ����NULl

	BOOL bCreate;
	bCreate = CreatePipe(&hPRead, &hPWrite, &sa, 0);//���������ܵ�
	if (!bCreate)
	{
		MessageBox(_T("�����ܵ�ʧ��"));
	}

	PROCESS_INFORMATION pi = { 0 };//������Ϣ�ṹ��
	STARTUPINFO si = { 0 };//ָ���½��̵����������ԵĽṹ��
	si.cb = sizeof(si);
	si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);//����ΪĬ��
	si.hStdOutput = si.hStdError = hPWrite;//����ͳ�����Ϣд��ܵ�

	si.wShowWindow = SW_HIDE;//�����½��̵Ĵ���
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	TCHAR szCMD[MAX_PATH * 2] = { 0 };

	::GetDlgItemText(this->m_hWnd, IDC_EDIT1, szCMD, MAX_PATH * 2);
	bCreate = CreateProcess(NULL, szCMD, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi);//�����½���(�ӽ���)

	CloseHandle(pi.hProcess);
	if (!bCreate)
	{
		CloseHandle(hPRead);
		CloseHandle(hPWrite);
		MessageBox(_T("��������ʧ��"));
	}
	else
	{
		CString str;
		CloseHandle(hPWrite);//��ȡ֮ǰ�����ȹر�д�ľ��
		char szBuff[4096];
		DWORD dwRead;
		while (true)//ѭ����ȡ
		{
			memset(szBuff, 0, sizeof(szBuff));
			if (!ReadFile(hPRead, szBuff, 4096, &dwRead, NULL))
				break;
			str += szBuff;
			str += '\n';
			SetDlgItemText(IDC_EDIT2, str);
		}
		CloseHandle(hPRead);//��ȡ��Ϲرն�ȡ���
	}
}
