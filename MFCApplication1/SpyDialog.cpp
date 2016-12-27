// SpyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SpyDialog.h"
#include "afxdialogex.h"


// CSpyDialog 对话框

IMPLEMENT_DYNAMIC(CSpyDialog, CDialogEx)

CSpyDialog::CSpyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSpyDialog::IDD, pParent)
{

}

CSpyDialog::~CSpyDialog()
{
}

void CSpyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSpyDialog, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CSpyDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSpyDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSpyDialog 消息处理程序


void CSpyDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	CRect m_rtCtrl;
	CRect   m_rtCwin;
	GetDlgItem(IDC_STATIC)->GetClientRect(rect);

	this->GetWindowRect(&m_rtCwin);

	GetDlgItem(IDC_STATIC)->GetWindowRect(&m_rtCtrl);
	CString str, str1, str2;
	CRect m_Rect;
	m_Rect.left = m_rtCtrl.left - m_rtCwin.left;
	//  m_Rect.right = m_rtCwin.right - m_rtCtrl.right;
	m_Rect.top = m_rtCtrl.top - m_rtCwin.top;
	//  m_Rect.bottom = m_rtCwin.bottom - m_rtCtrl.bottom;
	//  str.Format(_T("left=%dright=%dtop=%dbottom=%d"), m_Rect.left, m_Rect.right, m_Rect.top, m_Rect.bottom);
	//  str1.Format(_T("x=%dy=%d"), point.x, point.y);
	//  AfxMessageBox(str);AfxMessageBox(str1);
	int Index = GetSystemMetrics(SM_CYSMCAPTION);//获取窗口标题栏的高度
	if (point.x >= m_Rect.left && point.x <= m_Rect.left + rect.Width()
		&& point.y >= m_Rect.top - Index  && point.y <= m_Rect.top - Index + rect.Height()
		)//
	{
		//  MessageBox(_T("点击了图片控件"));
		m_bCapturing = TRUE;//确定鼠标状态
		m_hCursor = LoadCursor(NULL, IDC_SIZEALL);//加载鼠标光标 IDC_SIZEALL为四个方向带箭头的光标
		SetCapture();//开始鼠标捕获
		SetCursor(m_hCursor); //设置当前鼠标光标 
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSpyDialog::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bCapturing)
	{
		ReleaseCapture();//释放鼠标捕获
		m_bCapturing = FALSE;
		POINT pt = point;
		ClientToScreen(&pt);//获取窗口的屏幕坐标
		m_hWndDest = ::WindowFromPoint(pt);//根据坐标获取窗口的句柄
		TCHAR szBuf[MAX_PATH] = { 0 };
		_stprintf_s(szBuf, _T("0x%0.8x"), m_hWndDest);
		SetDlgItemText(IDC_EDIT1, szBuf);
		GetClassName(m_hWndDest, szBuf, MAX_PATH);//根据句柄获取窗口的类名 
		SetDlgItemText(IDC_EDIT2, szBuf);

		::SendMessage(m_hWndDest, WM_GETTEXT, MAX_PATH, (LPARAM)szBuf); //发送消息获取窗口的标题
		SetDlgItemText(IDC_EDIT3, szBuf);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CSpyDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_EDIT3, str);
	::SendMessage(m_hWndDest, WM_SETTEXT, 0, (LPARAM)(LPCTSTR)str);
}


void CSpyDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	::SendMessage(m_hWndDest, WM_CLOSE, 0, 0);
}
