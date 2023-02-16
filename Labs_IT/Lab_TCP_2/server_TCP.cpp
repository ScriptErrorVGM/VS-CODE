#include <stdio.h>
#include <winsock2.h>
#include <locale.h>
#include <windows.h>

#pragma comment(lib,"ws2_32.lib")
#define MY_PORT 666

#define PRINTNUSERS if (nclients)\
printf("%d user on-line\n",nclients);\
else printf("No User on line\n");

DWORD WINAPI SexToClient(LPVOID client_socket);

int nclients = 0;

int main(int argc, char* argv[])
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buff[1024];

    printf("TCP SERVER DEMO\n");

    if(WSAStartup(0x0202,(WSADATA *) &buff[0]))
    {
        printf("Error WSAStartup %d\n", WSAGetLastError());
        return -1;
    }

    SOCKET mysocket;

    if ((mysocket = socket(AF_INET,SOCK_STREAM,0)) < 0)
    {
        printf("Error socket %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(MY_PORT);
    local_addr.sin_addr.s_addr = 0;

    if (bind(mysocket,(sockaddr *) &local_addr, sizeof(local_addr)))
    {
        printf("Error bind %d\n", WSAGetLastError());
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    if (listen(mysocket, 0x100))
    {
        printf("Error listen %d\n", WSAGetLastError());
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    printf("Waiting for connections\n");

    SOCKET client_socket;
    sockaddr_in client_addr;

    int client_addr_size = sizeof(client_addr);

    while((client_socket = accept(mysocket, (sockaddr *) &client_addr,
            &client_addr_size)))
    {
        nclients++;

        HOSTENT *hst;
        hst = gethostbyaddr((char *) &client_addr.sin_addr.s_addr,4, AF_INET);

        printf("+%s [%s:%d] new connect!\n", (hst)?hst->h_name:"",
        inet_ntoa(client_addr.sin_addr), htons(client_addr.sin_port));
        PRINTNUSERS

        DWORD thID;
        CreateThread(NULL,0,SexToClient, &client_socket,0, &thID);
    }
    return 0;
}

DWORD WINAPI SexToClient(LPVOID client_socket)
{
    SOCKET my_sock;
    sockaddr_in client_a;
    int client_a_size = sizeof(client_a);
    my_sock = ((SOCKET *) client_socket)[0];
    getpeername(my_sock, (sockaddr *) &client_a,&client_a_size);

    char buff[20*1024];
    #define sHELLO "Hello, SALIOR\r\n"

    send(my_sock,sHELLO,sizeof(sHELLO),0);

    int bytes_recv = 0;
    while((bytes_recv = recv(my_sock,&buff[0],sizeof(buff)-1,0)) 
                    && bytes_recv != SOCKET_ERROR)
    {   
        buff[bytes_recv]=0;
        
        printf("[%s:%d] Message from client: %s",
        inet_ntoa(client_a.sin_addr), htons(client_a.sin_port),buff);

        printf("Answer: "); fgets(&buff[0], sizeof(buff)-1, stdin);
        send(my_sock,&buff[0],strlen(buff),0);
    }
    nclients--;
    printf("-disconnect\n"); PRINTNUSERS
    closesocket(my_sock);
    return 0;

}
