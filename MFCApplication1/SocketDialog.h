#pragma once


// CSocketDialog �Ի���

class CSocketDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSocketDialog)

public:
	CSocketDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSocketDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG22 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
