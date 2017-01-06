// SocketServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#pragma  comment(lib,"WS2_32.lib") //动态载入WS2_32.lib

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	WSAData data; //http://baike.baidu.com/view/2297317.htm
	WORD wVersionRqueested = MAKEWORD(2, 0);//http://baike.baidu.com/view/1385564.htm
	::WSAStartup(wVersionRqueested, &data);

	SOCKET s;
	s = ::socket(AF_INET, SOCK_STREAM, 0);//创建socket句柄

	sockaddr_in addr;//地址结构
	addr.sin_family = AF_INET;//协议
	addr.sin_port = htons(666);//端口
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//ip
	if (!::bind(s, (sockaddr*)&addr, sizeof(addr)))//绑定端口
		printf("绑定成功\n");
	else
	{
		printf("绑定失败\n");
		return 0;
	}

	::listen(s, 5);//监听端口
	sockaddr_in ClientAddr;
	int len = sizeof(ClientAddr);
	while (true)
	{
		//不知为何，在调试模式下可以连接。但是正式环境下不行
		SOCKET s1 = ::accept(s, (sockaddr*)&ClientAddr, &len);//接受连接
	//	Sleep(50);
		if (s1 != 0)
		{
			printf("%s 已连接\r\n", ClientAddr.sin_addr.S_un.S_addr);
			char buf[] = "欢迎连接！\r\n";
			if (::send(s1, buf, sizeof(buf), 0))//发送数据
				printf("发送数据成功\n");
			::closesocket(s1);//关闭socket句柄
		}
	}
	::closesocket(s);
	return 0;
}
