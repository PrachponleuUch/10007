//Sample Code for Assignment-1 TP1 2021 - COS10007
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sample Structure 
typedef struct {
	char id[2];
	time_t t; //Variable t is of the type time - this allows us to store date&time
}Bus;

int main()
{
	srand(time(NULL)); //Initialize the srand with the current time
	int count=0;
	Bus array[3];
	time_t mytime; //A variable of the type time_t to store the current date and time
	while(count<3){
		printf("Enter bus id ...\n");
		gets(array[count].id);
		mytime = time(NULL)+rand()%9999; // to generate the current time and add a random value to it
		array[count].t=mytime;
		count++;
	}
	
	/* Following code is to display the structure arrays contents */
	count=0;
	char * time_str;
	while(count<3)
	{
		time_str = ctime(&array[count].t); //convert and store the time into a character pointer
		printf("Bus id = %s -> Time --> %s \n",array[count].id, time_str);
		count++;
	}
    return 0;
}