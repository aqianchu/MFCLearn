#pragma once


// CSpyDialog �Ի���

class CSpyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSpyDialog)

public:
	CSpyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSpyDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	HICON m_hIcon;
	HCURSOR m_hCursor;//�������
	BOOL m_bCapturing;//��¼���״̬
	HWND m_hWndDest;//���ھ��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
