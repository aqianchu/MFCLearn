#pragma once
#include "afxwin.h"


// CStatusDialog �Ի���

class CStatusDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStatusDialog)

public:
	CStatusDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStatusDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	CStatusBar m_status;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit;
};
