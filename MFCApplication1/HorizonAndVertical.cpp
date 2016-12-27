// HorizonAndVertical.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "HorizonAndVertical.h"
#include "afxdialogex.h"


// CHorizonAndVertical �Ի���

IMPLEMENT_DYNAMIC(CHorizonAndVertical, CDialogEx)

CHorizonAndVertical::CHorizonAndVertical(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHorizonAndVertical::IDD, pParent)
	, c_edittext(_T(""))
{
	
}

BOOL CHorizonAndVertical::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//�ؼ��ͱ�����֮��
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


// CHorizonAndVertical ��Ϣ�������


//void CHorizonAndVertical::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
//	// ���� _WIN32_WINNT ���� >= 0x0501��
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}



void CHorizonAndVertical::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//nSBCode ��Ϣ����
	//nPos ����ϵ���λ��
	//pScroolBar ������ָ��
	SCROLLINFO si = { 0 };
	si.cbSize = sizeof(SCROLLBARINFO);
	si.fMask = SIF_ALL;
	pScrollBar->GetScrollInfo(&si);
	int nNewPos = si.nPos;
	switch (nSBCode)
	{
	case SB_THUMBTRACK://����϶�����������Ϣ
		nNewPos = nPos;
		break;
	case SB_LINERIGHT://��������С��ͷ����Ϣ
		nNewPos += 1;
		break;
	case SB_LINELEFT://������ұ�С��ͷ����Ϣ
		nNewPos -= 1;
		break;
	case SB_PAGERIGHT://������������ұߵ���Ϣ
		nNewPos += 1;
		break;
	case SB_PAGELEFT://�������������ߵ���Ϣ
		nNewPos -= 1;
		break;
	default:
		break;
	}
	CString str;
	str.Format(_T("��ǰλ��%d"), nNewPos);
	GetDlgItem(IDC_TET_STATIC)->SetWindowText(str);
	pScrollBar->SetScrollPos(nNewPos,TRUE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CHorizonAndVertical::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	case SB_LINEDOWN://������±�С��ͷ����Ϣ
		nNewPos += 1;
		break;
	case SB_LINEUP://������ϱ�С��ͷ����Ϣ
		nNewPos -= 1;
		break;
	case SB_PAGEDOWN:////������������±ߵ���Ϣ
		nNewPos += 1;
		break;
	case SB_PAGEUP://������������ϱߵ���Ϣ
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	UpdateData(TRUE);
	if (c_edittext.IsEmpty())
	{
		str = "����Ϊ��";
		MessageBox(str);
		return;
	}
	int i = _ttoi(c_edittext);
	m_hs.SetScrollPos(i);
}
