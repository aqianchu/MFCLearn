#pragma once


// CSocketDialog 对话框

class CSocketDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSocketDialog)

public:
	CSocketDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSocketDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG22 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
