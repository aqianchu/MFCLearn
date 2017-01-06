#pragma once


// CScreenCapDialog 对话框

class CScreenCapDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CScreenCapDialog)

public:
	CScreenCapDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScreenCapDialog();
	void Screen(char filename[]);
// 对话框数据
	enum { IDD = IDD_DIALOG23 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
