// SocketServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#pragma  comment(lib,"WS2_32.lib") //��̬����WS2_32.lib

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	WSAData data; //http://baike.baidu.com/view/2297317.htm
	WORD wVersionRqueested = MAKEWORD(2, 0);//http://baike.baidu.com/view/1385564.htm
	::WSAStartup(wVersionRqueested, &data);

	SOCKET s;
	s = ::socket(AF_INET, SOCK_STREAM, 0);//����socket���

	sockaddr_in addr;//��ַ�ṹ
	addr.sin_family = AF_INET;//Э��
	addr.sin_port = htons(666);//�˿�
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//ip
	if (!::bind(s, (sockaddr*)&addr, sizeof(addr)))//�󶨶˿�
		printf("�󶨳ɹ�\n");
	else
	{
		printf("��ʧ��\n");
		return 0;
	}

	::listen(s, 5);//�����˿�
	sockaddr_in ClientAddr;
	int len = sizeof(ClientAddr);
	while (true)
	{
		//��֪Ϊ�Σ��ڵ���ģʽ�¿������ӡ�������ʽ�����²���
		SOCKET s1 = ::accept(s, (sockaddr*)&ClientAddr, &len);//��������
	//	Sleep(50);
		if (s1 != 0)
		{
			printf("%s ������\r\n", ClientAddr.sin_addr.S_un.S_addr);
			char buf[] = "��ӭ���ӣ�\r\n";
			if (::send(s1, buf, sizeof(buf), 0))//��������
				printf("�������ݳɹ�\n");
			::closesocket(s1);//�ر�socket���
		}
	}
	::closesocket(s);
	return 0;
}
