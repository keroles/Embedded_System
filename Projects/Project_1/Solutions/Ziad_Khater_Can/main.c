#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef unsigned char u8;
typedef unsigned long u32;
typedef double u64;

struct packet
{
	u8 id_type;
	u32 id_value;
	u8 dlc;
	u64 data;
};

void send_packets(u32 id_dest ,u32 id_source, int no_of_packets , struct packet** ptpts)
{
	int i=0;

	for(i=0;i<no_of_packets;i++)
	{
		printf("id Type %d:",i+1);
		scanf("%d",&ptpts[id_source][i].id_type);
		ptpts[id_source][i].id_value=id_dest;
		printf("dlc %d:",i+1);
		scanf("%d",&ptpts[id_source][i].dlc);
		printf("data %d:",i+1);
		scanf("%lf",&ptpts[id_source][i].data);
		printf("\n");
	}

}
void print_packets(u32 id_dest ,u32 id_source, int no_of_packets , struct packet** ptpts)
{
	int i=0;
	printf("sending packets in progress\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	for(i=0;i<no_of_packets;i++)
	{	
		
		printf("\n%d\t",ptpts[id_source][i].id_type);
		switch (ptpts[id_source][i].id_value)
		{
		case 0: printf("0x20\t");
				break;
		case 1: printf("0x40\t");
				break;
		case 2: printf("0x80\t");
				break;
		}
		printf("%d\t",ptpts[id_source][i].dlc);
		printf("%lf\t\n",ptpts[id_source][i].data);
	}

}
void main()
{
	while (1)
	{
	struct packet** ptpts;
	u32 id_source;
	u32 id_dest;
	int i=0,j=0;
	int no_of_packets;
	printf("\n");
	printf("choose the source ID \n 0:0x20\n 1:0x40\n 2:0x80\n");
	scanf("%d",&id_source);
	printf("choose the destination ID \n 0:0x20\n 1:0x40\n 2:0x80\n");
	scanf("%d",&id_dest);
	ptpts=(struct packet**)malloc(3*sizeof(struct packet*));
	
	printf("how many packets will be sent\n");
	scanf("%d",&no_of_packets);
	while(i<3)
	{
	ptpts[i]=(struct packet*)malloc(no_of_packets * sizeof(struct packet));
	i++;
	}
	send_packets(id_dest,id_source,no_of_packets,ptpts);
	print_packets(id_dest,id_source,no_of_packets,ptpts);
	
	}	
}
