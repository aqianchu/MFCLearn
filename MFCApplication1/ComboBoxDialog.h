#pragma once
#include "afxwin.h"


// CComboBoxDialog �Ի���

class CComboBoxDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CComboBoxDialog)

public:
	CComboBoxDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CComboBoxDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox test_list;
	CComboBox test_combo;
	CEdit test_static_text;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
