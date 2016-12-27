#pragma once
#include "afxwin.h"


// CPictureDialog 对话框

class CPictureDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDialog)

public:
	CPictureDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPictureDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	afx_msg void OnBnClickedButton1();
};
