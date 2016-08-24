
/*
	
	  AUTHOR: Ahmed Ragab Shaarawy.
	  DATE  : 24/8/2016.

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
			       = IDV_ptr[IDV_NUM] =								    addr-1     addr-2    addr..
	===========	   ===========================		   ============================================================================
	= mainPtr = ====>> =  IDV_ptr[IDV20_INDEX]   = =========>> = Dynamic size of the structure CAN for ID-20  | Packet-1 | Packet-2 | ....=
	===========	   ===========================		   ============================================================================
			   =  IDV_ptr[DV80_INDEX]    = ======
			   ===========================	    =							    addr-1     addr-2    addr..
			   =  IDV_ptr[DV110_INDEX]   = ==   =	   ============================================================================
			   ===========================  =   ====>> = Dynamic size of the structure CAN for ID-80  | Packet-1 | Packet-2 | ....=
						        = 	   ============================================================================
						        =
							=							    addr-1     addr-2    addr..
						        =	   ============================================================================
						        ========>> = Dynamic size of the structure CAN for ID-110 | Packet-1 | Packet-2 | ....=
								   ============================================================================

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
	U8 IDt:1 ;
	U8 IDv ;
	U8 DLc	;
	U8 packet[PACKET_SIZE];
	}CAN;

CAN FirstCAN[IDV_NUM]={0};

U8 getPacketData( CAN *const can );
U8 showPacketData( const CAN can, U8 packetNum );
U8 showPackets( CAN *canPtr, U8 packetsNum );
U8 addPacket( CAN **const mPtr,volatile U8 *id,volatile U8 *n  );
U8 managePackets( CAN **const mPtr );
U8 deletePacket( CAN **const mPtr,volatile U8 ID,volatile U8 num );

int main(void)
{
	U8  check= 1 ;
	CAN *IDV_ptr[IDV_NUM]={0} ;
	CAN **mainPtr= IDV_ptr ;

	check= managePackets( mainPtr );
	printf("Check is true/false: %d", check);
	
	return 0;
}




U8 managePackets( CAN **const mPtr )
{
	volatile U8 check= 1, id= 0, num=0;
	U8 ch, idv_index= 0, i= 0 ;
	CAN tempCAN ;
	#if DEBUGING
	printf("<<DEBUGING: Program is using debuging.>>\n");
	printf("<<DEBUGING: Program is executing f( managePackets ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	while(1)
	{
		printf("\nProgram options:\n	Enter A/a to add packet.\n	Enter D/d to delete Packet.\n	Enter C/c to change Packet.\n"
		"	Enter V/v to view  packets.\n	Enter O/o to view  one packet.\n	Enter N/n to view  packets numbers.\n"
		"	Enter T/t to terminate  program.\nYour choice is: ");
		scanf("%s", &ch);
		switch(ch)
		{
			case 'A': case 'a': 
			check= addPacket(mPtr, &id, &num  );
			if( !check )
			{
				printf("Error when adding.\n");
				#if DEBUGING
				printf("<<DEBUGING: Error from f(addPacket) inside f(managePackets)>>\n");
				#endif
			}
			else
				printf("Packet number-%d has been added, to ID_type-%d\n",num, id );
			break;
			/**************************************************************************************/
			case 'D': case 'd':
			printf("\nEnter packet ID_type: ");
			scanf("%d", &id);
			#if DEBUGING
			printf("<<DEBUGING: You entered %d>>\n", id);
			#endif
			printf("\nEnter packet number: ");
			scanf("%d", &num);
			#if DEBUGING
			printf("<<DEBUGING: You entered %d>>\n", num);
			#endif
			check= deletePacket(mPtr,id,num );
			#if DEBUGING
			printf("<<DEBUGING: You entered ID= %d, number= %d>>\n",id, num);
			#endif
			
			if( !check )
			{
				printf("Error when deleting.\n");
				#if DEBUGING
				printf("<<DEBUGING: Error from f(deletePacket) inside f(managePackets)>>\n");
				#endif
			}
			else
				printf("Packet number-%d has been deleted, to ID_type-%d\n",num, id );
			break;
			/**************************************************************************************/
			case 'C': case 'c':
			printf("\nEnter new packet data: \n");
			check= getPacketData( &tempCAN );
			if( !check )
			{
				printf("False new Data.\n");
				#if DEBUGING
				printf("<<DEBUGING: Error from f(getPacketData) inside f(managePackets)>>\n",id, num);
				#endif
			}
			else
			{
				if( tempCAN.IDv== AIRC_ID )
					idv_index= IDV20_INDEX ;
				else if( tempCAN.IDv== GARAGE_ID )
					idv_index= IDV80_INDEX;
				else if( tempCAN.IDv== FRIDGE_ID )
					idv_index= IDV110_INDEX;
				printf("\nEnter packet number to change: ");
				scanf("%d", &num);
				if( num== 0 || num> IDV_packetsNum[idv_index] )
					printf("Packet not found.\n");
				else
					mPtr[idv_index][num]= tempCAN;
				printf("Packet number-%d has been changed, from ID_type-%d\n", num,tempCAN.IDv );
			}
			break;			
			/**************************************************************************************/
			case 'V': case 'v':
			if( IDV_packetsNum[IDV20_INDEX] )
			{
				printf("		  [ All packets for ID-20/Aircondition ]\n");
				check= showPackets( mPtr[IDV20_INDEX], IDV_packetsNum[IDV20_INDEX] );
			}
			else printf("Ther is no packets for ID-20/Aircondition.\n");
			if( IDV_packetsNum[IDV80_INDEX] )
			{
				printf("			[ All packets for ID-80/Garage ]\n");
				check= showPackets( mPtr[IDV80_INDEX], IDV_packetsNum[IDV80_INDEX] );
			}
			else printf("Ther is no packets for ID-80/Garage.\n");
			if( IDV_packetsNum[IDV110_INDEX] )
			{
				printf("			[ All packets for ID-110/Fridge ]\n");
				check= showPackets( mPtr[IDV110_INDEX], IDV_packetsNum[IDV110_INDEX] );
			}
			else printf("Ther is no packets for ID-110/Fridge.\n");
			break;
			/**************************************************************************************/
			case 'O': case 'o':
			printf("\nEnter packet ID: ");
			scanf("%d", &id);
			#if DEBUGING
			printf("<<DEBUGING: You entered %d>>\n", id);
			#endif
			if( id== AIRC_ID )
				idv_index= IDV20_INDEX ;
			else if( id== GARAGE_ID )
				idv_index= IDV80_INDEX;
			else if( id== FRIDGE_ID )
				idv_index= IDV110_INDEX;
			else
				printf("False ID type !!.\n");
			printf("\nEnter packet number: ");
			scanf("%d", &num);
			#if DEBUGING
			printf("<<DEBUGING: You entered %d>>\n", num);
			printf("<<DEBUGING: You entered ID= %d, number= %d>>\n",id, num);
			#endif
			if( num== 0 || num> IDV_packetsNum[idv_index] )
				printf("Packet not found.\n");
			else
				check= showPacketData( mPtr[idv_index][num-1], num );
			break;
			/**************************************************************************************/
			case 'N': case 'n':
			printf("Packets number are %d-packets, and are distributed as: \n",
			IDV_packetsNum[IDV20_INDEX]+IDV_packetsNum[IDV80_INDEX]+IDV_packetsNum[IDV110_INDEX]);
			printf("packets for ID-20/Aircondition are: %4d\n", IDV_packetsNum[IDV20_INDEX]);
			printf("packets for ID-80/Garage are: %10d-packets\n", IDV_packetsNum[IDV80_INDEX]);
			printf("packets for ID-110/Fridge are: %9d-packets\n", IDV_packetsNum[IDV110_INDEX]);
			break;
			/**************************************************************************************/
			case 'T': case 't':
			printf("Program terminated.\nTHANK YOU,\nDEVELOPER, AHMED SHAARAWY.\n");
			break;
			/**************************************************************************************/
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




U8 deletePacket( CAN **const mPtr,volatile U8 ID,volatile U8 num )
{
	volatile U8 check= 1;
	U8 idv_index= 0, i;
	CAN *tempPtr;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( deletePacket ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	printf("<<DEBUGING: ID_tye passed to f(deletePacket)= %d.>>\n", ID);
	printf("<<DEBUGING: Packet number passed to f(deletePacket)= %d.>>\n", num);
	#endif
	if( ID== AIRC_ID || ID== GARAGE_ID || ID== FRIDGE_ID )
	{
		#if DEBUGING
		printf("<<DEBUGING: Valid ID-type.>>\n");
		#endif
		switch(ID)
		{
			case AIRC_ID: idv_index= IDV20_INDEX ; break;
			case GARAGE_ID:	idv_index= IDV80_INDEX; break;
			case FRIDGE_ID: idv_index= IDV110_INDEX; break;
		}
		if( num> IDV_packetsNum[idv_index] || num== 0 )
		{
			#if DEBUGING
			printf("<<DEBUGING: False packet number passed to f(deletePacket).>>\n");
			#endif
			check= 0;
		}
		else
		{
			if( num== 1)
			{
				tempPtr= &mPtr[idv_index][1];
				free(mPtr[idv_index]);
				mPtr[idv_index]= tempPtr;
				IDV_packetsNum[idv_index]--;
			}
			else if( num== IDV_packetsNum[idv_index] && num> 0 ) 
				IDV_packetsNum[idv_index]--;
			else
			{
				for( i= num; i< IDV_packetsNum[idv_index] ; i++ )
				mPtr[idv_index][i]= mPtr[idv_index][i+1] ;
				IDV_packetsNum[idv_index]--;
			}
		}
	}
	else
	{
		#if DEBUGING
		printf("<<DEBUGING: False packet ID passed to f(deletePacket) .>>\n");
		#endif
		check= 0;
	}
	
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( deletePacket ).>>\n");
	#endif
	return check ;
}


U8 addPacket( CAN **const mPtr,volatile U8 *id,volatile U8 *n  )
{
	volatile U8 check= 1;
	U8 idv_index= IDV20_INDEX ;
	CAN can, *tempPtr ;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( addPacket ).>>\n");
	printf("<<DEBUGING: Check started True/false= %d>>\n", check);
	#endif
	check= getPacketData( &can );
	//showPacketData( can, 1);
	if( check )
	{
		*id= can.IDv;
		switch(can.IDv)
		{	
			case GARAGE_ID : idv_index= IDV80_INDEX ; 
			#if DEBUGING
			printf("<<DEBUGING: Garage ID = 80.>>\n");
			#endif
			break;
			case FRIDGE_ID:  idv_index= IDV110_INDEX ;
			#if DEBUGING
			printf("<<DEBUGING: Fridge ID = 110.>>\n");
			#endif 
			break;
			default:
			#if DEBUGING
			printf("<<DEBUGING: Aircondition ID = 20.>>\n");
			#endif
			break;
		}
		
		tempPtr= mPtr[idv_index] ;
		#if DEBUGING
		printf("<<DEBUGING: CAN packets numbers before reseving are (%d for AC, %d for Garage, %d for Fridge).>>\n",
		IDV_packetsNum[IDV20_INDEX],IDV_packetsNum[IDV80_INDEX],IDV_packetsNum[IDV110_INDEX] );
		#endif
		if( !IDV_packetsNum[idv_index] )
		{
			#if DEBUGING
			printf("<<DEBUGING: You will reserve the first packet for this ID.>>\n");
			#endif
			mPtr[idv_index]= (CAN*)malloc( sizeof(CAN) );
			if( !mPtr[idv_index] )
			{
				check=0 ;
				#if DEBUGING
				printf("<<DEBUGING: No dynamic size available, can't reserve, false check.>>\n");
				#endif
			}
			else
			{
				#if DEBUGING
				printf("<<DEBUGING: One packet dynamic size reserved at address%p.>>:\n",mPtr[idv_index]);
				#endif
				*mPtr[idv_index]= FirstCAN[idv_index]= can ;
				#if DEBUGING
				printf("<<DEBUGING: The reserved packet data was assigned, and bacome>>:\n" );
				showPacketData( *mPtr[idv_index], 1 );
				#endif
				IDV_packetsNum[idv_index]++ ;
				#if DEBUGING
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
			tempPtr= (CAN*)realloc( (CAN*)tempPtr, sizeof(CAN)*(1+IDV_packetsNum[idv_index]) );
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
				printf("<<DEBUGING: Dynamic size resized by one packet at address%p.>>\n", tempPtr+IDV_packetsNum[idv_index]);
				#endif
				free(mPtr[idv_index]);
				#if DEBUGING
				printf("<<DEBUGING: Pointer freed.>>\n");
				#endif
				mPtr[idv_index]= tempPtr;
				tempPtr[IDV_packetsNum[idv_index]]= can ;
				tempPtr[0]= FirstCAN[idv_index];
				IDV_packetsNum[idv_index]++ ;
				#if DEBUGING
				printf("<<DEBUGING: The reserved packet data was assigned, and bacome>>:\n" );
				showPacketData( tempPtr[IDV_packetsNum[idv_index]-1], 1 );
				printf("<<DEBUGING: CAN packets numbers are (%d for AC, %d for Garage, %d for Fridge).>>\n",
				IDV_packetsNum[IDV20_INDEX],IDV_packetsNum[IDV80_INDEX],IDV_packetsNum[IDV110_INDEX] );
				#endif
		}
		}
	}
	else
		printf("Error at getting data from f( getPacketData )");
	*n= IDV_packetsNum[idv_index];

	#if DEBUGING
	printf("<<DEBUGING: Program finished f( addPacket ).>>\n");
	#endif
	return check ;
}





/* tested = Ok */
U8 getPacketData( CAN *const can )
{
	volatile U8 check= 1 ;
	unsigned int temp= 0, k ;
	U8 ch, idv_index ;
	
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
		printf("<<DEBUGING: False packet ID was chosen>>\n");
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
			case 'A': case 'a': can->IDv= AIRC_ID;  idv_index= IDV20_INDEX;  can->packet[IDV_INDEX]= AIRC_ID; 
			#if DEBUGING
			printf("<<DEBUGING: A/a stored>>\n");
			#endif
			break;
			case 'G': case 'g': can->IDv= GARAGE_ID; idv_index= IDV80_INDEX; can->packet[IDV_INDEX]= GARAGE_ID; 
			#if DEBUGING
			printf("<<DEBUGING: G/g stored>>\n");
			#endif
			break;
			case 'F': case 'f': can->IDv= FRIDGE_ID; idv_index= IDV110_INDEX; can->packet[IDV_INDEX]= FRIDGE_ID;
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
					if( IDV_packetsNum[idv_index]== 0 )
						FirstCAN[idv_index]= *can ;
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


/* tested = Ok */
U8 showPackets( CAN *canPtr, U8 packetsNum )
{
	volatile U8 check= 1;
	U8 i;
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( showPackets ).>>\n");
	#endif
	if( !packetsNum )
	{
		check= 0;
		printf("There is no packets.\n");
		#if DEBUGING
		printf("<<DEBUGING: Argument packets number (packetsNum) was false passed.>>\n");
		#endif
	}
	else
	{
		for( i= 0 ; i< packetsNum ; i++, canPtr++ )
		{
			check= showPacketData( *canPtr, i+1 );
			if(!check)
				break;
		}
	}
	#if DEBUGING
	printf("<<DEBUGING: Program finished f( showPackets ).>>\n");
	#endif
	return check;
	
}

/* tested = OK */
U8 showPacketData( const CAN can, U8 packetNum )
{
	U8 i, check= 1; 
	#if DEBUGING
	printf("<<DEBUGING: Program is executing f( showPacketData ).>>\n");
	#endif
	if( !packetNum )
	{
		check= 0;
		#if DEBUGING
		printf("<<DEBUGING: Argument packet number(packetNum) was false passed.>>\n");
		#endif
	}
	else
	{
		printf("\n                           [ PACKET NUMBER(%d) ]                        \n", packetNum );
		printf(" IDT   IDV1  IDV2  IDV3  IDV4  DLC : Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7\n");
		printf("================================================================================\n");
		printf("||%2d ", can.IDt);
		printf("| %3d ", 0); printf("| %3d ", 0); printf("| %3d ", 0);
		printf("| %3d ", can.IDv);
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












