#pragma once
#include <WinSock2.h>
#pragma comment(lib, "WS2_32")

class CInitSock
{//���� Winsock ��
public:
	CInitSock(BYTE minorVer = 2, BYTE majorVer = 2)
	{//��ʼ�� W32_32.dll
		WSADATA wsaData;
		WORD sockVersion = MAKEWORD(minorVer, majorVer);
		if (::WSAStartup(sockVersion, &wsaData) != 0)
		{
			exit(0);
		}
	}
	~CInitSock()
	{
		::WSACleanup();
	}
};