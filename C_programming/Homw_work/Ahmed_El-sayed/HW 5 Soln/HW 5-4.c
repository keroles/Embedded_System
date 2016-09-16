#include "stdio.h"

struct students{
	char name[100];
	int  Roll;
	float marks;
};
void main(){

	struct students student[10];
	int i;
	
	printf("Enter information of students: \n\n");
	for(i=0;i<10;i++){
		student[i].Roll = i+1;
		printf("For Roll number %d: \n",student[i].Roll);
		printf("Enter Name: ");
		scanf(" %s",&student[i].name);
		printf("Enter Marks: ");
		scanf(" %f",&student[i].marks);
		printf("\n");
	}
	printf("\nDisplaying information of students: \n\n");
	for(i=0;i<10;i++){
		printf("Information for Roll number %d: \nName: %s\nMarks: %g\n\n",student[i].Roll,student[i].name,student[i].marks);
	}
	system("pause");
	
}