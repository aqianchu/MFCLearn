#pragma once
#include "afxwin.h"


// CComboBoxDialog 对话框

class CComboBoxDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CComboBoxDialog)

public:
	CComboBoxDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CComboBoxDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox test_list;
	CComboBox test_combo;
	CEdit test_static_text;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
