#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <locale.h>

#pragma comment(lib,"ws2_32.lib")
#define PORT 666

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buff[1024];
    char SERVERADDR[64];
    printf("TCP CLIENT DEMO\n");

    printf("IP Server: ");
    fgets(&SERVERADDR[0], sizeof(SERVERADDR)-1, stdin);

    if(WSAStartup(0x0202,(WSADATA *) &buff[0]))
    {
        printf("WSAStartup error %d\n", WSAGetLastError());
        return -1;
    }
    SOCKET my_sock;
    my_sock = socket(AF_INET,SOCK_STREAM,0);
    if (my_sock < 0)
    {
        printf("Socket() error %d\n", WSAGetLastError());
        return -1;
    }

    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    HOSTENT *hst;

    if (inet_addr(SERVERADDR) != INADDR_NONE)
        dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
    else
        if(hst = gethostbyname(SERVERADDR))
        ((unsigned long *)&dest_addr.sin_addr)[0] = 
            ((unsigned long **)hst->h_addr_list)[0][0];
        else
        {
            printf("Invlaid address %s\n",SERVERADDR);
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }
    
    if (connect(my_sock,(sockaddr *)&dest_addr,
                sizeof(dest_addr)))
    {
        printf("Connect error %d\n",WSAGetLastError());
        return -1;
    }

    printf("Connection to %s successfully established\n\
    Type quit for quit\n\n",SERVERADDR);

    int nsize;
    while(1)
    {
        nsize = recv(my_sock,&buff[0],sizeof(buff)-1,0);
        if(nsize == SOCKET_ERROR)
        {
            printf("Exit...");
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }
        buff[nsize] = 0;

        printf("S=>C: %s",buff);
        printf("S<=C: "); fgets(&buff[0],sizeof(buff)-1,stdin);

        if (!strcmp(&buff[0],"quit\n"))
        {
            printf("Exit...");
            closesocket(my_sock);
            WSACleanup();
            return 0;
        }

        send(my_sock,&buff[0],nsize,0);
    }
    printf("Recv error %d\n",WSAGetLastError());
    closesocket(my_sock);
    WSACleanup();
    return -1;
}

