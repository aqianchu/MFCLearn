#pragma once


// CRegisterDialog �Ի���

class CRegisterDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDialog)

public:
	CRegisterDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
