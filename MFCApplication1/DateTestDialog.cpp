// DateTestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "DateTestDialog.h"
#include "afxdialogex.h"


// CDateTestDialog 对话框

IMPLEMENT_DYNAMIC(CDateTestDialog, CDialogEx)

CDateTestDialog::CDateTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDateTestDialog::IDD, pParent)
{

}

CDateTestDialog::~CDateTestDialog()
{
}

void CDateTestDialog::CalcDate()
{
	CTime dateBegin;
	CTime dateOver;
	m_DateBegin.GetTime(dateBegin);

	m_DateOver.GetTime(dateOver);

	CTimeSpan dateSpan = dateOver - dateBegin;
	CString dateStr;
	dateStr.Format(_T("相差%d天"), dateSpan.GetDays());//GetDays() 获取天数
	SetDlgItemText(IDC_STATIC, dateStr);
}
void CDateTestDialog::CalcTime()
{
	CTime timeBegin;
	CTime timeOver;
	m_TimeBegin.GetTime(timeBegin);
	m_TimeOver.GetTime(timeOver);

	CTimeSpan TimeSpan = timeOver - timeBegin;
	CString timeStr;
	timeStr.Format(_T("相差%d小时%d分钟%d秒"), TimeSpan.GetHours(), TimeSpan.GetMinutes(), TimeSpan.GetSeconds());//分别是获取小时，获取分钟 获取秒数 
	SetDlgItemText(IDC_STATIC2, timeStr);
}

void CDateTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_DateBegin);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_DateOver);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_TimeBegin);
	DDX_Control(pDX, IDC_DATETIMEPICKER4, m_TimeOver);
}


BEGIN_MESSAGE_MAP(CDateTestDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDateTestDialog::OnBnClickedButton1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CDateTestDialog::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER3, &CDateTestDialog::OnDtnDatetimechangeDatetimepicker3)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &CDateTestDialog::OnDtnDatetimechangeDatetimepicker2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER4, &CDateTestDialog::OnDtnDatetimechangeDatetimepicker4)
END_MESSAGE_MAP()


// CDateTestDialog 消息处理程序


void CDateTestDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CDateTestDialog::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CalcDate();
	*pResult = 0;
}


void CDateTestDialog::OnDtnDatetimechangeDatetimepicker3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CalcDate();
	*pResult = 0;
}


void CDateTestDialog::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CalcTime();
	*pResult = 0;
}


void CDateTestDialog::OnDtnDatetimechangeDatetimepicker4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CalcTime();
	*pResult = 0;
}
