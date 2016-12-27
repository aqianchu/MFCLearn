// TimeDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "TimeDialog.h"
#include "afxdialogex.h"


// CTimeDialog �Ի���

IMPLEMENT_DYNAMIC(CTimeDialog, CDialogEx)

CTimeDialog::CTimeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTimeDialog::IDD, pParent)
{

}

BOOL CTimeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_Progress.SetRange32(0, 100);
	return TRUE;
}

CTimeDialog::~CTimeDialog()
{
}

void CTimeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
}


BEGIN_MESSAGE_MAP(CTimeDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTimeDialog::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTimeDialog ��Ϣ�������


void CTimeDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1, 100, NULL);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void CTimeDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 1)
	{
		int nMax, nMin;
		m_Progress.GetRange(nMin, nMax);
		int nNewPos = m_Progress.GetPos();
		if (nNewPos >= nMax)
		{
			nNewPos = nMin;
			KillTimer(1);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
			MessageBox(_T("�������"));
		}
		else{
			nNewPos++;
		}
		m_Progress.SetPos(nNewPos);
	}
	CDialogEx::OnTimer(nIDEvent);
}
