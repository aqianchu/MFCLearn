// StatusDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "StatusDialog.h"
#include "afxdialogex.h"


// CStatusDialog �Ի���

IMPLEMENT_DYNAMIC(CStatusDialog, CDialogEx)

CStatusDialog::CStatusDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStatusDialog::IDD, pParent)
{

}

CStatusDialog::~CStatusDialog()
{
}
BOOL CStatusDialog::OnInitDialog()
{
	m_status.Create(this);
	UINT nId[] = { 1000, 1001 };
	m_status.SetIndicators(nId, 2);
	m_status.SetPaneInfo(0, 1000, SBPS_NORMAL, 100);
	m_status.SetPaneInfo(1, 1001, SBPS_STRETCH, 0);
	RECT rect = { 0 };
	GetClientRect(&rect);
	m_status.MoveWindow(0, rect.bottom - 20, rect.right, 20, true);
	return TRUE;
}
void CStatusDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CStatusDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CStatusDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CStatusDialog ��Ϣ�������


void CStatusDialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nLen = m_edit.GetWindowTextLengthW();
	CString str;
	str.Format(_T("������%d"), nLen);
	m_status.SetPaneText(1, str);
}
