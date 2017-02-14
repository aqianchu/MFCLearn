
// GetScreenPixelDlg.h : ͷ�ļ�
//

#pragma once
#include "ColorStatic.h"
#include "PictureButton.h"


// CGetScreenPixelDlg �Ի���
class CGetScreenPixelDlg : public CDialogEx
{
// ����
public:
	CGetScreenPixelDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETSCREENPIXEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	boolean isFinish;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// λ��x
	int posx;
	// λ��y
	int posy;
	// ��ɫred
	int red;
	// ��ɫ��ɫGreen
	int green;
	// ��ɫ��ɫ
	int blue;
	// ������ʾ��ɫ
	CColorStatic m_colorState;
	// ���ڸ��Ǳ���
	CColorStatic m_background;
	// �����ҵ���ҳ
	CPictureButton m_linkMe;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
