#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <WinSock2.h>
#include <iostream>


int main()
{

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET principalSocket;
	principalSocket = socket(AF_INET, 
							 SOCK_STREAM, 
							 IPPROTO_TCP);

	if (principalSocket == INVALID_SOCKET)
	{
		std::cout << "Ocorreu um erro ao "
				  << "criar o socket";
		return 1;
	}
	
	int r;

	sockaddr_in enderecoServidor;
	enderecoServidor.sin_addr.s_addr  = inet_addr("127.0.0.1");
	enderecoServidor.sin_family = AF_INET;
	enderecoServidor.sin_port = htons(9999);

	r = bind(principalSocket,
			(SOCKADDR*)&enderecoServidor,
			sizeof(sockaddr_in));


	r = listen(principalSocket, SOMAXCONN);


	closesocket(principalSocket);

	WSACleanup();
	return 0;
}