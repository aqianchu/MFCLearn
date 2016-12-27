// HorizonAndVertical.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "HorizonAndVertical.h"
#include "afxdialogex.h"


// CHorizonAndVertical 对话框

IMPLEMENT_DYNAMIC(CHorizonAndVertical, CDialogEx)

CHorizonAndVertical::CHorizonAndVertical(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHorizonAndVertical::IDD, pParent)
	, c_edittext(_T(""))
{
	
}

BOOL CHorizonAndVertical::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//控件和变量绑定之后
	SCROLLINFO si = { 0 };
	si.cbSize = sizeof(SCROLLBARINFO);
	si.fMask = SIF_ALL;
	si.nMax = 100;
	si.nMin = 0;
	si.nPage = 1;
	m_hs.SetScrollInfo(&si);

	SCROLLINFO si2 = { 0 };
	si2.cbSize = sizeof(SCROLLBARINFO);
	si2.fMask = SIF_ALL;
	si2.nMax = 100;
	si2.nMin = 1;
	m_vs.SetScrollInfo(&si2);
	return TRUE;
}

CHorizonAndVertical::~CHorizonAndVertical()
{
}

void CHorizonAndVertical::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_hs);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_vs);


	DDX_Text(pDX, IDC_EDIT1, c_edittext);
}


BEGIN_MESSAGE_MAP(CHorizonAndVertical, CDialogEx)
//	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CHorizonAndVertical::OnNMThemeChangedScrollbar1)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, &CHorizonAndVertical::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHorizonAndVertical 消息处理程序


//void CHorizonAndVertical::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// 该功能要求使用 Windows XP 或更高版本。
//	// 符号 _WIN32_WINNT 必须 >= 0x0501。
//	// TODO:  在此添加控件通知处理程序代码
//	*pResult = 0;
//}



void CHorizonAndVertical::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//nSBCode 消息类型
	//nPos 鼠标拖到的位置
	//pScroolBar 滚动条指针
	SCROLLINFO si = { 0 };
	si.cbSize = sizeof(SCROLLBARINFO);
	si.fMask = SIF_ALL;
	pScrollBar->GetScrollInfo(&si);
	int nNewPos = si.nPos;
	switch (nSBCode)
	{
	case SB_THUMBTRACK://鼠标拖动滚动条的消息
		nNewPos = nPos;
		break;
	case SB_LINERIGHT://鼠标点击左边小箭头的消息
		nNewPos += 1;
		break;
	case SB_LINELEFT://鼠标点击右边小箭头的消息
		nNewPos -= 1;
		break;
	case SB_PAGERIGHT://鼠标点击滚动条右边的消息
		nNewPos += 1;
		break;
	case SB_PAGELEFT://鼠标点击滚动条左边的消息
		nNewPos -= 1;
		break;
	default:
		break;
	}
	CString str;
	str.Format(_T("当前位置%d"), nNewPos);
	GetDlgItem(IDC_TET_STATIC)->SetWindowText(str);
	pScrollBar->SetScrollPos(nNewPos,TRUE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CHorizonAndVertical::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SCROLLINFO si = { 0 };
	si.cbSize = sizeof(SCROLLBARINFO);
	si.fMask = SIF_ALL;
	pScrollBar->GetScrollInfo(&si);
	int nNewPos = si.nPos;
	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		nNewPos = nPos;
		break;
	case SB_LINEDOWN://鼠标点击下边小箭头的消息
		nNewPos += 1;
		break;
	case SB_LINEUP://鼠标点击上边小箭头的消息
		nNewPos -= 1;
		break;
	case SB_PAGEDOWN:////鼠标点击滚动条下边的消息
		nNewPos += 1;
		break;
	case SB_PAGEUP://鼠标点击滚动条上边的消息
		nNewPos -= 1;
		break;
	default:
		break;
	}

	pScrollBar->SetScrollPos(nNewPos);
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CHorizonAndVertical::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	UpdateData(TRUE);
	if (c_edittext.IsEmpty())
	{
		str = "数据为空";
		MessageBox(str);
		return;
	}
	int i = _ttoi(c_edittext);
	m_hs.SetScrollPos(i);
}
