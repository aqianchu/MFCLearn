#pragma once
#include "afxcmn.h"


// CListTestDialog �Ի���

class CListTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CListTestDialog)

public:
	CListTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CListTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
