
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "NextTestDialog.h"
#include "ComboBoxDialog.h"
#include "HorizonAndVertical.h"
#include "TimeDialog.h"
#include "ListTestDialog.h"
#include "DateTestDialog.h"
#include "StatusDialog.h"
#include "ModelMainDialog.h"
#include "PictureDialog.h"
#include "SpyDialog.h"
#include "RegisterDialog.h"
#include "GetSystemDialog.h"
#include "StartBootDialog.h"
#include "ThreadDialog.h"
#include "ProcessDialog.h"
#include "AnonymousDialog.h"

//�Զ�����Ϣ
#define WM_MY_DEFINE_MSG WM_USER + 0x1
// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit test_control;
	CString test_value;
	afx_msg void OnBnClickedTestButton4();
	afx_msg void OnBnClickedBandButton5();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedTiaoButton6();
	afx_msg void OnBnClickedComboListButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void On32771();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton4();
	//�Զ�����Ϣ
	afx_msg LRESULT OnMyMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMyMsg1(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
};
