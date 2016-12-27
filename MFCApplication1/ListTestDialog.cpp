// ListTestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ListTestDialog.h"
#include "afxdialogex.h"


// CListTestDialog 对话框

IMPLEMENT_DYNAMIC(CListTestDialog, CDialogEx)

CListTestDialog::CListTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListTestDialog::IDD, pParent)
{

}

CListTestDialog::~CListTestDialog()
{
}

void CListTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}


BEGIN_MESSAGE_MAP(CListTestDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CListTestDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListTestDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CListTestDialog::OnBnClickedButton3)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CListTestDialog::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CListTestDialog 消息处理程序


void CListTestDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	if (str.GetLength() == 0)
	{
		AfxMessageBox(_T("请输入文本"));
		return;
	}
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == NULL)
	{
		hItem = TVI_ROOT;
	}
	TVINSERTSTRUCT ts = { 0 };
	ts.hParent = hItem;
	ts.hInsertAfter = TVI_LAST;
	ts.item.pszText = str.GetBuffer();
	ts.item.mask = TVIF_TEXT;

	HTREEITEM hNewItem = m_tree.InsertItem(&ts);
	m_tree.EnsureVisible(hNewItem);
}


void CListTestDialog::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == NULL)
	{
		AfxMessageBox(_T("请选择一个节点"));
		return;
	}
	HTREEITEM hParent = m_tree.GetParentItem(hItem);
	m_tree.DeleteItem(hItem);
	m_tree.SelectItem(hParent);
}


void CListTestDialog::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == NULL)
	{
		AfxMessageBox(_T("请选择一个节点"));
		return;
	}
	CString strText;
	GetDlgItemText(IDC_EDIT1, strText);
	if (strText.GetLength() == 0)
	{
		AfxMessageBox(_T("请输入要修改成文本"));
		return;
	}
	m_tree.SetItemText(hItem, strText);
}


void CListTestDialog::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	HTREEITEM hItem = m_tree.GetSelectedItem();
	CString strText = m_tree.GetItemText(hItem);
	SetDlgItemText(IDC_TESS_STATIC, strText);
	*pResult = 0;
}
