// MySQLDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MySQLDialog.h"
#include "afxdialogex.h"
#pragma comment(lib, "libmysql.lib")

// CMySQLDialog �Ի���

IMPLEMENT_DYNAMIC(CMySQLDialog, CDialogEx)

CMySQLDialog::CMySQLDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMySQLDialog::IDD, pParent)
{

}

CMySQLDialog::~CMySQLDialog()
{
}

void CMySQLDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMySQLDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMySQLDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMySQLDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMySQLDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMySQLDialog ��Ϣ�������


void CMySQLDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);
	
	if (mysql_real_connect(&mysql, "localhost", "root", "root", "test", 3306, NULL, 0))
	{
		AfxMessageBox(_T("���ݿ����ӳɹ�"));
		mysql_close(&mysql);
		return;
	}
	AfxMessageBox(_T("���ݿ�����ʧ��"));
}

// wchar_t to string
void Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte������
	char *psText;  // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte���ٴ�����
	szDst = psText;// std::string��ֵ
	delete[]psText;// psText�����
}

void CMySQLDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);

	if (mysql_real_connect(&mysql, "localhost", "root", "root", "test", 3306, NULL, 0))
	{
		//AfxMessageBox(_T("���ݿ����ӳɹ�"));
		list<student> lists;
		list<student>::iterator listitr;
		MYSQL_RES *results;
		MYSQL_ROW record;
		mysql_query(&mysql, "select * from student;");
		results = mysql_store_result(&mysql);
		//cout << "table size :" << (unsigned long)mysql_num_rows(results);
		if (!results)
		{
			AfxMessageBox(_T("��ѯʧ��"));
			return;
		}
		while (record = mysql_fetch_row(results)) {
			student *stu = new student;
			stu->id = atoi(record[0]);

			string name = record[1];
			int len = name.length();
			len = ::MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, NULL, 0);
			wchar_t *pUnicode = new wchar_t[len + 1];
			memset(pUnicode, 0, (len + 1)*sizeof(wchar_t));
			::MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, (LPWSTR)pUnicode, len);
			Wchar_tToString(stu->name,pUnicode);
			stu->age = atoi(record[2]);
			//stu->gender = record[3];
			lists.push_back(*stu);
		}
		mysql_close(&mysql);
		CString str = _T("���ݱ����ݸ�����");
		string name1 = lists.begin()->name;
		CString str1(name1.c_str());
		str = str + str1;
		AfxMessageBox(str);
		return;
	}
	AfxMessageBox(_T("���ݿ�����ʧ��"));
}


void CMySQLDialog::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);

	if (mysql_real_connect(&mysql, "localhost", "root", "root", "test", 3306, NULL, 0))
	{
		//AfxMessageBox(_T("���ݿ����ӳɹ�"));
		/*char *insertsql = new char[200];
		string yu = "INSERT INTO student(name,age,gender) value('%s','%s','%s')";
		int len = yu.length();
		sprintf_s(insertsql,yu.length()+1 ,"tianxia", "12", 'm');*/
		char *insertsql = "INSERT INTO student(name,age,gender) value('tianxia','18','m')";
		int res = mysql_real_query(&mysql, insertsql, (unsigned long)strlen(insertsql));
		cout << "��������" << res << endl;
		mysql_close(&mysql);
		return;
	}
	AfxMessageBox(_T("���ݿ�����ʧ��"));
}
