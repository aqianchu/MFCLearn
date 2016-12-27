// TimeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "TimeDialog.h"
#include "afxdialogex.h"


// CTimeDialog 对话框

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


// CTimeDialog 消息处理程序


void CTimeDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	SetTimer(1, 100, NULL);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void CTimeDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
			MessageBox(_T("下载完成"));
		}
		else{
			nNewPos++;
		}
		m_Progress.SetPos(nNewPos);
	}
	CDialogEx::OnTimer(nIDEvent);
}
