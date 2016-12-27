#pragma once
#include "afxdtctl.h"


// CDateTestDialog 对话框

class CDateTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDateTestDialog)

public:
	CDateTestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDateTestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void CalcDate();
	void CalcTime();
	DECLARE_MESSAGE_MAP()
public:
	CDateTimeCtrl m_DateBegin;
	CDateTimeCtrl m_DateOver;
	CDateTimeCtrl m_TimeBegin;
	CDateTimeCtrl m_TimeOver;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker4(NMHDR *pNMHDR, LRESULT *pResult);
};
