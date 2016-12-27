// ListTestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ListTestDialog.h"
#include "afxdialogex.h"


// CListTestDialog �Ի���

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


// CListTestDialog ��Ϣ�������


void CListTestDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	if (str.GetLength() == 0)
	{
		AfxMessageBox(_T("�������ı�"));
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == NULL)
	{
		AfxMessageBox(_T("��ѡ��һ���ڵ�"));
		return;
	}
	HTREEITEM hParent = m_tree.GetParentItem(hItem);
	m_tree.DeleteItem(hItem);
	m_tree.SelectItem(hParent);
}


void CListTestDialog::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == NULL)
	{
		AfxMessageBox(_T("��ѡ��һ���ڵ�"));
		return;
	}
	CString strText;
	GetDlgItemText(IDC_EDIT1, strText);
	if (strText.GetLength() == 0)
	{
		AfxMessageBox(_T("������Ҫ�޸ĳ��ı�"));
		return;
	}
	m_tree.SetItemText(hItem, strText);
}


void CListTestDialog::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItem = m_tree.GetSelectedItem();
	CString strText = m_tree.GetItemText(hItem);
	SetDlgItemText(IDC_TESS_STATIC, strText);
	*pResult = 0;
}
