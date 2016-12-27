#pragma once
#include "afxwin.h"


// CHorizonAndVertical 对话框

class CHorizonAndVertical : public CDialogEx
{
	DECLARE_DYNAMIC(CHorizonAndVertical)

public:
	CHorizonAndVertical(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHorizonAndVertical();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_hs;
	CScrollBar m_vs;
//	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CString c_edittext;
	afx_msg void OnBnClickedButton1();
};
