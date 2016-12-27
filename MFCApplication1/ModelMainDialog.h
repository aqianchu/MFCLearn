#pragma once
#include "ModelTestDialog.h"
#include "NoModelTestDialog.h"
// CModelMainDialog 对话框

class CModelMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CModelMainDialog)

public:
	CModelMainDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModelMainDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
