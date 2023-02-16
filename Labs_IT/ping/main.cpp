/*\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
\\//\\//\\//\\//\\//\\//\\//\Lab #5/\\//\\//\\//\\//\\//\\//\\//
//\\//\\//\\//\\//\\/Pinger by Sachko Maxim\//\\//\\//\\//\\//\\
\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\*/
#include <iostream>
#include "icmp.h"

using namespace std;

int main(void)
{
//������������� WinSocket
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2,1),&WSAData) != 0)
	{
		printf("WSAStartup failed: %d\n",GetLastError());
	}
//��������� �����
	int sockRaw;
	/*������� "�����" ����� ��� ��� ����������� ����������*/
	sockRaw = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
	if(sockRaw == INVALID_SOCKET)
	{
		printf("WSASocket() failed: %d\n",GetLastError());
	}

//������������� ������� (� ������������) �� ����� ICMP ������ 
	int timeout = 1000, bread;
	bread = setsockopt(sockRaw, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
	if(bread == SOCKET_ERROR)
	{
		printf("failed to set recv timeout: %d\n",GetLastError());
		return false;
	}
//7. ��������������� �����. 
//***********************************************************************
	SOCKADDR_IN dest_sin, from_sin;		// ������ � ��������� � ��������� ������
	struct hostent *from_host;			// ��������� �������� ������ � �����
	char hname[64];						// ����-��� ���������� ����������
	int n;								// ����� ���������� �������

	// ���� ������
	cout << "Enter server host name  : ";
	cin >> hname;						// ������ ��� ��� ip-����� �����
	cout << "Enter namber of packets : ";
	cin >> n;							// ������ ���-�� ���������� �������

	//�������� ������������� ��������� ����-�����
	if((from_host = gethostbyname(hname))==NULL)
	{
		cout<<"host name error"<<endl;
		return 0;
	}

	ZeroMemory(&dest_sin, sizeof(dest_sin));	// �������� ������
	dest_sin.sin_addr.s_addr = ((struct in_addr *)from_host->h_addr_list[0])->s_addr;	// IP ������ �������
	dest_sin.sin_family = AF_INET;
// **********************************************************************
	char *icmp_data;
	icmp_data = (char *)malloc(MAX_PACKET);		// #include <stdlib.h>
	memset(icmp_data,0,MAX_PACKET);				// �������� ������

	IcmpHeader *icmp_hdr;						// ICMP ���������
	char *datapart;
	// ����������� ��������� �� char ��������� �� ICMP ���������
	icmp_hdr = (IcmpHeader*)icmp_data;
	// SOCK_RAW ICMP ���������
	icmp_hdr->i_type = ICMP_ECHO;					// ��� ������������� ���������
	icmp_hdr->i_code = 0;							// ��� ������������� ���������
	icmp_hdr->i_id = (USHORT)GetCurrentProcessId();	// � id ICMP ��������� ������� ����� �������� ��������
	icmp_hdr->i_cksum = 0;							// �������� �������� ����
	icmp_hdr->i_seq = 0;							// �������� ����� ICMP ���������

	datapart = icmp_data + sizeof(IcmpHeader);
	// ��������� ���-������ � ����� ��� ��������.
	int datasize;
	datasize = DEF_PACKET_SIZE;
	memset(datapart,'m', datasize - sizeof(IcmpHeader));

//8. ��������� ping. 
// **********************************************************
// ��������� ����
	USHORT seq_no = 0;						// ������� �������
	char *recvbuf;							// ����� ���������� ���������
	recvbuf = (char*)malloc(MAX_PACKET);	// �������� ������
	int iRecvLen;
	iRecvLen = sizeof(from_sin);
	int bwrote;
	int temp = 1;
	while(temp != 0)		// ���������� n-�� ���������� �������
	{
		// �������� ����������� ���� � ICMP ���������
		((IcmpHeader*)icmp_data)->i_cksum = 0;
		// �������� ���������� ���� ICMP ���������
		((IcmpHeader*)icmp_data)->timestamp = GetTickCount();
		((IcmpHeader*)icmp_data)->i_seq = seq_no++;
		// ��������� ����������� �����
		((IcmpHeader*)icmp_data)->i_cksum = checksum((USHORT*)icmp_data,datasize);
		
		// ������������� ������� TTL � IP ���������
		int TTL=1;
		// bwrote = setsockopt(sockRaw, IPPROTO_IP, IP_TTL, (const char*)&TTL, sizeof(TTL)); 

		// �������� �����
		bwrote = sendto(sockRaw,icmp_data,datasize,0,(struct sockaddr*)&dest_sin,sizeof(dest_sin));
		if(bwrote == SOCKET_ERROR)
		{
			if (GetLastError() == WSAETIMEDOUT)
			{
				printf("timed out\n");
				continue;
			}
			fprintf(stderr,"sendto failed: %d\n",GetLastError());
			return false;
		}
		if (bwrote < datasize)
		{
			fprintf(stdout,"Wrote %d bytes\n",bwrote);
		}
		// ��������� �����
		bread = recvfrom(sockRaw,recvbuf,MAX_PACKET,0,(struct sockaddr*)&from_sin,&iRecvLen);
		if (bread == SOCKET_ERROR)
		{
			if (GetLastError() == WSAETIMEDOUT)
			{
				printf("timed out\n");
				continue;
			}
			fprintf(stderr,"recvfrom failed: %d\n",GetLastError());
			return false;
		}
		// ��������� ���������� �����
		temp = decode_resp(recvbuf,bread,&from_sin);
		
		// ���� ���� �������...
		Sleep(1000);
		// ...����������
		TTL++;
	} 

//��������� ������.
	// ����������� ������
	free(icmp_data);
	free(recvbuf);
	// ��������� �����
	closesocket(sockRaw);
	// ����������� �� �������� :)
	cout << "Ping OK!" << endl << endl;
	cout << "Press ENTER to quit" << endl;
	cin.getline(hname,15);
	cin.getline(hname,15);
	return 0;
	// �� ���� ���!!!
}
