#include<stdio.h>
#define num_address 3
typedef struct {
int ID_value,ID_type;
char dlc,*data;
}packet;

void display(packet**);

int num_cl[num_address]={0};//indicates number of packets in each address (column)

void spacket(packet**);
int main(){
    int i;
    char ch='y';
   packet**ptr;

ptr=(packet**)malloc(num_address*sizeof(packet*));
//at the first of program the number of packet is zero and it increase depend on user
for(i=0;i<num_address;i++){
    ptr[i]=(packet*)malloc(num_cl[i]*sizeof(packet));
}
while(ch=='y'){
spacket(ptr);
printf("Do you want to add more packets press y if yes  \n");
scanf(" %c",&ch);

}

display(ptr);
}
void spacket(packet**ptr){
    int value,type;
printf("choose ID_value\n1-for air condition\n2-for left door lock\n3-for right door lock\n");
scanf("%d",&value);
ptr[value-1]=realloc(ptr[value-1],++num_cl[value-1]*sizeof(packet));
printf("Enter ID_Type\n1-normal\n2-external\n");
scanf("%d",&type);
if(value==1){ptr[value-1][num_cl[value-1]-1].ID_value=20;}
else if(value==2){ptr[value-1][num_cl[value-1]-1].ID_value=80;}
else if(value==3){ptr[value-1][num_cl[value-1]-1].ID_value=110;}
if(type==1){ptr[value-1][num_cl[value-1]-1].ID_type=0;}
else if(type==2){ptr[value-1][num_cl[value-1]-1].ID_type=1;}
printf("Enter the Data length counter (DLC):");
scanf(" %d",&ptr[value-1][num_cl[value-1]-1].dlc);

ptr[value-1][num_cl[value-1]-1].data=(char*)malloc(ptr[value-1][num_cl[value-1]-1].dlc*sizeof(char));
printf("Enter data\n");
scanf("%s",ptr[value-1][num_cl[value-1]-1].data);

}
void display(packet**ptr){
    int i,j,k;
printf("the packets are\n");
for(i=0;i<num_address;i++){
        for(j=0;j<num_cl[i];j++){
            printf("%d\t%d\t%d\t",ptr[i][j].ID_type,ptr[i][j].ID_value,ptr[i][j].dlc);
            for(k=0;k<ptr[i][j].dlc;k++){
                printf("%c",ptr[i][j].data[k]);

            }
            printf("\n");
        }}



}




