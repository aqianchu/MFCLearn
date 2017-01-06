#pragma once


// CComputerDialog 对话框

class CComputerDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CComputerDialog)

public:
	CComputerDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CComputerDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG24 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	float number1;
	float number2;
	CString _operator;
	double result;
	afx_msg void OnBnClickedButton2();
};
