#pragma once


// CGetSystemDialog �Ի���

class CGetSystemDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGetSystemDialog)

public:
	CGetSystemDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGetSystemDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
