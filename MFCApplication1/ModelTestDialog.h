#pragma once


// CModelTestDialog �Ի���

class CModelTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CModelTestDialog)

public:
	CModelTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModelTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
