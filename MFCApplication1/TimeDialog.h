#pragma once
#include "afxcmn.h"


// CTimeDialog �Ի���

class CTimeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTimeDialog)

public:
	CTimeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTimeDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CProgressCtrl m_Progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
