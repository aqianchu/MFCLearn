#pragma once
#include "afxwin.h"


// CStatusDialog 对话框

class CStatusDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStatusDialog)

public:
	CStatusDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStatusDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	CStatusBar m_status;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit;
};
