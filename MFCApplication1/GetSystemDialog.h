#pragma once


// CGetSystemDialog 对话框

class CGetSystemDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGetSystemDialog)

public:
	CGetSystemDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGetSystemDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
