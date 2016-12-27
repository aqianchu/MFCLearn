// ModelMainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ModelMainDialog.h"
#include "afxdialogex.h"


// CModelMainDialog 对话框

IMPLEMENT_DYNAMIC(CModelMainDialog, CDialogEx)

CModelMainDialog::CModelMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModelMainDialog::IDD, pParent)
{

}

CModelMainDialog::~CModelMainDialog()
{
}

void CModelMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModelMainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CModelMainDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CModelMainDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CModelMainDialog 消息处理程序


void CModelMainDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CModelTestDialog testDialog;
	testDialog.DoModal();
}


void CModelMainDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CNoModelTestDialog *model = new CNoModelTestDialog();
	model->Create(IDD_DIALOG10, this);
	model->ShowWindow(SW_SHOW);
}
