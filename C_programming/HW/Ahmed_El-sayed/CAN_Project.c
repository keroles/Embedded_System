#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define packet_no (_msize(pp_packet[ID_Value-1])/sizeof(struct packet))-1
#define packet_count(x) (_msize(pp_packet[x])/sizeof(struct packet))

void packet_config(struct packet **pp_Packet);
void View_Packets(struct packet **pp_packet);

struct packet{
	int ID_Type,ID_Value;
	char DLC;
	char *Data;
};

void main(){

	struct packet **pp_packet;
	int i,option= 0;
	pp_packet = (struct packet **)malloc(3*sizeof(struct packet *));
	for(i=0;i<3;i++){
		pp_packet[i]=(struct packet *)malloc(0);
	}
	while(option != 1 || option != 2 || option != 3){
		printf("Choose one of the following option: \n");
		printf("1- Add a packet \n");
		printf("2- View packets \n");
		printf("3- Terminate Program \n");
		printf("\nYour Choice: ");
		scanf(" %d",&option);
		
		if(option == 1){
			packet_config(pp_packet);
		}
		else if (option == 2){
			View_Packets(pp_packet);
			printf("\n");
		}
		else if(option == 3){
			printf("\nThank you for using this program.\n");
			break;
		}
		else{
			printf("Error!! Enter a valid option\n");
		}
	}
	system("pause");
}

void packet_config(struct packet **pp_packet){
	
	int ID_Value = 0,i;
	while(ID_Value != 1 && ID_Value != 2 && ID_Value != 3){
		printf("\nEnter ID Value: \n");
		printf("1-Air Conditioner\n");
		printf("2-Left Door Lock\n");
		printf("3-Right Door Lock\n");
		printf("\nYour Choice: ");
		scanf(" %d",&ID_Value);
		if(ID_Value != 1 && ID_Value != 2 && ID_Value != 3){
			printf("ERROR!! Enter a valid ID Value\n");
		}
	}
	
	pp_packet[ID_Value-1]=(struct packet*)realloc(pp_packet[ID_Value-1],_msize(pp_packet[ID_Value-1])+sizeof(struct packet));
	pp_packet[ID_Value-1][packet_no].ID_Value = ID_Value;
	pp_packet[ID_Value-1][packet_no].ID_Type = 5;
	while(pp_packet[ID_Value-1][packet_no].ID_Type != 0 && pp_packet[ID_Value-1][packet_no].ID_Type != 1){
		printf("\nEnter ID Type (0 for normal & 1 for external): ");
		scanf(" %d",&pp_packet[ID_Value-1][packet_no].ID_Type);
		if(pp_packet[ID_Value-1][packet_no].ID_Type != 0 && pp_packet[ID_Value-1][packet_no].ID_Type != 1){
			printf("ERROR!! Enter a valid ID Type\n");
		}
	}
	pp_packet[ID_Value-1][packet_no].DLC = 8;
	while(pp_packet[ID_Value-1][packet_no].DLC < 0 || pp_packet[ID_Value-1][packet_no].DLC > 7 ){
		printf("\nEnter Length of Data (Maximum 7): ");
		scanf(" %d",&pp_packet[ID_Value-1][packet_no].DLC);
		if(pp_packet[ID_Value-1][packet_no].DLC < 0 || pp_packet[ID_Value-1][packet_no].DLC > 7){
			printf("ERROR!! Enter a valid Data Length\n");
		}
	}
	
	pp_packet[ID_Value-1][packet_no].Data = (char *)malloc(pp_packet[ID_Value-1][packet_no].DLC*sizeof(char));
	printf("\nEnter Data: ");
	scanf(" %s",pp_packet[ID_Value-1][packet_no].Data);
	printf("\n");
	
}
void View_Packets(struct packet **pp_packet){
	int i,j,k;
	if(_msize(pp_packet[0]) == 0){
		printf("\nThere is no Packets for Air Conditioner\n");
	}else{
		printf("\nAir Conditioner Packets: \n");
		for(i=0;i<packet_count(0);i++){
			printf("Packet no %d: \n\n",i+1);
			printf("ID Type           ID Value            DLC                         Data\n");
			printf("==============================================================================================\n");
			printf("%3d   ||%3d   |%3d   |%3d   |%3d  ||%3d   ||",pp_packet[0][i].ID_Type,0,0,2,0,pp_packet[0][i].DLC);
			for(j=0;j<pp_packet[0][i].DLC;j++){
				printf("%3c   |",pp_packet[0][i].Data[j]);
			}
			for(k=0;k<7-j;j++){
				printf("%3d   |",0);
			}
			printf("|\n");
			printf("==============================================================================================\n");
		}
	}
	if(_msize(pp_packet[1]) == 0){
		printf("\nThere is no Packets for Left Door Lock\n");
	}else{
		printf("\nLeft Door Lock Packets: \n");
		for(i=0;i<packet_count(1);i++){
			printf("Packet no %d: \n\n",i+1);
			printf("ID Type           ID Value            DLC                         Data\n");
			printf("==============================================================================================\n");
			printf("%3d   ||%3d   |%3d   |%3d   |%3d  ||%3d   ||",pp_packet[1][i].ID_Type,0,0,8,0,pp_packet[1][i].DLC);
			for(j=0;j<pp_packet[1][i].DLC;j++){
				printf("%3c   |",pp_packet[1][i].Data[j]);
			}
			for(k=0;k<7-j;j++){
				printf("%3d   |",0);
			}
			printf("|\n");
			printf("==============================================================================================\n");
		}
	}
	if(_msize(pp_packet[2]) == 0){
		printf("\nThere is no Packets for Right Door Lock\n");
	}else{
		printf("\nRight Door Lock Packets: \n");
		for(i=0;i<packet_count(2);i++){
			printf("Packet no %d: \n\n",i+1);
			printf("ID Type           ID Value            DLC                         Data\n");
			printf("==============================================================================================\n");
			printf("%3d   ||%3d   |%3d   |%3d   |%3d  ||%3d   ||",pp_packet[2][i].ID_Type,0,1,1,0,pp_packet[2][i].DLC);
			for(j=0;j<pp_packet[2][i].DLC;j++){
				printf("%3c   |",pp_packet[2][i].Data[j]);
			}
			for(k=0;k<7-j;j++){
				printf("%3d   |",0);
			}
			printf("|\n");
			printf("==============================================================================================\n");
		}
	}
}