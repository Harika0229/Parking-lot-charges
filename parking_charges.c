#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>

/* Program to calculate the parking charges */

int calculate();
float rate();
void output();

 	int ehour;
 	int emin;
 	int exhour;
 	int exmin;
 	int entry=0;
 	int Exit=0;
 	int totalParkingTime;
	float totalChargeFee; 
	int hrs; 
	int mins; 
	char x;  int i;
	
	struct customer
	{
		int vehic;
		char Name[20];
		char vehicno[10];
	}C1;
 	
int main()
 {
 	printf("Enter the type of the vehicle: \n 1 for Two Wheeler \n 2 for Car \n 3 for Bus\n"); 
	scanf("%d",&C1.vehic);
	printf("Enter the hour the vehicle entered the lot: ");
	scanf("%d",&ehour);
	printf("Enter the min the vehicle entered the lot: ");
	scanf("%d",&emin);
	
   int ch;
   
    printf("\nEnter your choice\n");
    printf("\nPress 1 to print an Entry ticket");
    printf("\nPress 2 to print a charge receipt ");
    scanf("%d",&ch);
	
	if(ch==1)
	{
	printf("Enter the name of the customer: ");
	scanf("%s",C1.Name);
	printf("Enter the vehicle number: ");
	scanf("%s",C1.vehicno);
	
	
	//printing an entry ticket
	printf("\n----------------------------------------------\n");
	printf(" *****Welcome to the parking lot*****");
	printf("\n---------------------------------------------\n");
	printf("\n Vehicle type-%d\t",C1.vehic); 
	printf("\tVehicle no-%s",C1.vehicno);
	printf("\n Name - %s",C1.Name);
	printf("\n Time In - %d:%d",ehour,emin);
	for(x='A';x<='E';x++)
	{
		for(i=1;i<=10;i++)
		{
			printf("\nYou have been alloted slot %c%d",x,i);
			break;
		}
		break;
	}
getch();
}
	
   else
   {
	//Entering the details
	printf("\nEnter the hour the vehicle left the parking lot: "); 
	scanf("%d",&exhour);
	printf("Enter the min the vehicle left the parking lot: ");
	scanf("%d",&exmin);
	calculate();
		totalChargeFee=rate();
	 hrs=(totalParkingTime/60);
    mins=(totalParkingTime%60);	
	output();
	getch();
}
return 0;
}
int calculate()
{
  //Calculating parking time
     entry=ehour*60+emin;
	Exit=exhour*60+exmin;
    totalParkingTime=Exit-entry;
    return totalParkingTime;
}
float rate()
	{
    //Calculating the charges according to time
    switch(C1.vehic)
   {
	case 1: 
	if(totalParkingTime<=180)
	{
	totalChargeFee=0.5*totalParkingTime;
    }
 	else 
 	{
	totalChargeFee=0.5*180+0.55*(totalParkingTime-180); 
    }
	break;
	
	case 2:
		if(totalParkingTime<=120)
		{
		totalChargeFee=0.55*totalParkingTime;
	    }
		else
		{
		totalChargeFee=0.55*120+0.6*(totalParkingTime-120);
	    }
		break;
		
	case 3:
		if(totalParkingTime<=60)
		{
		totalChargeFee=0.6*totalParkingTime;
	    }
		else
		{
		totalChargeFee=0.6*60+0.65*(totalParkingTime-60);
	    }
		break;
	}
	return totalChargeFee;
}
void output()
{
//Printing the customer's bill
printf("\n\n");
printf("\n---------------------------------------------\n");
printf("\t\tROYAL PARKING VALET\t\t\n");
printf("\t\tSALT LAKE STADIUM\t\t\n");                   
printf("\tMaiden B.B.D Bagh,Kolkata,West Bengal\t\n");
printf("============================================\n");
printf("\tPARKING CHARGE RECEIPT\t\t\n");                        
printf("=============================================\n");
printf("\nType of vehicle:%d",C1.vehic);       //printf("\t\t\t%s\n",ctime(&now));                          
printf("\nTime In: %d : %d\t",ehour,emin);
printf ("Time Out: %d : %d",exhour,exmin);
printf("\nTotal parking time:%d hours %d minutes\n",hrs,mins);
printf("Parking charges:%f\n",totalChargeFee);
printf("----------------------------------------------\n");
printf("\tThank you and Drive Safe!\t");
printf("\n----------------------------------------------\n");
}


