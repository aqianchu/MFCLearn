
// GetScreenPixelDlg.h : 头文件
//

#pragma once
#include "ColorStatic.h"
#include "PictureButton.h"


// CGetScreenPixelDlg 对话框
class CGetScreenPixelDlg : public CDialogEx
{
// 构造
public:
	CGetScreenPixelDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GETSCREENPIXEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	boolean isFinish;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 位置x
	int posx;
	// 位置y
	int posy;
	// 颜色red
	int red;
	// 颜色绿色Green
	int green;
	// 颜色蓝色
	int blue;
	// 用于显示颜色
	CColorStatic m_colorState;
	// 用于覆盖背景
	CColorStatic m_background;
	// 链接我的主页
	CPictureButton m_linkMe;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
