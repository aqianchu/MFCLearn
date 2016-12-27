// NoModelTestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NoModelTestDialog.h"
#include "afxdialogex.h"


// CNoModelTestDialog 对话框

IMPLEMENT_DYNAMIC(CNoModelTestDialog, CDialogEx)

CNoModelTestDialog::CNoModelTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNoModelTestDialog::IDD, pParent)
{

}

CNoModelTestDialog::~CNoModelTestDialog()
{
}

//非模式对话框是通过new一个对话框，需要释放对应的内存，释放是在这个回调中释放的。
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


// CNoModelTestDialog 消息处理程序
