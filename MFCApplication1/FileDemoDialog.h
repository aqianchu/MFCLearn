#pragma once


// CFileDemoDialog 对话框

class CFileDemoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFileDemoDialog)

public:
	CFileDemoDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFileDemoDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG20 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
