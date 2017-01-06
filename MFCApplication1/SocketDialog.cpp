// SocketDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SocketDialog.h"
#include "afxdialogex.h"


// CSocketDialog 对话框

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


// CSocketDialog 消息处理程序


void CSocketDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	WSAData data;
	WORD wVersionRqueested = MAKEWORD(2, 0);
	::WSAStartup(wVersionRqueested, &data);
	SOCKET s;
	s = ::socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(666);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (::connect(s, (sockaddr*)&addr, sizeof(addr)))//连接
		MessageBox(_T("连接成功"));
	char buf[1024] = { 0 };
	int i = ::recv(s, buf, sizeof(buf), 0);//接收数据
	SetDlgItemText(IDC_EDIT1, CString(buf));
	::closesocket(s);//关闭句柄
}
