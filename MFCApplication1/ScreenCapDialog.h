#pragma once


// CScreenCapDialog �Ի���

class CScreenCapDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CScreenCapDialog)

public:
	CScreenCapDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScreenCapDialog();
	void Screen(char filename[]);
// �Ի�������
	enum { IDD = IDD_DIALOG23 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
