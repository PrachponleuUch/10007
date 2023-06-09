/*
Name: Prachponleu Uch
Student Number: 103518056
Unit: Developing Technical Software
Unit Code: COS10007
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//!Create self referential structure for Train with id, t and *next as its elements
typedef struct Train{
	int id;
	time_t t; 
    struct Train *next;
}Train;

//!Pointer for Train
typedef Train *TrainPtr;

//!Function prototypes
void getId(Train *array, int);
void getTime(Train *array, int);
void printArray(Train *array, int);
void arrangeSchedule(Train *array, int);
void instruction();
void menu(Train *array, int, int);
void enQdeQ(TrainPtr topPtr, Train *array, int, int);
void pushPop(TrainPtr topPtr, Train *array, int, int);

int main()
{
    int count = 0;
	Train array[10]; //!Set structure size to 10
    getId(array,10); //!Passing structure and size to getId function
    getTime(array, 10); //!Passing structure and size to getTime function
    printf("\nUnordered schedule:\n");
    printArray(array, 10); //!Passing structure and size to printArray function
    printf("\nOrdered schedule:\n");
    arrangeSchedule(array, 10); //!Passing structure and size to arrangeStructure function
    instruction(); //! Call to instruction function
    menu(array,10, count); //!Passing structure, size and count to arrangeStructure function
}

//!Insert random Id values between 100-200 into structure 
void getId(Train *array, int size)
{
    srand(time(NULL));
    int count = 0, upper = 200, lower = 100;

    //! While loop to generate random number between 100-200 and insert into structure Train
    while(count<size){
		array[count].id = (rand() % (upper - lower + 1)) + lower;
		count++;
	}
}

//!Insert Time values into structure 
void getTime(Train *array, int size)
{
    srand(time(NULL));
    int count = 0;
    time_t mytime;

    //!While loop to generate and insert time to structure Train
	while(count<size)
	{
		mytime = time(NULL)+rand()%9999; 
		array[count].t = mytime;
		count++;
	}
    
}

//! Print Structure
void printArray(Train *array, int size)
{
    int count = 0;
    char * time_str;

    //!While loop to print out Train schedule
	while(count<size)
	{
		time_str = ctime(&array[count].t); 
		printf("Train id = %d -> Time --> %s \n", array[count].id, time_str);
		count++;
	}
}
//! Rearrange Schedule from Earliest to Latest
void arrangeSchedule(Train *array, int size)
{
    int tempId = 0;
    time_t tempT;
    int i, j;

    //! For loop to rearrange train schedule
    for (i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(difftime((array+i)->t,(array+j)->t) > 0)
            {
                tempId =  (array+j)->id;
                tempT = (array+j)->t;

                (array+j)->id = (array+i)->id;
                (array+j)->t = (array+i)->t;

                (array+i)->id = tempId;
                (array+i)->t = tempT;
            }
        }
    }
    //! Passing array and size to print the new rearrange schedule
    printArray(array, size);
}

//! Print instruction
void instruction()
{
    printf("\n(1) To allow one train to leave based on schedule.\n");
    printf("(2) To allow one train to leave in an emergency.\n");
    printf("(9) To exit program.\n");
}

//! Menu to send out train in the order of the schedule or in an emergency
void menu(Train *array, int size, int count)
{
    TrainPtr startPtr = NULL;
    int choice = 0;
    printf("\nPlease enter your option:");
    scanf("%d", &choice);

    //! Infinite loop use to ask for user input
    while(1)
    {
        switch(choice)
        {
            case 1:
            enQdeQ(startPtr, array, size, count);
            break;
            case 2:
            pushPop(startPtr, array, size, count);
            break;
            case 9:
            printf("Program ended.");
            exit(0);
        }
    }
}

//! Function use for sending train out in the order of the schedule 
void pushPop(TrainPtr topPtr, Train *array, int size, int count)
{
    TrainPtr newPtr, tempPtr;
    int tempId = 0;
    char * tempT;
    int i = count;
    int length = size;
    //! Insert values inside Trains to build stack
    while(length > 0)
    {
        newPtr = malloc(sizeof(Train));
        newPtr->id =  (array+i)->id;
        newPtr->t = (array+i)->t;
        newPtr->next = topPtr;
        topPtr = newPtr;
        i++;
        length--;
    }
    size--;

    //! Release the value of the top of the stack
    tempPtr = topPtr;
    tempId = topPtr->id;
    tempT = ctime(&topPtr->t);
    topPtr = topPtr->next;
    free(tempPtr);
 
    printf("Train id = %d -> Time --> %s has departed in an emergency \n", tempId, tempT);

    //! IF statement to check if the stack is empty
    if (topPtr == NULL)
    {
        printf("\nNo more train will be departed from this station. Thank you.\n");
        exit(0);
    }
    else
    {
    menu(array, size, count);
    }
}

//! Function use to send train out in an emergency
void enQdeQ(TrainPtr headPtr, Train *array, int size, int count)
{
    TrainPtr newPtr, tempPtr, tailPtr = NULL;
    int tempId = 0;
    char * tempT;
    int i = count;
    int length = size;

    //! Insert values inside Trains to build stack
    while(length > 0)
    {
        newPtr = malloc(sizeof(Train));
        newPtr->id =  (array+i)->id;
        newPtr->t = (array+i)->t;
        newPtr->next = NULL;
        //! IF statement use to check if the queue is empty
        if ( headPtr == NULL)
		{
			headPtr = newPtr;
		} 
		else
		{
			tailPtr->next = newPtr;
		}
        tailPtr = newPtr;
        i++;
        length--;
    }
    size--;

    //! Release the value of the head of the queue
    tempId = headPtr->id;
    tempT = ctime(&headPtr->t);
    tempPtr = headPtr;
    headPtr = headPtr->next;
    free(tempPtr);

    printf("Train id = %d -> Time --> %s has departed in an emergency \n", tempId, tempT);
    count++;

    //! IF statement use to check if the stack is empty
    if (headPtr == NULL)
    {
        printf("\nNo more train will be departed from this station. Thank you.\n");
        exit(0);
    }
    else
    {
    menu(array, size, count);
    }
}