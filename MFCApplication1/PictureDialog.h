#pragma once
#include "afxwin.h"


// CPictureDialog �Ի���

class CPictureDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDialog)

public:
	CPictureDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPictureDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	afx_msg void OnBnClickedButton1();
};
