#pragma once
#include "afxdtctl.h"


// CDateTestDialog �Ի���

class CDateTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDateTestDialog)

public:
	CDateTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDateTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void CalcDate();
	void CalcTime();
	DECLARE_MESSAGE_MAP()
public:
	CDateTimeCtrl m_DateBegin;
	CDateTimeCtrl m_DateOver;
	CDateTimeCtrl m_TimeBegin;
	CDateTimeCtrl m_TimeOver;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker4(NMHDR *pNMHDR, LRESULT *pResult);
};
