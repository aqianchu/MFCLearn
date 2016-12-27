#pragma once


// CProcessDialog 对话框

class CProcessDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CProcessDialog)

public:
	CProcessDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProcessDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG17 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HANDLE hProc;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
