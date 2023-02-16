  #include <stdio.h>
  #include <string.h>
  #include <winsock2.h>
  #include <windows.h>
  #pragma comment(lib, "ws2_32.lib")


  int main(int argc, char* argv[])
  {
    char buff[10*1014]={"0 "};
    char SERVERADDR[64];
    char PortStart[64], *end1; 
    char PortFin[64], *end2;

    printf("IP Server: ");
    fgets(&SERVERADDR[0], sizeof(SERVERADDR)-1, stdin);
    printf("Enter Start Port: ");
    fgets(PortStart, sizeof(PortStart)-1, stdin);
    printf("Enter Finish Port: ");
    fgets(PortFin, sizeof(PortFin)-1, stdin);

    int pStart = strtol(PortStart, &end1, 10);
    int pFin = strtol(PortFin, &end2, 10);

    if (WSAStartup(0x202,(WSADATA *)&buff[0]))
    {
      printf("WSAStartup error: %d\n",
             WSAGetLastError());
      return -1;
    }

    SOCKET my_sock=socket(AF_INET, SOCK_DGRAM, 0);
    if (my_sock==INVALID_SOCKET)
    {
      printf("socket() error: %d\n",WSAGetLastError());
      WSACleanup();
      return -1;
    }

    HOSTENT *hst;
    sockaddr_in dest_addr;

    dest_addr.sin_family=AF_INET;

    if (inet_addr(SERVERADDR))
      dest_addr.sin_addr.s_addr=inet_addr(SERVERADDR);
    else
      if (hst=gethostbyname(SERVERADDR))
        dest_addr.sin_addr.s_addr=((unsigned long **)
              hst->h_addr_list)[0][0];
    else
      {
        printf("Unknown host: %d\n",WSAGetLastError());
        closesocket(my_sock);
        WSACleanup();
        return -1;
      }

    int timeout = 100, bread;
	  bread = setsockopt(my_sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
    if(bread == SOCKET_ERROR)
    {
      printf("failed to set recv timeout: %d\n",GetLastError());
    }
    
    int len, n;
    for(int PORT=pStart; PORT<=pFin; PORT++)
    {
      dest_addr.sin_port=htons(PORT);

      sendto(my_sock,&buff[0],strlen(&buff[0]),0,
        (sockaddr *) &dest_addr,sizeof(dest_addr));

      len = sizeof(dest_addr);
      n=recvfrom(my_sock,&buff[0],sizeof(buff)-1,0,
        (sockaddr *) &dest_addr, &len);

      if (n==SOCKET_ERROR)
      {
        if(WSAGetLastError()==10054) continue;
        else if(WSAGetLastError()==10060) printf("PORT %d OPEN\n",PORT);
        else printf("PORT %d error:%d\n",PORT, WSAGetLastError());
      }
      else printf("PORT %d OPEN\n",PORT);
 
    }
    
    closesocket(my_sock);
    WSACleanup();
    
    fgets(&SERVERADDR[0], sizeof(SERVERADDR)-1, stdin);
    return 0;
  }