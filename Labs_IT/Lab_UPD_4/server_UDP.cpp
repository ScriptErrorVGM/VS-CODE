  #include <stdio.h>
  #include <winsock2.h>
  #pragma comment(lib, "ws2_32.lib")

  #define PORT 666   
  
  int main(int argc, char* argv[])
  {
    char buff[1024];

    printf("UDP DEMO echo-Server\n");

    if (WSAStartup(0x202,(WSADATA *) &buff[0]))
    {
      printf("WSAStartup error: %d\n",
             WSAGetLastError());
      return -1;
    }

    SOCKET my_sock;
    my_sock=socket(AF_INET,SOCK_DGRAM,0);
    if (my_sock==INVALID_SOCKET)
    {
      printf("Socket() error: %d\n",WSAGetLastError());
      WSACleanup();
      return -1;
    }

    sockaddr_in local_addr;
    local_addr.sin_family=AF_INET;
    local_addr.sin_addr.s_addr=INADDR_ANY;
    local_addr.sin_port=htons(PORT);

    if (bind(my_sock,(sockaddr *) &local_addr,
        sizeof(local_addr)))
    {
      printf("bind error: %d\n",WSAGetLastError());
      closesocket(my_sock);
      WSACleanup();
      return -1;
    }

    while(1)
    {
      sockaddr_in client_addr;
      int client_addr_size = sizeof(client_addr);
      int bsize=recvfrom(my_sock,&buff[0],
        sizeof(buff)-1,0,
        (sockaddr *) &client_addr, &client_addr_size);
      if (bsize==SOCKET_ERROR)
      printf("recvfrom() error: %d\n",
             WSAGetLastError());

      HOSTENT *hst;
      hst=gethostbyaddr((char *)
            &client_addr.sin_addr,4,AF_INET);
      printf("+%s new DATAGRAM!\n",
      (hst)?hst->h_name:"Unknown host",
      inet_ntoa(client_addr.sin_addr),
      ntohs(client_addr.sin_port));

      buff[bsize]=0;

      printf("From [%s:%d]:%s\n",inet_ntoa(client_addr.sin_addr),
      ntohs(client_addr.sin_port), &buff[0]);

      printf("answer: ");fgets(&buff[0],sizeof(buff)-1,
             stdin);
      if (!strcmp(&buff[0],"exit\n")) break;

      sendto(my_sock,&buff[0],strlen(&buff[0]),0,
        (sockaddr *)&client_addr, sizeof(client_addr));
    }
    return 0;
  }