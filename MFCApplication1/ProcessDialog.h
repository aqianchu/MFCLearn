#pragma once


// CProcessDialog �Ի���

class CProcessDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CProcessDialog)

public:
	CProcessDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProcessDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG17 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	HANDLE hProc;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
