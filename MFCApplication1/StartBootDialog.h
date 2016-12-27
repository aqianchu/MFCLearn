#pragma once


// CStartBootDialog 对话框

class CStartBootDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStartBootDialog)

public:
	CStartBootDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStartBootDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
