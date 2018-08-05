/*
 * calculator.c
 *
 * Created: 8/3/2018 2:01:20 PM
 *  Author: Mahmoud Ashtaf
 */ 
#include "calculator.h"


/*============================================================================*/
/*=================================Variables ==================================*/

char mode='0';							//detect the current mode
char key=NO_KEY ,force_key=NO_KEY ;    //key variable From keypad with user  **** force_Key  the program can only change it
int Number,		                    //Number is temp variable which store the final integer after input each digit alone
result  ; 	     					//result store the final answer of all operations
char op ;								//temp variable store only one operation and pass it to array op operations
int array_of_input [20]={0};			//array of input numbers
char array_of_OP [20]={0};				//array of all input operations
const char Arth_op[]={'+','-','*','/'};	//constant array store the main operations
int inp_counter=0,                      //store the number of input numbers
op_counter=0,						//store the number of op numbers
Arth_swap_counter=0 ;				//used to swap between main operation + - * /

char str_inputs[16];
char* ptr_inputs=str_inputs ;
/*============================================================================*/
/*============================boolean variables ==============================*/

bool print1_check = false ;           //check if intro display finished
bool print2_check = false ;		   //check if mode menu display finished
bool print3_check = false ;           //check if display result finished
bool save_inp_check=false ;           //check if last number already saved
bool save_op_check=true ;			   //check if last operation already saved
bool addition_op=false ;
/*===============================================================================*/

void print_intro(){
	LCD_GotoXY(0,0);
	LCD_Send_A_String("    WELCOME TO   ");
	LCD_GotoXY(1,0);
	LCD_Send_A_String("  MY CALCULATOR ");
	_delay_ms(500);
	LCD_clear_screen();
	LCD_GotoXY(0,0);
	LCD_Send_A_String("enter 1");
	LCD_GotoXY(1,0);
	LCD_Send_A_String("to select modes");
	print1_check=true;
	
}

void print_modes()
{
	LCD_clear_screen();
	LCD_GotoXY(0,0);
	LCD_Send_A_String("1-ARTH OPERATION");
	LCD_GotoXY(1,0);
	LCD_Send_A_String("2-LOGIC OPER");
	
	print2_check=true ;
	
}

void intro_interface()
{
	
	if (print1_check==false)
	{
		print_intro();
	}
	while (key!='1')
	{
		key=Keypad_getkey();
		
		if (print2_check==false && (key=='1'||force_key=='1'))
		{
			print_modes();
		}
	}
	
	key=NO_KEY;
	force_key=NO_KEY;
}

void get_mode()
{
	while(key==NO_KEY)
	{
		key=Keypad_getkey();
		
	}
	mode=key;
	key=NO_KEY;
}

void Detect_numbers()
{
	

	if (key == '1')
	{
		if (Number == 0)
		Number = 1;
		else
		Number = (Number * 10) + 1; //Pressed twice
	}
	
	else if (key == '2') //Button 2 is Pressed
	{
		if (Number == 0)
		Number = 2;
		else
		Number = (Number * 10) + 2; //Pressed twice
	}
	
	else if (key == '3')
	{
		if (Number == 0)
		Number = 3;
		else
		Number = (Number * 10) + 3; //Pressed twice
	}
	
	else if (key == '4') //If Button 4 is pressed
	{
		if (Number == 0)
		Number = 4;
		else
		Number = (Number * 10) + 4; //Pressed twice
	}
	
	else if (key == '5')
	{
		if (Number == 0)
		Number = 5;
		else
		Number = (Number * 10) + 5; //Pressed twice
	}
	
	else if (key == '6')
	{
		if (Number == 0)
		Number = 6;
		else
		Number = (Number * 10) + 6; //Pressed twice
	}
	
	else if (key == '7') //If Button 7 is pressed
	{
		if (Number == 0)
		Number = 7;
		else
		Number = (Number * 10) + 7; //Pressed twice
	}
	
	else if (key == '8')
	{
		if (Number == 0)
		Number = 8;
		else
		Number = (Number * 10) + 8; //Pressed twice
	}
	
	
	else if (key == '9')
	{
		if (Number == 0)
		Number = 9;
		else
		Number = (Number * 10) + 9; //Pressed twice
	}
	
	else if (key == '0')
	{
		if (Number == 0)
		Number = 0;
		else
		Number = (Number * 10) + 0; //Pressed twice
	}
	
	else if (key == OP2)
	{
		
		Number = (Number / 10) ; //Pressed twice
	}
	
	
}

void Arth_mode()
{
	key=NO_KEY;
	
	while (key==NO_KEY)
	{
		key=Keypad_getkey();
	}
	switch(key)
	{
		case '1':case'2':case'3':case'4':case'5':
		case'6':case'7':case'8':case'9':case'0':
		Detect_numbers();
		LCD_Send_A_Character(key);
		if(save_op_check==false)save_last_OP();
		if(addition_op==true){*ptr_inputs=key;ptr_inputs++;}/////////////////
		break;
		
		case AOP:
		swap_operation();
		if(save_inp_check==false)
		save_last_number();
		break;
		
		case CLC:
		LCD_clear_screen();
		reset_var();
		break;
		
		case OP2 :
		if (Number!=0)
		{
			LCD_clear_character();
			Detect_numbers();
		}
		break;
		
		case '=':
		save_last_number();
		//save_last_OP();
		if(addition_op==true)///////////////////
		{	LCD_clear_screen();/////////////////
			disp_addition_op();/////////////////
			init_addtion_op();//////////////////
		}						////////////////
		addition_op=true;
		calculate ();
		Print_result ();
		inp_counter=1;
		op_counter=0;
		
		break;
		
		case OP7:
		mode='0';
		// print1_check = true ;
		print2_check = false ;
		force_key='1';
		break;
	}
	
	
}

void swap_operation()
{

	

	if (Arth_swap_counter==0)
	{	op=Arth_op[Arth_swap_counter];
		LCD_Send_A_Character(op);
	}
	else if (Arth_swap_counter>0 && Arth_swap_counter<5)
	{	op=Arth_op[Arth_swap_counter-1];
		LCD_clear_character();
		LCD_Send_A_Character(op);
	}
	
	Arth_swap_counter++;
	if (Arth_swap_counter==5)
	{
		Arth_swap_counter=1;
		
	}
	
}

void save_last_number()
{
	array_of_input[inp_counter]=Number ;
	inp_counter ++ ;
	save_inp_check=true ;
	save_op_check=false ;
	Number=0 ;
}

void save_last_OP()
{
	array_of_OP[op_counter]=op;
	op_counter ++;
	save_op_check=true ;
	save_inp_check=false ;
	
	if(addition_op==true){*ptr_inputs=op;ptr_inputs++;}///////////////////
	Arth_swap_counter=0;
	op=NO_KEY ;

}

void calculate ()
{ int temp = array_of_input[0] ;
	for (int i=0;i<op_counter;i++)
	{
		switch (array_of_OP[i])
		{
			case '+':
			temp = temp+array_of_input[i+1];break;
			case '-':
			temp = temp-array_of_input[i+1];break;
			case '*':
			temp = temp*array_of_input[i+1];break;
			case '/':
			temp = temp/array_of_input[i+1];break;
			
			
		}
	}
	result = temp ;
	array_of_input[0]=result;
}
void Print_result ()
{
	if (print3_check==false)
	{
		LCD_clear_sec_line();
		LCD_GotoXY(1,0);
		LCD_Send_A_String("result =");
		LCD_display_number(result);
		
	}
	
}

void reset_var()
{
	op=NO_KEY ;
	result=0;
	inp_counter=0;
	op_counter=0;
	Number=0;
	Arth_swap_counter=0;
	
}

void disp_addition_op()
{char str_disp_addtion_op[20];
	sprintf(str_disp_addtion_op,"%d%s",result,str_inputs);
	LCD_GotoXY(0,0);
	LCD_Send_A_String(str_disp_addtion_op);
}

void init_addtion_op()
{
	for (int i=0;i<16;i++)
	{
		
		//str_inputs[i]='\0';
	}
	ptr_inputs=str_inputs;
}

void logic_mode()
{
	
	key=NO_KEY;
	while (key==NO_KEY)
	{
		key=Keypad_getkey();
	}
	switch(key)
	{
		case '1':
		case'0':
		LCD_Send_A_Character(key);
		
		break;
		
		case AOP:
		swap_operation();
		if(save_inp_check==false)
		save_last_number();
		break;
		
		case CLC:

		break;
		
		
	}
}
void op_periorety()
{ int arange_op[10] ;
	for (int i=0 ;i<op_counter;i++)
	{
		
	}
}