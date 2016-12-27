// PictureDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "PictureDialog.h"
#include "afxdialogex.h"


// CPictureDialog �Ի���

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


// CPictureDialog ��Ϣ�������


void CPictureDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, _T("*.bmp|*.bmp"));
	if (dlg.DoModal() == IDOK)
	{
		HBITMAP phBmp = (HBITMAP)LoadImage(NULL, dlg.GetPathName(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_pic.SetBitmap(phBmp);
	}
}
