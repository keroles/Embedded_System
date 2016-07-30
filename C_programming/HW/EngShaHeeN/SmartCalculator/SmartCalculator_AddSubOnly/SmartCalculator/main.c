#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define s 100
void main(){
	int i,j,k,l,weights[s],pr[s]; //pr : priority 
	char exp[s],operand[s][s],operators[s];
	int num_operators=0,num_operands;
    double numbers[s];
    double resault=0,temp;
	numbers[0]=0;
    printf("Enter an Expression :");
    gets(exp);
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while(exp[i] != 0){
        if(exp[i]=='+'){
                operators[j] = '+';
                operand[k][l] = 0;
                i++;
                j++;
                k++;
                l = 0;
                continue;
            }
        else if(exp[i]=='-'){
                operators[j] = '-';
                operand[k][l] = 0;
                i++;
                j++;
                k++;
                l = 0;
                continue;
        }
		else if(exp[i]=='*'){
                operators[j] = '*';
                operand[k][l] = 0;
                i++;
                j++;
                k++;
                l = 0;
                continue;
        }
		else if(exp[i]=='/'){
                operators[j] = '/';
                operand[k][l] = 0;
                i++;
                j++;
                k++;
                l = 0;
                continue;
        }
        else{
			if((exp[i]!='1')&&(exp[i]!='2')&&(exp[i]!='3')&&(exp[i]!='4')&&(exp[i]!='5')&&(exp[i]!='6')&&(exp[i]!='7')&&(exp[i]!='8')&&(exp[i]!='9')&&(exp[i]!='0')&&(exp[i]!='.')){
				i++;
				continue;
			}
            operand[k][l] = exp[i];
            i++;
            l++;
            continue;
        }
    }
	
    operand[k][l] = 0;
	operators[j]=0;
    num_operators = j;
    num_operands = k+1;
    for(i=0;i<num_operands;i++){
            numbers[i] = atof(operand[i]); 
			//printf("\nnum %d = %lf\n",i,numbers[i]);
    }
    resault = numbers[0];
    for(i=0;i<num_operators;i++){
        switch(operators[i]){
		case '+':
		{
			resault += numbers[i+1];
		}
			break;
		case '-':
		{
			resault -= numbers[i+1];
		}
			break;
        }
    }
    

	printf("Resault =  %.2lf",resault);
	
	
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",i);
 
}