#pragma once
#include "afxwin.h"


// CNextTestDialog �Ի���

class CNextTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNextTestDialog)

public:
	CNextTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNextTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNextButton1();
	CButton check1;
	CButton check2;
	CButton check3;
	CButton radio1;
	int radio2;
};
