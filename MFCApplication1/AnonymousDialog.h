#pragma once


// CAnonymousDialog �Ի���

class CAnonymousDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAnonymousDialog)

public:
	CAnonymousDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAnonymousDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
