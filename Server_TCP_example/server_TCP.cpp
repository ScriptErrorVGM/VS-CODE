// ������ �������� TCP � ��� �������

  #include <stdio.h>
  #include <winsock2.h>  // Wincosk2.h ������ ���� 
          // ��������� ������ windows.h!
  #include <windows.h>
  //����������� ���������� � �������
  #pragma comment(lib, "ws2_32.lib")
  #define MY_PORT    666
           // ����, ������� ������� ������

  // ������ ��� ������ ���������� ��������
  // ������������� 
  #define PRINTNUSERS if (nclients)\
  printf("%d user on-line\n",nclients);\
  else printf("No User on line\n");

  // �������� �������, �������������
  // �������������� �������������
  DWORD WINAPI SexToClient(LPVOID client_socket);

  // ���������� ���������� � ����������
  // �������� ������������� 
  int nclients = 0;

  int main(int argc, char* argv[])
  {
    char buff[1024];    // ����� ��� ��������� ����

    printf("TCP SERVER DEMO\n");

    // ��� 1 - ������������� ���������� �������
    // �.�. ������������ �������� ����������
    // �� ������������ �� ���������� ��������� ��
    // ������� �����, �������������
    // � ���������  �� ��������� WSADATA.
    // ����� ����� ��������� ���������� ����
    // ����������, ������, ����� ������ ���� �� �����
    // ������������ �������� (��������� WSADATA
    // �������� 400 ����)
    if (WSAStartup(0x0202,(WSADATA *) &buff[0])) 
    {
      // ������!
	      printf("Error WSAStartup %d\n",
             WSAGetLastError());
      return -1;
    }

    // ��� 2 - �������� ������
    SOCKET mysocket;
    // AF_INET     - ����� ���������
    // SOCK_STREAM  - ��������� ����� (�
    //      ���������� ����������)
    // 0      - �� ��������� ���������� TCP ��������
    if ((mysocket=socket(AF_INET,SOCK_STREAM,0))<0)
    {
      // ������!
      printf("Error socket %d\n",WSAGetLastError());
      WSACleanup();
        // �������������� ���������� Winsock
      return -1;
    }

    // ��� 3 ���������� ������ � ��������� �������
    sockaddr_in local_addr;
    local_addr.sin_family=AF_INET;
    local_addr.sin_port=htons(MY_PORT);
             // �� �������� � ������� �������!!!
    local_addr.sin_addr.s_addr=0;
             // ������ ��������� �����������
             // �� ��� IP-������

    // �������� bind ��� ����������
    if (bind(mysocket,(sockaddr *) &local_addr,
                sizeof(local_addr)))
    {
      // ������
      printf("Error bind %d\n",WSAGetLastError());
      closesocket(mysocket);  // ��������� �����!
      WSACleanup();
      return -1;
    }

    // ��� 4 �������� �����������
    // ������ ������� � 0x100
    if (listen(mysocket, 0x100))
    {
      // ������
      printf("Error listen %d\n",WSAGetLastError());
      closesocket(mysocket);
      WSACleanup();
      return -1;
    }

    printf("�������� �����������\n");

    // ��� 5 ��������� ��������� �� �������
    SOCKET client_socket;    // ����� ��� �������
    sockaddr_in client_addr;    // ����� �������
              // (����������� ��������)

    // ������� accept ���������� �������� ������
    // ���������
    int client_addr_size=sizeof(client_addr);

    // ���� ���������� �������� �� ����������� ��
    // �������
    while((client_socket=accept(mysocket, (sockaddr *)
            &client_addr, &client_addr_size)))
    {
      nclients++;      // ����������� �������
              // �������������� ��������

      // �������� �������� ��� �����
      HOSTENT *hst;
      hst=gethostbyaddr((char *)
          &client_addr.sin_addr.s_addr,4, AF_INET);

      // ����� �������� � �������
      printf("+%s [%s] new connect!\n",
      (hst)?hst->h_name:"",
      inet_ntoa(client_addr.sin_addr));
      PRINTNUSERS

      // ����� ������ ������ ��� ����������� �������
      // ��, ��� ����� ������������� ������������
      // _beginthreadex ��, ��������� ������� �����
      // ������� ����������� �� ���������� ����� ��
      // ������, ����� �������� � CreateThread
      DWORD thID;
      CreateThread(NULL,0,SexToClient,
              &client_socket,0,&thID);
    }
    return 0;
  }

  // ��� ������� ��������� � ��������� ������ �
  // ���������� ���������� ��������������� �������
  // ���������� �� ���������
  DWORD WINAPI SexToClient(LPVOID client_socket)
  {
    SOCKET my_sock;
    my_sock=((SOCKET *) client_socket)[0];
    char buff[20*1024];
    #define sHELLO "Hello, Sailor\r\n"

    // ���������� ������� ����������� 
    send(my_sock,sHELLO,sizeof(sHELLO),0);

    // ���� ���-�������: ����� ������ �� ������� �
    // ����������� �� �������
    while( int bytes_recv=
                 recv(my_sock,&buff[0],sizeof(buff),0)
              && bytes_recv !=SOCKET_ERROR)
      send(my_sock,&buff[0],bytes_recv,0);

    // ���� �� �����, �� ��������� ����� �� ����� ��
    // ������� ���������� �������� recv ������ �
    // ���������� �������� ���������
    nclients--; // ��������� ������� �������� ��������
    printf("-disconnect\n"); PRINTNUSERS

    // ��������� �����
    closesocket(my_sock);
    return 0;
  }
