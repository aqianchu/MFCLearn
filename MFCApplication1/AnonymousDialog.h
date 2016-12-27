#pragma once


// CAnonymousDialog 对话框

class CAnonymousDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAnonymousDialog)

public:
	CAnonymousDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAnonymousDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
