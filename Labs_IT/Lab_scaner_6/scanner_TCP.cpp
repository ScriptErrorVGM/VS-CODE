#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <locale.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buff[1024];
    char SERVERADDR[64];
    printf("TCP scanner DEMO\n");
    char PortStart[64], *end1; 
    char PortFin[64], *end2;

    printf("Enter IP: ");
    fgets(&SERVERADDR[0], sizeof(SERVERADDR)-1, stdin);
    printf("Enter Start Port: ");
    fgets(PortStart, sizeof(PortStart)-1, stdin);
    printf("Enter Finish Port: ");
    fgets(PortFin, sizeof(PortFin)-1, stdin);

    int pStart = strtol(PortStart, &end1, 10);
    int pFin = strtol(PortFin, &end2, 10);

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
    

    // for(int PORT=78; PORT<=85; PORT++)
    // for(int PORT=49660; PORT<=49670; PORT++)
    for(int PORT=pStart; PORT<=pFin; PORT++)
    {
        dest_addr.sin_port = htons(PORT);
        if (connect(my_sock,(sockaddr *)&dest_addr,sizeof(dest_addr)))
        {   
            if(WSAGetLastError()==10061) printf("Port %d CLOSED\n",PORT);
            else printf("Connect to port %d, error %d\n",PORT,WSAGetLastError());
        }
        else {
            
            printf("Port %d OPEN\n",PORT);
            closesocket(my_sock);
            my_sock = socket(AF_INET,SOCK_STREAM,0);
            if (my_sock < 0)
            {
                printf("Socket() error %d\n", WSAGetLastError());
                return -1;
            }
        }
    }

    closesocket(my_sock);
    WSACleanup();
    fgets(&SERVERADDR[0], sizeof(SERVERADDR)-1, stdin);
    return 0;
}

