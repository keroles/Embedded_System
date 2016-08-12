#include "stdio.h"

struct students{
	char name[100];
	int  Roll;
	float marks;
};
void main(){
	struct students student;
	
	printf("Enter information of students: \n\n");
	printf("Enter Name: ");
	scanf(" %s",&student.name);
	printf("Enter Roll number: ");
	scanf(" %d",&student.Roll);
	printf("Enter Marks: ");
	scanf(" %f",&student.marks);
	
	printf("\nDisplaying information\n");
	printf("Name: %s\nRoll: %d\nMarks: %g\n\n",student.name,student.Roll,student.marks);
	
	system("pause");
	
}