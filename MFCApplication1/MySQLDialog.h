#pragma once
#include"winsock.h"
#include "mysql.h"
#include <iostream>
#include <string.h>
#include <list>   
#include <numeric>   
#include <algorithm>  
using namespace std;
// CMySQLDialog �Ի���

class student
{
public:
	int id;
	string name;
	int age;
	char gender;
};

class CMySQLDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMySQLDialog)

public:
	CMySQLDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMySQLDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG21 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
