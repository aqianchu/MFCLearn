#pragma once


// CNoModelTestDialog �Ի���

class CNoModelTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNoModelTestDialog)

public:
	CNoModelTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNoModelTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void PostNcDestroy();
	DECLARE_MESSAGE_MAP()
};
