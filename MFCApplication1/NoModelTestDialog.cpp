// NoModelTestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NoModelTestDialog.h"
#include "afxdialogex.h"


// CNoModelTestDialog �Ի���

IMPLEMENT_DYNAMIC(CNoModelTestDialog, CDialogEx)

CNoModelTestDialog::CNoModelTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNoModelTestDialog::IDD, pParent)
{

}

CNoModelTestDialog::~CNoModelTestDialog()
{
}

//��ģʽ�Ի�����ͨ��newһ���Ի�����Ҫ�ͷŶ�Ӧ���ڴ棬�ͷ���������ص����ͷŵġ�
void CNoModelTestDialog::PostNcDestroy()
{
	delete this;
	CDialogEx::PostNcDestroy();
}

void CNoModelTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNoModelTestDialog, CDialogEx)
END_MESSAGE_MAP()


// CNoModelTestDialog ��Ϣ�������
