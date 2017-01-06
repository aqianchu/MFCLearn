#pragma once


// CImproveProcessPrivilige 对话框
// 进程提高权限

class CImproveProcessPrivilige : public CDialogEx
{
	DECLARE_DYNAMIC(CImproveProcessPrivilige)

public:
	CImproveProcessPrivilige(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CImproveProcessPrivilige();
	void RaisePrivileges();
// 对话框数据
	enum { IDD = IDD_DIALOG19 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
