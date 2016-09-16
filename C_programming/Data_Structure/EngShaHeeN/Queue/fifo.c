#include <fifo.h>

front = -1;
rear = -1;

int queue[MAX_SIZE];


int isEmpty(){
	if(front < 0 || front > rear){
		return 1;
	}
	else {
		return 0;
	}

}

int isFull(){
	if(rear > MAX_SIZE - 1){
		return 1;
	}
	else {
		return 0;
	}

}

int enqueue(int data){
	if(isEmpty()){
		queue[++front] = data;
		rear++;
		return 1;
	}
	else if(!isFull()){
		queue[++rear] = data;
		return 1;
	}
	else{
		printf("Queue is FULL !");
		return 0;
	}
}

int dequeue(){
	int data;
	if(!isEmpty()){
		data = queue[rear--];
		return data;
	}
	else{
		printf("Queue is EMPTY !");
	}
}

int peek(){
	if(!isEmpty()){
		return queue[rear];
	}
	else{
		printf("Queue is EMPTY !");
	}
}
