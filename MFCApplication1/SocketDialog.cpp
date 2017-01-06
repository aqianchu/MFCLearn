// SocketDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SocketDialog.h"
#include "afxdialogex.h"


// CSocketDialog �Ի���

IMPLEMENT_DYNAMIC(CSocketDialog, CDialogEx)

CSocketDialog::CSocketDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSocketDialog::IDD, pParent)
{

}

CSocketDialog::~CSocketDialog()
{
}

void CSocketDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSocketDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSocketDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSocketDialog ��Ϣ�������


void CSocketDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	WSAData data;
	WORD wVersionRqueested = MAKEWORD(2, 0);
	::WSAStartup(wVersionRqueested, &data);
	SOCKET s;
	s = ::socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(666);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (::connect(s, (sockaddr*)&addr, sizeof(addr)))//����
		MessageBox(_T("���ӳɹ�"));
	char buf[1024] = { 0 };
	int i = ::recv(s, buf, sizeof(buf), 0);//��������
	SetDlgItemText(IDC_EDIT1, CString(buf));
	::closesocket(s);//�رվ��
}
