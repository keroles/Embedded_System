

/*
	
	  AUTHOR: Ahmed Ragab Shaarawy.
	  DATE  : 24/8/2016.



	PROJECT FEATURES:
		1- Add packet.
		2- Delete packet.
		3- Change packet.
		4- View all packets.
		5- View one packet.
		6- Show all packet number.


PROJECT	  =============================
=======>> = CAN Encapsulation projct: =
	  =============================
				      	     [ Packe size MAX-13, MIN-7 ]
	  =====================================================================================================
	  = ID type  |  ID val 4bytes    |   DLC 1byte	        |       	 			      =
	  = 1byte    |  20,80,110        |   indecates          |       DATA, MAX 7 byte, selected with DLC   =
	  = 0 or 1   |  ID 20            |   How many data 	|					      =
	  =	     |  ID 80	"IDV"    |   for use     	|	MIN 0-Byte	    		      =
	  =   "IDT"  |  ID 110    	 |			|					      =
	  =====================================================================================================
		

	[ A block diagram for project ]
			     ====================
			     = IDV_ptr[IDV_NUM] =					                      addr-1     addr-2    addr..
	===========	 ===========================	      ===========================================================================
	= mainPtr = ==>> =  IDV_ptr[IDV20_INDEX]   ========>> = Dynamic size of the structure CAN for ID-20 | Packet-1 | Packet-2 | ....=
	===========	 ===========================	      ===========================================================================
			 =  IDV_ptr[DV80_INDEX]    = ======
			 ===========================	  =						      addr-1     addr-2    addr..
			 =  IDV_ptr[DV110_INDEX]   = ==   =    ==========================================================================
			 ===========================  =   ==>> = Dynamic size of the structure CAN for ID-80 | Packet-1 | Packet-2 |....=
						      =        ==========================================================================
						      =
						      =							      addr-1     addr-2    addr..
						      =	       ==========================================================================
						      ======>> = Dynamic size of the structure CAN for ID-110| Packet-1 | Packet-2 |....=
							       ==========================================================================

*/


#include<stdio.h>
#include<stdlib.h>

#define DEBUGING	0

#define PACKET_SIZE	13
#define IDT_INDEX	0
#define IDV_INDEX	1
#define DLC_INDEX	5
#define FIRSTBYTE_INDEX 6

#define AIRC_ID		20
#define	GARAGE_ID	80
#define FRIDGE_ID	110

#define IDV_NUM		3
#define IDV20_INDEX	0
#define IDV80_INDEX	1
#define IDV110_INDEX	2

typedef unsigned char  U8;
typedef unsigned short U16;
typedef unsigned long  U32;

U8 IDV_packetsNum[IDV_NUM]={0}; 

typedef struct{
	U8 IDv;
	U8 idv_index;
	U8 num;
	}PktKeys;

typedef struct{
	U8 IDt:1 ;
	PktKeys pkeys ;
	U8 DLc	;
	U8 packet[PACKET_SIZE];
	}CAN;



CAN FirstCAN[IDV_NUM]={0};

U8 getPacketData( CAN *const can );
U8 showPacketData( const CAN can );
U8 showIDPackets( CAN *canPtr );
U8 addPacket( CAN **const mPtr, PktKeys *pkeys  );
U8 managePackets( CAN **const mPtr );
U8 deletePacket( CAN **const mPtr );
U8 getPacketKey( PktKeys *pkeys );
U8 viewAll( CAN **const mPtr );

int main(void)
{
	U8 num, idv, check= 1 ;
	CAN *IDV_ptr[IDV_NUM]={0} ;
	CAN **mainPtr= IDV_ptr ;

	check= managePackets( mainPtr );
	
	return 0;
}




U8 managePackets( CAN **const mPtr )
{
	volatile U8 check= 1 ;
	U8 ch, i= 0, num= 0 ;
	CAN tempCAN ;
	PktKeys pkeys;
	#if DEBUGING
	printf("<<DEBUGING: Program is using debuging.>>\n");
	printf("<<DEBUGING: Program is executing f( managePackets ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	while(1)
	{
		printf("\nProgram options:\n	Enter A/a to add packet.\n	Enter D/d to delete Packet.\n	Enter C/c to change Packet.\n"
		"	Enter V/v to view  packets.\n	Enter O/o to view  one packet.\n	Enter N/n to view packets numbers.\n"
		"	Enter T/t to terminate  program.\nYour choice is: ");
		scanf("%s", &ch);
		switch(ch)
		{
			case 'A': case 'a': 
			check= addPacket(mPtr, &pkeys  );
			if( !check )
			{
				printf("Error when adding.\n");
				#if DEBUGING
				printf("<<DEBUGING: Error from f(addPacket) inside f(managePackets)>>\n");
				#endif
			}
			else
				printf("Packet number-%d has been added, to ID_value-%d\n",pkeys.num, pkeys.IDv );
			break;
			/*****/
			case 'D': case 'd':
			check= deletePacket( mPtr );
			if( !check )
			{
				#if DEBUGING
				printf("<<DEBUGING: f(deletePacket) returns false inside f(managePackets)>>\n");
				#endif
			}
			break;
			/*****/
			case 'C': case 'c':
			printf("\nEnter new packet data: \n");
			check= getPacketData( &tempCAN );
			if( !check )
			{
				printf("False new Data.\n");
				#if DEBUGING
				printf("<<DEBUGING: f(getPacketData) returns false inside f(managePackets)>>\n");
				#endif
			}
			else
			{
				printf("\nEnter packet number to change: ");
				scanf("%d", &num);
				if( num== 0 || num> IDV_packetsNum[tempCAN.pkeys.idv_index] )
					printf("Packet not found.\n");
				else
				{
					tempCAN.pkeys.num= num;
					mPtr[tempCAN.pkeys.idv_index][num-1]= tempCAN;
					printf("Packet number-%d has been changed, from ID_value-%d\n", num,tempCAN.pkeys.IDv );
				}
			}
			break;	
		
			/*****/
			case 'V': case 'v':
			viewAll( mPtr );

			break;
			/*****/
			case 'O': case 'o':
			check= getPacketKey( &pkeys );
			if( check )
				check= showPacketData( mPtr[pkeys.idv_index][pkeys.num-1] );
			break;

			/*****/
			case 'N': case 'n':
			printf("Packets number are %d-packets, and are distributed as: \n",
			IDV_packetsNum[IDV20_INDEX]+IDV_packetsNum[IDV80_INDEX]+IDV_packetsNum[IDV110_INDEX]);
			printf("packets for ID-20/Aircondition are: %4d-packets\n", IDV_packetsNum[IDV20_INDEX]);
			printf("packets for ID-80/Garage are: %10d-packets\n", IDV_packetsNum[IDV80_INDEX]);
			printf("packets for ID-110/Fridge are: %9d-packets\n", IDV_packetsNum[IDV110_INDEX]);
			break;

			/*****/
			case 'T': case 't':
			printf("Program terminated.\nTHANK YOU,\nDEVELOPER, AHMED SHAARAWY.\n");
			break;

			/*****/
			default :
			printf("\nFalse choice !!.\n");
			break;
		}
		if( ch== 'T' || ch== 't' )
			break;
		
	}
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( managePackets ).>>\n");
	#endif
	return check ;
}






U8 viewAll( CAN **const mPtr )
{
	volatile U8 check= 1, check1= 1, check2= 1, check3= 1 ;
	
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( viewAll ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	if( IDV_packetsNum[IDV20_INDEX] )
	{
		printf("		  [ All packets for ID-20/Aircondition ]\n");
		check= showIDPackets( mPtr[IDV20_INDEX] );
		if( !check )
		{
			check1= 0 ;
			printf("Error when trying to show ID-20/Aircondition packets.\n");
		}
	}
	else printf("There are no packets for ID-20/Aircondition.\n");
	if( IDV_packetsNum[IDV80_INDEX] )
	{
		printf("			[ All packets for ID-80/Garage ]\n");
		check= showIDPackets( mPtr[IDV80_INDEX] );
		if( !check )
		{
			check2= 0 ;
			printf("Error when trying to show ID-80/Garage packets.\n");
		}
	}
	else printf("There are no packets for ID-80/Garage.\n");
	if( IDV_packetsNum[IDV110_INDEX] )
	{
		printf("			[ All packets for ID-110/Fridge ]\n");
		check= showIDPackets( mPtr[IDV110_INDEX] );
		if( !check )
		{
			check3= 0 ;
			printf("Error when trying to show ID-110/Fridge packets.\n");
		}
	}
		else printf("There are no packets for ID-110/Fridge.\n");
	
	check= check1 & check2 & check3 ;
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( viewAll ).>>\n");
	#endif
	return check;
}



/* tested = OK */
U8 deletePacket( CAN **const mPtr )
{
	volatile U8 check= 1;
	U8 i;
	PktKeys pkeys;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( deletePacket ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif

	check= getPacketKey( &pkeys );
	if( check )
	{
		if( pkeys.num== IDV_packetsNum[pkeys.idv_index] ) // if it is last packet.
			IDV_packetsNum[pkeys.idv_index]--;
		else
		{
			for( i= pkeys.num-1; i< IDV_packetsNum[pkeys.idv_index] ; i++ )
				mPtr[pkeys.idv_index][i]= mPtr[pkeys.idv_index][i+1] ;
			IDV_packetsNum[pkeys.idv_index]--;
			for( i= 1; i<= IDV_packetsNum[pkeys.idv_index] ; i++ ) // New Numbering for packets.
				mPtr[pkeys.idv_index][i-1].pkeys.num= i;
		}
		printf("Packet number-%d has been deleted, from ID_value-%d\n", pkeys.num, pkeys.IDv );

	}
	else
		printf("Error when deleting.\n");
	
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( deletePacket ).>>\n");
	#endif
	return check ;
}




/* tested = OK */
U8 addPacket( CAN **const mPtr, PktKeys *pkeys  )
{
	volatile U8 check= 1;
	CAN can, *tempPtr ;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( addPacket ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	check= getPacketData( &can );
	if( check )
	{
		pkeys->IDv= can.pkeys.IDv;
		pkeys->idv_index= can.pkeys.idv_index;
		pkeys->num= can.pkeys.num;
		tempPtr= mPtr[can.pkeys.idv_index] ;
		#if DEBUGING
		printf("<<DEBUGING: CAN packets numbers before reseving are (%d for AC, %d for Garage, %d for Fridge).>>\n",
		IDV_packetsNum[IDV20_INDEX],IDV_packetsNum[IDV80_INDEX],IDV_packetsNum[IDV110_INDEX] );
		#endif
		if( !IDV_packetsNum[can.pkeys.idv_index] )
		{
			#if DEBUGING
			printf("<<DEBUGING: You will reserve the first packet for this ID.>>\n");
			#endif
			mPtr[can.pkeys.idv_index]= (CAN*)malloc( sizeof(CAN) );
			if( !mPtr[can.pkeys.idv_index] )
			{
				check=0 ;
				#if DEBUGING
				printf("<<DEBUGING: No dynamic size available, can't reserve, false check.>>\n");
				#endif
			}
			else
			{
				#if DEBUGING
				printf("<<DEBUGING: One packet dynamic size reserved at address%p.>>:\n",mPtr[can.pkeys.idv_index]);
				#endif
				*mPtr[can.pkeys.idv_index]= FirstCAN[can.pkeys.idv_index]= can ;
				IDV_packetsNum[can.pkeys.idv_index]++ ;
				#if DEBUGING
				printf("<<DEBUGING: The reserved packet data was assigned, and bacome>>:\n" );
				showPacketData( *mPtr[can.pkeys.idv_index] );
				printf("<<DEBUGING: CAN packets numbers are (%d for AC, %d for Garage, %d for Fridge)>>\n",
				IDV_packetsNum[IDV20_INDEX],IDV_packetsNum[IDV80_INDEX],IDV_packetsNum[IDV110_INDEX] );
				#endif
			}
			
		}
		else
		{
			#if DEBUGING
			printf("<<DEBUGING: You will add a packet.>>\n");
			#endif
			tempPtr= (CAN*)realloc( (CAN*)tempPtr, sizeof(CAN)*(1+IDV_packetsNum[can.pkeys.idv_index]) );
			if( !tempPtr )
			{
				check=0 ;
				#if DEBUGING
				printf("<<DEBUGING: No dynamic size available, can't resize, false check.>>\n");
				#endif
			}
			else
			{
				#if DEBUGING
				printf("<<DEBUGING: Dynamic size resized by one packet at address%p.>>\n",
				tempPtr+IDV_packetsNum[can.pkeys.idv_index]);
				#endif
				free(mPtr[can.pkeys.idv_index]);
				#if DEBUGING
				printf("<<DEBUGING: Pointer freed.>>\n");
				#endif
				mPtr[can.pkeys.idv_index]= tempPtr;
				tempPtr[IDV_packetsNum[can.pkeys.idv_index]]= can ;
				tempPtr[0]= FirstCAN[can.pkeys.idv_index];
				IDV_packetsNum[can.pkeys.idv_index]++ ;
				#if DEBUGING
				printf("<<DEBUGING: The reserved packet data was assigned, and bacome>>:\n" );
				showPacketData( tempPtr[IDV_packetsNum[can.pkeys.idv_index]-1] );
				printf("<<DEBUGING: CAN packets numbers are (%d for AC, %d for Garage, %d for Fridge).>>\n",
				IDV_packetsNum[IDV20_INDEX],IDV_packetsNum[IDV80_INDEX],IDV_packetsNum[IDV110_INDEX] );
				#endif
		}
		}
	}
	else
		printf("Error at getting data from f( getPacketData )\n");

	#if DEBUGING
	printf("<<DEBUGING: Program finished f( addPacket ).>>\n");
	#endif
	return check ;
}





/* tested = OK */
U8 getPacketKey( PktKeys *pkeys )
{
	volatile U8 check= 1;
	
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( getPacketKey ).>>\n");
	#endif	
	printf("\nEnter packet ID_value: ");
	scanf("%d", &pkeys->IDv);
	#if DEBUGING
	printf("<<DEBUGING: You entered %d>>\n", pkeys->IDv);
	#endif
	switch(pkeys->IDv)
	{
		case AIRC_ID: pkeys->idv_index= IDV20_INDEX; break;
		case GARAGE_ID: pkeys->idv_index= IDV80_INDEX; break;
		case FRIDGE_ID: pkeys->idv_index= IDV110_INDEX; break;
		default: check= 0; 
		printf("False ID-value.\n");
		#if DEBUGING
		printf("<<DEBUGING: ID-value must be 20/AC or 80/Garage or 110/Fridge.>>\n");
		#endif
		break;
	}
	if( check )
	{
		#if DEBUGING
		printf("<<DEBUGING: True ID-value.>>\n");
		#endif
		printf("\nEnter packet number: ");
		scanf("%d", &pkeys->num);
		#if DEBUGING
		printf("<<DEBUGING: You entered %d>>\n", pkeys->num);
		#endif
		if( pkeys->num== 0 || pkeys->num> IDV_packetsNum[pkeys->idv_index] )
		{
			#if DEBUGING
			if( pkeys->num== 0 )
				printf("<<DEBUGING: Packet number can't be zero.>>\n");
			else
				printf("<<DEBUGING: Packet number over than stored.>>\n");
			#endif
			printf("Packet number not found.\n");
			check= 0;
		}
		else
		{
			#if DEBUGING
			printf("<<DEBUGING: True packet number, packet found>>\n");
			#endif
		}
	}
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( getPacketKey ).>>\n");
	#endif
	return check ;
}




/* tested = Ok */
U8 showIDPackets( CAN *canPtr )
{
	volatile U8 check= 1;
	U8 i ;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( showIDPackets ).>>\n");
	#endif
	if( !IDV_packetsNum[canPtr->pkeys.idv_index] )
	{
		check= 0;
		printf("There is no packets.\n");
		#if DEBUGING
		printf("<<DEBUGING: Argument packets number (packetsNum) was false passed.>>\n");
		#endif
	}
	else
	{
		for( i= 0 ; i< IDV_packetsNum[canPtr->pkeys.idv_index] ; i++ )
		{
			check= showPacketData( canPtr[i] );
			if(!check)
			{
				#if DEBUGUNG
				printf("<<DEBUGING: Error in packet %d show for ID-%d.>>", i+1, canPtr[i].keys.IDv);
				#endif
				break;
			}
				
		}
	}
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( showIDPackets ).>>\n");
	#endif
	return check;
	
}

/* tested = OK */
U8 showPacketData( const CAN can )
{
	U8 i, check= 1; 
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( showPacketData ).>>\n");
	#endif
	if( !can.pkeys.num )
	{
		check= 0;
		#if DEBUGING
		printf("<<DEBUGING: False packet number inide struct.>>\n");
		#endif
	}
	else
	{
		printf("\n                           [ PACKET NUMBER(%d) ]                        \n", can.pkeys.num );
		printf(" IDT   IDV1  IDV2  IDV3  IDV4  DLC : Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7\n");
		printf("================================================================================\n");
		printf("||%2d ", can.IDt);
		printf("| %3d ", 0); printf("| %3d ", 0); printf("| %3d ", 0);
		printf("| %3d ", can.pkeys.IDv);
		printf("| %3d |", can.DLc);
		for(i= FIRSTBYTE_INDEX; i< 13 ; i++)
			printf("| %3d ", can.packet[i]);
		printf("||\n");
		printf("================================================================================\n\n");
	}
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( showPacketData ).>>\n");
	#endif
	return check ;
}




/* tested = Ok */
U8 getPacketData( CAN *const can )
{
	volatile U8 check= 1 ;
	unsigned int temp= 0, k ;
	U8 ch ;
	
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( getPacketData ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	printf("Enter 0 for 1st packet identifier type\n   or 1 for 2nd packet identefier type: ");
	scanf("%d", &temp);
	if( temp== 1)
	{	
		#if DEBUGING
		printf("<<DEBUGING: 2nd packet ID was chosen>>\n");
		#endif
		can->IDt= 1; 
		can->packet[IDT_INDEX]= 1;
	}
		
	else if( temp== 0)
	{
		#if DEBUGING
		printf("<<DEBUGING: 1st packet ID was chosen>>\n");
		#endif
		can->IDt= 0; 
		can->packet[IDT_INDEX]= 0;
	}
	else
	{
		#if DEBUGING
		printf("<<DEBUGING: False packet ID-type was chosen>>\n");
		#endif
		check= 0;
	}
	if( check ) // 1st check.
	{
		#if DEBUGING
		printf("<<DEBUGING: 1st check is true>>\n");
		#endif
		printf("Enter A for Aircondition.\n      G for Garage.\n      F for Fridge.\nChose packet target: ");
		scanf("%s", &ch);
		//scanf("%c", &charcter);
		#if DEBUGING
		printf("<<DEBUGING: You entered %c>>\n", ch);
		printf("<<DEBUGING: check before switch() which dfines A or G or F is %d>>\n", check);
		#endif
		switch(ch)
		{
			case 'A': case 'a': 
			can->pkeys.IDv= AIRC_ID; 
			can->pkeys.idv_index= IDV20_INDEX; 
			can->packet[IDV_INDEX]= AIRC_ID;
			can->pkeys.num= IDV_packetsNum[IDV20_INDEX]+1 ;
			#if DEBUGING
			printf("<<DEBUGING: A/a stored>>\n");
			#endif
			break;
			case'G':case'g':
			can->pkeys.IDv= GARAGE_ID;  
			can->pkeys.idv_index= IDV80_INDEX;  
			can->packet[IDV_INDEX]= GARAGE_ID; 
			can->pkeys.num= IDV_packetsNum[IDV80_INDEX]+1 ;
			#if DEBUGING
			printf("<<DEBUGING: G/g stored>>\n");
			#endif
			break;
			case 'F': case 'f': 
			can->pkeys.IDv= FRIDGE_ID; 
			can->pkeys.idv_index= IDV110_INDEX; 
			can->packet[IDV_INDEX]= FRIDGE_ID;
			can->pkeys.num= IDV_packetsNum[IDV110_INDEX]+1 ;
			#if DEBUGING
			printf("<<DEBUGING: F/f stored>>\n");
			#endif
			break;
			default : check= 0; 
			#if DEBUGING
			printf("<<DEBUGING: No stored>>\n");
			#endif
			break;
		}
		if( check ) //2nd check
		{
			#if DEBUGING
			printf("<<DEBUGING: 2nd check is true>>\n");
			#endif
			printf("Enter number of data bytes max 7-Bytes: ");
			scanf("%d", &temp);
			#if DEBUGING
			printf("<<DEBUGING: You entered %d>>\n", temp);
			#endif
			if( temp<= 7 && temp>= 0)
			{
				#if DEBUGING
				printf("<<DEBUGING: True packet data size>>\n");
				#endif
				can->DLc= temp;
				can->packet[DLC_INDEX]= temp;
				if( temp )
				{
					#if DEBUGING
					printf("<<DEBUGING: Packet data size > 0>>\n");
					#endif
					printf("\nEnter Your data Bytes.\n");
					for( k= FIRSTBYTE_INDEX; k< PACKET_SIZE ; k++)
					{
						if( k< temp+FIRSTBYTE_INDEX )
						{
							printf("Enter byte %d: ", k-FIRSTBYTE_INDEX+1 );
							scanf("%d", &(can->packet[k]) );
							#if DEBUGING
							printf("<<Byte%d stored as %d>>\n", k-FIRSTBYTE_INDEX+1, can->packet[k]);
							#endif
						}
						else
							can->packet[k]= 0;
					}
					if( IDV_packetsNum[can->pkeys.idv_index]== 0 )
						FirstCAN[can->pkeys.idv_index]= *can ;
					
					printf("\n");
				}
				
				#if DEBUGING
				else
				printf("<<DEBUGING: Packet data size= 0>>\n");
				#endif
			}
			else 
			{
				check= 0;
				#if DEBUGING
				printf("<<DEBUGING: False packet data size>>\n");
				#endif
			}
		}
		#if DEBUGING
		else
		printf("<<DEBUGING: 2st check is false>>\n");
		#endif

	}
	#if DEBUGING
	else
	printf("<<DEBUGING: 1st check is false>>\n");
	printf("<<DEBUGING: Program finished f( getPacketData ).>>\n");
	#endif
	return check ;
}





















