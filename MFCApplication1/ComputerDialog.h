#pragma once


// CComputerDialog �Ի���

class CComputerDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CComputerDialog)

public:
	CComputerDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CComputerDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG24 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	float number1;
	float number2;
	CString _operator;
	double result;
	afx_msg void OnBnClickedButton2();
};
