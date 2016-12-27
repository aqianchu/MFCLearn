// NextTestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NextTestDialog.h"
#include "afxdialogex.h"


// CNextTestDialog �Ի���

IMPLEMENT_DYNAMIC(CNextTestDialog, CDialogEx)

CNextTestDialog::CNextTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNextTestDialog::IDD, pParent)
	, radio2(0)
{

}

CNextTestDialog::~CNextTestDialog()
{
}

void CNextTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_CHECK2, check2);
	DDX_Control(pDX, IDC_CHECK3, check3);
	DDX_Control(pDX, IDC_RADIO1, radio1);
}


BEGIN_MESSAGE_MAP(CNextTestDialog, CDialogEx)
	ON_BN_CLICKED(IDC_NEXT_BUTTON1, &CNextTestDialog::OnBnClickedNextButton1)
END_MESSAGE_MAP()


// CNextTestDialog ��Ϣ�������


void CNextTestDialog::OnBnClickedNextButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (radio1.GetCheck())
	{
		CString str1, str2, str3;
		if (check1.GetCheck())
		{
			check1.GetWindowTextW(str1);
		}
		if (check2.GetCheck())
		{
			check2.GetWindowTextW(str2);
		}
		if (check3.GetCheck())
		{
			check3.GetWindowTextW(str3);
		}
		MessageBox(str1 + str2 + str3);
	}
}
