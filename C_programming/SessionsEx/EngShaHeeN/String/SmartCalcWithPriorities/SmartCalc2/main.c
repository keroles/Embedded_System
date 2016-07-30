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

	//prioritizing operators
	while(num_operators){
	i=0;
	while(operators[i]!=0){ //creating weight and priority matrix
		pr[i]=i;
		switch(operators[i]){
			case '+':
				{
					weights[i]=1;
				}
				break;
			case '-':
				{
					weights[i]=1;
				}
				break;
			case '*':
				{
					weights[i]=0;
				}
				break;
			case '/':
				{
					weights[i]=0;
				}
				break;
		}
		i++;
	}
	i=0;
	while(operators[i]!=0){ //sorting operator according to priority
		for(j=i;j>0;j--){
			if(weights[j]<weights[j-1]){
				temp = weights[j];
				weights[j] = weights[j-1];
				weights[j-1] = (int)temp;

				temp = pr[j];
				pr[j] = pr[j-1];
				pr[j-1] = (int)temp;
			}
			else{
				break;
			}
		}
		i++;
	}
	

	//computing expression
		switch(operators[pr[0]]){
		case '+':
			{
			temp = numbers[pr[0]] + numbers[pr[0]+1];
		}
			break;
		case '-':
		{
			temp = numbers[pr[0]] - numbers[pr[0]+1];
		}
			break;
		case '*':
		{
			temp = numbers[pr[0]] * numbers[pr[0]+1];
		}
			break;
		case '/':
		{
			if(numbers[pr[0]+1] == 0){
				printf("Error! \nCan't divide by zero");
				printf("\n\n####################\nPress any key to exit\n####################\n");
				scanf("%d",i);
				
				
				
			}
			else{
				temp = numbers[pr[0]] / numbers[pr[0]+1];
			}
		}
			break;
	}
		
		numbers[pr[0]] = temp;
		num_operands--;
		//operand pop
		for(j=pr[0]+1;j<num_operands;j++){
			numbers[j] = numbers[j+1];
		}
		//operator pop
		for(j=pr[0];j<num_operators;j++){
			operators[j] = operators[j+1];
		}
		num_operators--;
	}
	/*
    resault = numbers[0];
    for(i=0;i<num_operators;i++){
        switch(operators[i]){
		case '+':
		{
			resault += numbers[i+1];
			//printf("\nresault %d = %lf\n",i,resault);
		}
			break;
		case '-':
		{
			resault -= numbers[i+1];
			//printf("\nresault %d = %lf\n",i,resault);
		}
			break;
        }
    }
    */

	printf("Resault =  %.2lf",numbers[0]);
	
	
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",i);
 
}