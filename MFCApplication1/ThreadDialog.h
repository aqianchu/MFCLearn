#pragma once


// CThreadDialog 对话框

class CThreadDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CThreadDialog)

public:
	CThreadDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CThreadDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG16 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
