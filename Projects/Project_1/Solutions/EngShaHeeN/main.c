#include "stdio.h"
#include "string.h"
#include "conio.h"

#define MAX_DATA_SIZE 7
#define MAX_ADDRESS_SIZE 4
#define nAddress 3 //number of ID_Values
/*
AC  : Air Condition
LDL : Left Door Lock
RDL : Right Door Lock
*/
enum NUMAddress {AC=1,LDL,RDL};
enum NUMType {normal=1,external};

struct SPacket{
    enum NUMType ID_type;
    enum NUMAddress ID_value;
    int DLC;
    char *pdata;
};
int npackets[nAddress]={0}; //number of packets in each Address
char string_address[nAddress][2*MAX_ADDRESS_SIZE] = {"0|0|2|0","0|0|8|0","0|1|1|0"};
void Append_packet(struct SPacket **db);
void Encap(struct SPacket **db);


void main(){
    int i; 
    struct SPacket **pCAN;
	/*
	string_address[0] = "0|0|2|0";
	string_address[1] = "0|0|8|0";
	string_address[2] = "0|1|1|0";
	*/
    pCAN = (struct SPacket **) malloc(nAddress*sizeof(struct SPacket *));
    
    for (i=0;i<nAddress;i++){
        pCAN[i] = (struct SPacket *) malloc(npackets[i]*sizeof(struct SPacket));
    }
    do {
        Append_packet(pCAN);
        printf("Do you want to send more packets, press 'y' to continue?\r\n");
    }
    while(getch()=='y');
    Encap(pCAN);
}

void Append_packet(struct SPacket **db){
    // this function can be optimized by elemenating structure p (use only pointer db)
    int address,type;
    
    printf("Choose the number of ID Value:\n1- Air Condition\n2- Left Door Lock\n3- Right Door Lock\n");
    scanf("%d",&address);
    address--;
    db [address] = realloc (db[address],++npackets[address]*sizeof(struct SPacket));
    db[address][npackets[address]-1].ID_value = address+1;
    
    printf("Choose the number of ID type:\n1- Normal\n2- External\n");
    scanf("%d",&type);
    
	db[address][npackets[address]-1].ID_type = type;

    printf("\nEnter DLC: ");
    scanf("%d",&db[address][npackets[address]-1].DLC );

    db[address][npackets[address]-1].pdata = (char *) malloc((db[address][npackets[address]-1].DLC)*sizeof(char));
    
    if(db[address][npackets[address]-1].DLC){
        printf("\nEnter Data: ");
    scanf("%s",db[address][npackets[address]-1].pdata);
    }
    
}

void Encap(struct SPacket **db){
	
    int i,j,k;
    for(i=0;i<nAddress;i++){
        for(j=0;j<npackets[i];j++){
            printf("\nSENDING DATA\n");
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("<%X><%s><%X>",db[i][j].ID_type-1,string_address[db[i][j].ID_value-1],db[i][j].DLC);
			if(db[i][j].DLC){
				printf("<");
			}
				for(k=0;k<db[i][j].DLC;k++){
					if(k == db[i][j].DLC-1){
						printf("%c>",db[i][j].pdata[k]);
					}
					else{
						printf("%c|",db[i][j].pdata[k]);
					}
				}
				printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	        
        }
    }
}
















































































