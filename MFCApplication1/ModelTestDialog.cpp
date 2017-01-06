// ModelTestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ModelTestDialog.h"
#include "afxdialogex.h"


// CModelTestDialog 对话框

IMPLEMENT_DYNAMIC(CModelTestDialog, CDialogEx)

CModelTestDialog::CModelTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModelTestDialog::IDD, pParent)
{

}

CModelTestDialog::~CModelTestDialog()
{
}

void CModelTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModelTestDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CModelTestDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CModelTestDialog 消息处理程序


void CModelTestDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
}
