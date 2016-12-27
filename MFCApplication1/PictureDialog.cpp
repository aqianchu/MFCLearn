// PictureDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "PictureDialog.h"
#include "afxdialogex.h"


// CPictureDialog 对话框

IMPLEMENT_DYNAMIC(CPictureDialog, CDialogEx)

CPictureDialog::CPictureDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPictureDialog::IDD, pParent)
{

}

CPictureDialog::~CPictureDialog()
{
}

void CPictureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MY_PICTURE, m_pic);
}


BEGIN_MESSAGE_MAP(CPictureDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPictureDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPictureDialog 消息处理程序


void CPictureDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, _T("*.bmp|*.bmp"));
	if (dlg.DoModal() == IDOK)
	{
		HBITMAP phBmp = (HBITMAP)LoadImage(NULL, dlg.GetPathName(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_pic.SetBitmap(phBmp);
	}
}
