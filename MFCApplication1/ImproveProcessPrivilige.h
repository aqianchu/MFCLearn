#pragma once


// CImproveProcessPrivilige �Ի���
// �������Ȩ��

class CImproveProcessPrivilige : public CDialogEx
{
	DECLARE_DYNAMIC(CImproveProcessPrivilige)

public:
	CImproveProcessPrivilige(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CImproveProcessPrivilige();
	void RaisePrivileges();
// �Ի�������
	enum { IDD = IDD_DIALOG19 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
