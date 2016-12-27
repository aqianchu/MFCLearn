#pragma once
#include "afxcmn.h"


// CTimeDialog 对话框

class CTimeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTimeDialog)

public:
	CTimeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTimeDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CProgressCtrl m_Progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
