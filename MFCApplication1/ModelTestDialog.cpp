// ModelTestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ModelTestDialog.h"
#include "afxdialogex.h"


// CModelTestDialog �Ի���

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
END_MESSAGE_MAP()


// CModelTestDialog ��Ϣ�������
