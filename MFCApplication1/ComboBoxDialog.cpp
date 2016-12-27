// ComboBoxDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ComboBoxDialog.h"
#include "afxdialogex.h"


// CComboBoxDialog �Ի���

IMPLEMENT_DYNAMIC(CComboBoxDialog, CDialogEx)

CComboBoxDialog::CComboBoxDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CComboBoxDialog::IDD, pParent)
{

}

CComboBoxDialog::~CComboBoxDialog()
{
}

void CComboBoxDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, test_list);
	DDX_Control(pDX, IDC_COMBO1, test_combo);
	DDX_Control(pDX, IDC_EDIT1, test_static_text);
}


BEGIN_MESSAGE_MAP(CComboBoxDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CComboBoxDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CComboBoxDialog ��Ϣ�������


void CComboBoxDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	if (str.IsEmpty())
		return;
	test_list.AddString(str);
	test_combo.AddString(str);

	test_list.SetCurSel(0);
	test_combo.SetCurSel(0);
}


void CComboBoxDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = test_list.GetCurSel();
	test_list.DeleteString(index);

	index = test_combo.GetCurSel();
	test_combo.DeleteString(index);

	test_list.SetCurSel(0);
	test_combo.SetCurSel(0);
}
