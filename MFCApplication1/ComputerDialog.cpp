// ComputerDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ComputerDialog.h"
#include "afxdialogex.h"


// CComputerDialog 对话框

IMPLEMENT_DYNAMIC(CComputerDialog, CDialogEx)

CComputerDialog::CComputerDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CComputerDialog::IDD, pParent)
	, number1(0)
	, number2(0)
	, _operator(_T(""))
	, result(0)
{

}

CComputerDialog::~CComputerDialog()
{
}

void CComputerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, number1);
	DDX_Text(pDX, IDC_EDIT3, number2);
	DDX_Text(pDX, IDC_EDIT2, _operator);
	DDV_MaxChars(pDX, _operator, 1);
	DDX_Text(pDX, IDC_EDIT4, result);
}


BEGIN_MESSAGE_MAP(CComputerDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CComputerDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CComputerDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CComputerDialog 消息处理程序


void CComputerDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str1, str2, str3;
	GetDlgItemText(IDC_EDIT1, str1);
	GetDlgItemText(IDC_EDIT2, str2);
	GetDlgItemText(IDC_EDIT3, str3);

	int number1, number2, result;
	number1 = _ttoi(str1);
	number2 = _ttoi(str3);
	if (str2 != _T(""))
	{
		if (str2 == _T("+"))
		{
			result = number1 + number2;
		}
		else if (str2 == _T("-"))
		{
			result = number1 - number2;
		}
		else if (str2 == _T("*"))
		{
			result = number1* number2;
		}
		else if (str2 == _T("/"))
		{
			result = number1 / number2;
		}
		else
		{
			MessageBox(_T("运算符输入有误！"));
		}
		str1.Format(_T("%d"), result);
		SetDlgItemText(IDC_EDIT4, str1);
	}

}


void CComputerDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if (_operator != _T(""))
	{
		if (_operator == _T("+"))
		{
			result = number1 + number2;
		}
		else if (_operator == _T("-"))
		{
			result = number1 - number2;
		}
		else if (_operator == _T("*"))
		{
			result = number1* number2;
		}
		else if (_operator == _T("/"))
		{
			result = number1 / number2;
		}
		else
		{
			MessageBox(_T("运算符输入有误!"));
		}
	}

	UpdateData(false);
}
