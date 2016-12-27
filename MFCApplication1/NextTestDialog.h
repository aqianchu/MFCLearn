#pragma once
#include "afxwin.h"


// CNextTestDialog 对话框

class CNextTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNextTestDialog)

public:
	CNextTestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNextTestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNextButton1();
	CButton check1;
	CButton check2;
	CButton check3;
	CButton radio1;
	int radio2;
};
