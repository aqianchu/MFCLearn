#pragma once


// CNoModelTestDialog 对话框

class CNoModelTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNoModelTestDialog)

public:
	CNoModelTestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNoModelTestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void PostNcDestroy();
	DECLARE_MESSAGE_MAP()
};
