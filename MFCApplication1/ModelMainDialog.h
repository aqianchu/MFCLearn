#pragma once
#include "ModelTestDialog.h"
#include "NoModelTestDialog.h"
// CModelMainDialog �Ի���

class CModelMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CModelMainDialog)

public:
	CModelMainDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModelMainDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
