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
#include "header1.h"
#include "header2.h"
#define SIZE 10

//!Function to read file
void readFile()
{
    int i = 0;
    FILE *fp = fopen("TEXT.txt","r");

    while (!feof(fp))
    {
        fscanf(fp,"%s",s[i].array);
        fscanf(fp,"%d",&s[i].value1);
        fscanf(fp,"%d",&s[i].value2);
        fscanf(fp,"%lf",&s[i].value3);
        i++;
    }
}

//!Function to print menu and get user input
int menu()
{
    int userInput;

    printf("\n(1) Display details of array\n");
    printf("(2) Sort array \n");
    printf("(3) Search array  \n");
    printf("(4) Insert array into linked list \n");
    printf("(5) Quit  \n");

    printf("Please choose an option: \n");
    scanf("%d", &userInput);

    return userInput;
}

//!Function to display array
void displayArray()
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        printf("\nArray: %s   Integer1: %d    Integer2: %d    Double: %.2lf\n", s[i].array, s[i].value1, s[i].value2, s[i].value3);
    }
    main();
}

//!Function to show user options and get user input on ascending or descending order
int AscORDes()
{
    int ascORdesUserInput;
    printf("\n(1) Ascending Order\n");
    printf("(2) Descending Order \n");
    printf("Enter an order: \n");
    scanf("%d", &ascORdesUserInput);

    return ascORdesUserInput;
}

//!Function to show user options and get user input on which sort algorithm to use
int SortInput()
{
    int sortUserInput;
    printf("\n(1) Bubble Sort\n");
    printf("(2) Insertion Sort \n");
    printf("Enter a sort algorithm to use: \n");
    scanf("%d", &sortUserInput);

    return sortUserInput;
}

//!Function to call to the correct function for user input
void Sort(int sortUserInput, int choice)
{
    switch(sortUserInput)
        { 
            case 1:
                Bubble(choice);
                break;
            case 2:
                Insertion(choice);
                break;
            default:
                break;
        }
}

//!Function to sort array using Bubble Sort Algorithm in ascending or descending order
void Bubble(int choice)
{
    int i, j;
    Struct temp;
    for (i = 0; i < (SIZE - 1); ++i)
    {
        for (j = 0; j < (SIZE - 1 - i); ++j)
        {
            switch(choice)
            {
                case 1:
                    if (strcmp(s[j].array,s[j+1].array)>0)
                    {
                        temp = s[j+1];
                        s[j+1] = s[j];
                        s[j] = temp;
                    }
                    break;
                case 2:
                    if (strcmp(s[j].array,s[j+1].array)<0)
                    {
                        temp = s[j+1];
                        s[j+1] = s[j];
                        s[j] = temp;
                    }
                    break;
            }
        }
    }
    displayArray();
    main();

}


//!Function to sort array using Insertion Sort Algorithm in ascending or descending order
void Insertion(int choice)
{
    int i = 0, j = 0;
    Struct temp;
    for (i = 1; i < SIZE; ++i)
    {
        temp = s[i];
        
            switch(choice)
            {
                case 1:
                    for (j = i; j > 0 && strcmp(s[j-1].array , temp.array)>0; j--)
                        s[j] = s[j-1];
                        s[j] = temp;
                    break;
                case 2:
                    for (j = i; j > 0 && strcmp(s[j-1].array , temp.array)<0; j--)
                        s[j] = s[j-1];
                        s[j] = temp;
                    break;
            }
    }    
    displayArray();
    main();
}

//!Function to show options to user and get user input on which searching algorithm to use
int SearchInput()
{
    int searchInput;
    printf("\n(1) Linear\n");
    printf("(2) Binary \n");
    printf("Enter a search algorithm to use: \n");
    scanf("%d", &searchInput);

    return searchInput;
}

//!Function to call to the correct function for user input
void Search(int choice)
{
    char searchChoice[20] = {0};
    printf("Enter a string to search: \n");
    scanf("%s", &searchChoice);
    switch(choice)
        { 
            case 1:
                Linear(SIZE,searchChoice);
                main();
                break;
            case 2:
                Binary(searchChoice, 0, SIZE-1);
                break;
            default:
                break;
        }
}

//!Function to do Linear Search Algorithm on the array
int Linear(int size,char *choice)
{
    size--;
    
    if (size < 0) {
        printf("none");
        return -1;
    }
    
    if (strcmp(s[size].array,choice)==0) {
        printf("It exists");
        return size;
    }
    
    return Linear(size, choice);
}


//!Function to do Binary Search Algorithm on the array
void Binary(char *searchKey, int low, int high)
{
    int i, j;
    Struct temp;
    for (i = 0; i < (SIZE - 1); ++i)
    {
        for (j = 0; j < (SIZE - 1 - i); ++j)
        {
                    if (strcmp(s[j].array,s[j+1].array)>0)
                    {
                        temp = s[j+1];
                        s[j+1] = s[j];
                        s[j] = temp;
                    }
        }
    }
    
    int middle, size = 10;
    i = 0, j = 0;
    while (low <= high) 
    {
        middle = (low + high)/2;
        if (strcmp(searchKey , s[middle].array) == 0 ) {
            size = size/2;
            printf("\nIt exists.\n");
            main();
            }
        else if (strcmp(searchKey , s[middle].array) < 0 ) {
            high = middle - 1;
                size = size/2;
            }
        else {
            low = middle + 1;
            size = size/2;       
            }
        
    }
    printf("\nDoes not exist\n");
    main();
}

//!Function to insert array into Linked List
void insert(StructPtr *sPtr, char array[20], int value1, int value2, double value3)
{
    //!Declare pointers
	StructPtr newPtr; 
	StructPtr previousPtr; 
	StructPtr currentPtr; 
	newPtr = malloc( sizeof( Struct ));

    //!IF statement to insert values into linked list
	if ( newPtr != NULL )  
	{
		strcpy(newPtr->array,array);
        newPtr->value1 = value1;
        newPtr->value2 = value2;
        newPtr->value3 = value3;
		newPtr->next = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;
		
        //!While loop to rearrange nodes in alphabetical order
		while ( currentPtr != NULL && strcmp(array,currentPtr->array) > 0)
		{
			previousPtr = currentPtr; 
			currentPtr = currentPtr->next; 
		} 
		
        //!IF statement to connect nodes
		if ( previousPtr == NULL )
		{
			newPtr->next = *sPtr;
			*sPtr = newPtr;
		} 
		else   
		{
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
		} 
	} 
	else
	{
		printf( "No memory available.\n");
	}
}

//!Function to display nodes
void displayNode(StructPtr currentPtr)
{
    int i;
    while (currentPtr != NULL)
    {
        printf("\nArray: %s   Integer1: %d    Integer2: %d    Double: %.2lf\n", currentPtr->array, currentPtr->value1, currentPtr->value2, currentPtr->value3);
        currentPtr = currentPtr->next;
    }
    main();
}