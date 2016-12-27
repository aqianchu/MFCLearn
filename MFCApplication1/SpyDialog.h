#pragma once


// CSpyDialog 对话框

class CSpyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSpyDialog)

public:
	CSpyDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSpyDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;
	HCURSOR m_hCursor;//鼠标光标句柄
	BOOL m_bCapturing;//记录鼠标状态
	HWND m_hWndDest;//窗口句柄
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
