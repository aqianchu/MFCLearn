#pragma once


// CStartBootDialog �Ի���

class CStartBootDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStartBootDialog)

public:
	CStartBootDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStartBootDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
