#pragma once


// CThreadDialog �Ի���

class CThreadDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CThreadDialog)

public:
	CThreadDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CThreadDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG16 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
