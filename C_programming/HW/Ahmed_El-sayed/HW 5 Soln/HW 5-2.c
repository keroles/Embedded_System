#include "stdio.h"

struct Distance{
	int feet;
	float inch;
};
void main(){
	struct Distance Dist1,Dist2,Total_Dist;
	printf("Enter information of 1st distance: \n");
	printf("Enter feet: ");
	scanf(" %d",&Dist1.feet);
	printf("Enter inch: ");
	scanf(" %f",&Dist1.inch);
	printf("\nEnter information of 2nd distance: \n");
	printf("Enter feet: ");
	scanf(" %d",&Dist2.feet);
	printf("Enter inch: ");
	scanf(" %f",&Dist2.inch);
	
	Total_Dist.feet = Dist1.feet + Dist2.feet;
	Total_Dist.inch = Dist1.inch + Dist2.inch;
	
	while(Total_Dist.inch >= 12){
		Total_Dist.inch -=12;
		Total_Dist.feet +=1;
	}
	printf("\nSum of distances = %d' - %g\"\n\n",Total_Dist.feet,Total_Dist.inch);
	system("pause");
	
}