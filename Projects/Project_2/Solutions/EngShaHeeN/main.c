#include <stdio.h>
#include <string.h>

/*
A program for Encapsulating CAN packets that takes the following inputs from the user:-
1.	ID type (0 for normal, 1 for external) (1 Byte long)
2.	ID value (0x20 for air condition, 0x80 for left door lock, 0x110 for right door lock)(4 Bytes long)
3.	DLC(length of data from 0 to 7)(1 Byte long)
4.	Data (from 0 to 7 bytes long)

and Encapsulate (print) it on the following format
<X><X|X|X|X><X><X|...|X>
<ID_type><ID_value><DLC><Data>

written by \
Eng. Ahmed Shaheen

*/

//type definitions
enum NUMType {normal=1,external};
struct SPacket{
    enum NUMType ID_type;
    int ID_value;
    int DLC;
    char *pdata;
    struct SPacket *pNextPacket;
};
struct SAddress{
    struct SPacket *pFirstPacket;
	int ID_value;
    struct SAddress *pNextAddress;    
};

//global variables declaration
struct SAddress *gpFirstAddress;

//Functions prototypes
struct SAddress * Find_Address(int address);
void Append_packet();
void Print_Packet(struct SPacket *pCurrentPacket);
void Encap(struct SAddress *db);

void main(){
    do {
        Append_packet();
        printf("Do you want to send more packets, press 'y' to continue?\r\n");
    }
    while(getch()=='y');
    Encap(gpFirstAddress);
}
//Function definition 

//1. Find_Address
//a function that search for address inside the global Linked-list of addresses and return it
//if it doesn't find the address it creats a new one and append it to the Linked-list then return it
struct SAddress * Find_Address(int address){
    struct SAddress *pNewAddress;
    struct SAddress *pCurrentAddress;
	struct SAddress *pLastAddress;
    
    pCurrentAddress = gpFirstAddress;
	//check if the Linked-list is Empty, creat a new address return it
    if(pCurrentAddress == NULL){
            pNewAddress = (struct SAddress *) malloc(sizeof(struct SAddress));
            pNewAddress->ID_value = address;
            pNewAddress->pNextAddress = NULL;
			pNewAddress->pFirstPacket = NULL;
	
            gpFirstAddress = pNewAddress;
            return gpFirstAddress;
        }
	//if the Linked List is not Empty, search for the address and retuen it
    else{
    while(pCurrentAddress){  
        if(pCurrentAddress->ID_value == address){
            return pCurrentAddress;
        }
        else{
			pLastAddress = pCurrentAddress;
            pCurrentAddress = pCurrentAddress->pNextAddress;
        }
    }
	//if it's a new address creat one and append it to the list then return it 
    pNewAddress = (struct SAddress *) malloc(sizeof(struct SAddress));
	pNewAddress->ID_value = address;
	pNewAddress->pNextAddress = NULL;
	pNewAddress->pFirstPacket = NULL;
	pLastAddress->pNextAddress = pNewAddress;
	return pLastAddress->pNextAddress;
    }
    
}

//2.Append_packet
//a function that asks the user to enter a packet 
//search for the address of the packet inside the Linked-list of addresses (using Find_Address Function)
//then it appends the packet to the List of that address
void Append_packet(){
   
    int address;
    struct SAddress *pCurrentAddress;
    struct SPacket *pCurrentPacket;
    struct SPacket *pNewPacket;
    
	//ask the user to Enter the address to search for it in the List of addresses
	printf("Enter The Address of the packet: \n");
    scanf("%d",&address);
    
    pCurrentAddress = Find_Address(address);
    pCurrentPacket = pCurrentAddress->pFirstPacket;
    
	//check if the List of the address is Empty (it's the first packet for that address)
    if(pCurrentPacket == NULL){
            pNewPacket = (struct SPacket *) malloc(sizeof(struct SPacket));
            pCurrentPacket = pNewPacket;
			pCurrentAddress->pFirstPacket = pCurrentPacket;
			pCurrentPacket->ID_value = pCurrentAddress->ID_value;
			printf("Choose the number of ID type:\n1- Normal\n2- External\n");
			scanf("%d",&pCurrentPacket->ID_type);
	            
			printf("Enter DLC: ");
			scanf("%d",&pCurrentPacket->DLC);  
			pCurrentPacket->pdata = (char *) malloc((pCurrentPacket->DLC)*sizeof(char));
	            
			if(pCurrentPacket->DLC){
				printf("Enter Data: ");
			scanf("%s",pCurrentPacket->pdata);
			}
				pCurrentPacket->pNextPacket = NULL;
				pCurrentAddress->pNextAddress = NULL;
				return;
    }
	//if it's not the first packet, creat a new packet and append it to the list
    else{
		while(pCurrentPacket->pNextPacket){
                pCurrentPacket = pCurrentPacket->pNextPacket;
        }
        pNewPacket = (struct SPacket *) malloc(sizeof(struct SPacket));
		pCurrentPacket->pNextPacket = pNewPacket;
		pCurrentPacket = pCurrentPacket->pNextPacket;
		pCurrentPacket->ID_value = pCurrentAddress->ID_value;
        printf("Choose the number of ID type:\n1- Normal\n2- External\n");
        scanf("%d",&pCurrentPacket->ID_type);
            
        printf("Enter DLC: ");
        scanf("%d",&pCurrentPacket->DLC);
            
        pCurrentPacket->pdata = (char *) malloc((pCurrentPacket->DLC)*sizeof(char));
            
        if(pCurrentPacket->DLC){
            printf("Enter Data: ");
        scanf("%s",pCurrentPacket->pdata);
        }
        pCurrentPacket->pNextPacket = NULL;
		return;
    }
}
//3.Print_Address
// a function that parse integer address and print it into the following format
//<thousands|hundreds|tens|ones>
void Print_Address(int address){
    int thous,hund,ten,one;
    
    thous = address/1000;
    address -= thous*1000;
    
    hund = address/100;
    address -= hund*100;
    
    ten = address/10;
    address -= ten*10;
    
    one = address;
    
    printf("<%d|%d|%d|%d>",thous,hund,ten,one);
}
//4.Print_Packet
//a function that takes a pointer to a packet and the print it on the following format
//<X><X|X|X|X><X><X|...|X>
//<ID_type><ID_value><DLC><Data>
void Print_Packet(struct SPacket *pCurrentPacket){
	int k;
	int address = pCurrentPacket->ID_value;
    printf("SENDING DATA");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("<%X>",pCurrentPacket->ID_type-1);
	Print_Address(address);
	printf("<%d><",pCurrentPacket->DLC);
    
    for(k=0;k<pCurrentPacket->DLC;k++){
        if(k+1 == pCurrentPacket->DLC){
            printf("%c>",pCurrentPacket->pdata[k]);
        }
        else{
            printf("%c|",pCurrentPacket->pdata[k]);
        }
    }
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

//5.Encap (Encapsulate)
//a function that scan the entire Lists and print all the Packets
void Encap(struct SAddress *db){
    struct SPacket *pCurrentPacket;
    struct SAddress *pCurrentAddress;
    
    if(db == NULL){
        printf("data base is EMPTY !");
    }
    
    else{
		pCurrentAddress = db;
		pCurrentPacket = db->pFirstPacket;
        while(pCurrentAddress){
            while(pCurrentPacket){
                Print_Packet(pCurrentPacket);
                pCurrentPacket = pCurrentPacket->pNextPacket;
            }
            pCurrentAddress = pCurrentAddress->pNextAddress;
			if(pCurrentAddress){
			pCurrentPacket = pCurrentAddress->pFirstPacket;
			}
        }
    }
}



