
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define ICMP_MIN 8                         
#define DEF_PACKET_SIZE 32 
#define MAX_PACKET 1024 
#define ICMP_ECHO 8 
#define ICMP_ECHOREPLY 0
#define ICMP_TTL 11 


typedef struct iphdr
{
	unsigned int h_len:4;          // length of the header
	unsigned int version:4;        // Version of IP 
	unsigned char tos;             // Type of service 
	unsigned short total_len;      // total length of the packet 
	unsigned short ident;          // unique identifier 
	unsigned short frag_and_flags; // flags 
	unsigned char  ttl; 
	unsigned char proto;           // protocol (TCP, UDP etc) 
	unsigned short checksum;       // IP checksum 
	
	unsigned int sourceIP; 
	unsigned int destIP; 
} IpHeader; 


typedef struct _ihdr
{
	BYTE i_type; 
	BYTE i_code;					//type sub code
	USHORT i_cksum; 
	USHORT i_id; 
	USHORT i_seq; 
// This is not the std header, but we reserve space for time
	ULONG timestamp;
} IcmpHeader; 


USHORT checksum(USHORT *, int); 
void decode_resp(char *,int ,struct sockaddr_in *); 


USHORT checksum(USHORT *buffer, int size)
{
	unsigned long cksum=0; 
	while(size >1) 
	{ 
		cksum+=*buffer++; 
		size -=sizeof(USHORT); 
	}
            if(size) 
            { 
				cksum += *(UCHAR*)buffer;
            } 
            cksum = (cksum >> 16) + (cksum & 0xffff); 
            cksum += (cksum >>16); 
            return (USHORT)(~cksum);
} 
 

int decode_resp(char *buf, int bytes, struct sockaddr_in *from)
{
	IpHeader *iphdr;			
	IcmpHeader *icmphdr;		
	unsigned short iphdrlen;	


	iphdr = (IpHeader *)buf;

	iphdrlen = iphdr->h_len * 4 ; 

	if (bytes  < iphdrlen + ICMP_MIN)	
	{
		printf("Too few bytes from %s\n",inet_ntoa(from->sin_addr));
	}
	
	icmphdr = (IcmpHeader*)(buf + iphdrlen);

	if (icmphdr->i_type == ICMP_TTL)	
	{
		printf("non-echo type %d recvd\n",(USHORT)GetCurrentProcessId());
		
	}
	else if (icmphdr->i_type != ICMP_ECHOREPLY)	
	{
		printf("non-echo type %d recvd\n",icmphdr->i_type);
		return 2;
	}
	if (icmphdr->i_id != (USHORT)GetCurrentProcessId())	
	{
		printf("someone else's packet!\n");
		return -1;
	}
	
	printf("%d bytes from %s:",bytes, inet_ntoa(from->sin_addr));
	printf(" icmp_seq = %d. ", icmphdr->i_seq);
	printf(" time: %d ms ",GetTickCount()-icmphdr->timestamp);
	printf("\n");
} 

