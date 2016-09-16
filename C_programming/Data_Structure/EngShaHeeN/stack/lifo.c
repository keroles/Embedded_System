#include "lifo.h"

int stack[MAX_SIZE];
int top = -1;

int isFull(){
	if(top == MAX_SIZE - 1){
	return 1;
	}else{
	return 0;
	}
}
int isEmpty(){
	if(top == -1){
	return 1;
	}else{
	return 0;
	}
}

int push(int data){
	
	if(!isFull()){
	stack[++top] = data;
	return 1;
	}else{
	printf("Stack is FULL !");
	return 0;
	}

}

int pop(){
	int data;
	if(!isEmpty()){
		data = stack[top--];
	return data;
	}else{
	printf("Stack is EMPTY !");
	//return -1;
	}

}
int peek(){

	if(!isEmpty()){
	return stack[top];
	}else{
	printf("Stack is EMPTY !");
	//return 0;
	}
}