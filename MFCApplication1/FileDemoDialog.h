#pragma once


// CFileDemoDialog �Ի���

class CFileDemoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFileDemoDialog)

public:
	CFileDemoDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileDemoDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG20 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
