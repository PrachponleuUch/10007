/*
Name: Prachponleu Uch
Student Number: 103518056
Unit: Developing Technical Software
Unit Code: COS10007
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//!Declare self referential struct TV with id name and *next as its elements
typedef struct TV{
    int id;
    char name[50];
    struct TV *next;
} TV;

//!Declare global variables
typedef TV *TVptr;
TVptr startPtr = NULL;
TVptr headPtr = NULL;
TVptr tailPtr = NULL;
TVptr topPtr = NULL;
TV tv;
int ii = 0; 

//!Function prototypes
void readTVs();
void Insert(TVptr *sPtr);
void menu();
void Display();
void Add();
void enQ();
int deQ(int);
void deQall();
void enQinput();
void Push();
void delete();
void stackToList();
void DisplayStack();
void UpdateFile();

int main()
{    
    //!Call to readTVs function
    readTVs();
    //!Call to menu function
    menu();
}

//!Function to read details from file and insert them into linked list and queue
void readTVs()
{
    
    FILE *fp = fopen("text.txt","r");

    while(!(feof(fp)))
    {
        fscanf(fp,"%d",&tv.id);
        fgets (tv.name, 50, fp);
        Insert(&startPtr);
        enQ();
    }
    fclose(fp);
}

//!Function to insert TV details into linked list
void Insert(TVptr *sPtr)
{
    //!Declare pointers
	TVptr newPtr; 
	TVptr previousPtr; 
	TVptr currentPtr; 
	newPtr = malloc( sizeof( TV ));

    //!IF statement to insert values into linked list
	if ( newPtr != NULL )  
	{
		strcpy(newPtr->name,tv.name);
        newPtr->id = tv.id;
		newPtr->next = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;
		
        //!While loop to rearrange details in alphabetical order
		while ( currentPtr != NULL && strcmp(tv.name,currentPtr->name) > 0)
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

//!Function to display options and ask user for input
void menu()
{
    int userInput;
    printf("\n(1) Display the current stock of TVs \n");
    printf("(2) Add a new TV to stock \n");
    printf("(3) Display next order information  \n");
    printf("(4) Display all orders \n");
    printf("(5) Add order to queue  \n");
    printf("(6) Process the next order \n");
    printf("(7) Cancel last order  \n");
    printf("(8) Display info of last order  \n");
    printf("(9) Update TV file\n");
    printf("(10) Quit program  \n");

    printf("Please choose an option: \n");
    scanf("%d", &userInput);

    while(1)
    {
        switch(userInput)
        {
            case 1:
            Display();
            break;
            case 2:
            Add();
            break;
            case 3:
            ii++;
            deQ(ii);
            break;
            case 4:
            deQall();
            break;
            case 5:
            enQinput();
            break;
            case 6:
            Push();
            break;
            case 7:
            stackToList();
            break;
            case 8:
            DisplayStack();
            break;
            case 9:
            UpdateFile();
            break;
            case 10:
            exit(0);
            break;
            default:
            break;
        }
    }
}

//!Function to display linked list
void Display()
{
    printf("\nEmployees' Information:\n");
    TVptr tempPtr = startPtr;
    while(tempPtr!=NULL)
    {
        printf("\n\nTV's Name: %s", tempPtr->name); 
        printf("\nTV`s id: %d", tempPtr->id);
        tempPtr = tempPtr->next;
    }
    menu();
}

//!Function to get and add TV details to linked list
void Add()
{
    int choice;
    
    while(1)
    {
        
        printf("Enter name (press space before entering name):\n");
        getchar();
        fgets(tv.name, 50, stdin);
        
        printf("Enter id:\n");
        scanf("%d", &tv.id);
        

        Insert(&startPtr);
        

        printf("Enter '0' to exit or any other number to continue: \n");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
    }
    
    menu();
}

//!Function to add TV details to queue
void enQ(  )
{
	TVptr newPtr; 
	newPtr = malloc( sizeof( TV ));
	if ( newPtr != NULL) 
	{
		newPtr->id = tv.id;
        strcpy(newPtr->name, tv.name);
		newPtr->next = NULL;
		if ( headPtr == NULL)
		{
			headPtr = newPtr;
		} 
		else
		{
			tailPtr->next = newPtr;
		}
        tailPtr = newPtr;
	} 
	else
	{
		printf( "%c not inserted. No memory available.\n", newPtr->name);
	}
}

//!Function to print head node of queue
int deQ(int ii)
{
    int i = ii;
    TVptr tempPtr = headPtr;
    while (i>1)
    {
        tempPtr = tempPtr->next;
        i--;
    }
    printf("\n\nTV's Name: %s", tempPtr->name); 
    printf("\nTV`s id: %d", tempPtr->id);
    menu();
}

//!Function to print all nodes in queue
void deQall()
{
    TVptr tempPtr = headPtr;
    while(tempPtr!=NULL)
    {
        printf("\n\nTV's Name: %s", tempPtr->name); 
        printf("\nTV`s id: %d", tempPtr->id);
        tempPtr = tempPtr->next;
    }
    menu();
}

//!Function to get and add TV details to queue
void enQinput()
{
    int choice;
    while(1)
    {
        printf("Enter name:\n");
        scanf("%s", tv.name);
        
        printf("Enter id:\n");
        scanf("%d", &tv.id);


        enQ();
        
        printf("Enter '0' to exit or any other number to continue: \n");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
    }
    menu();
}

//!Function to add TV details to stack
void Push()
{
    TVptr newPtr, tempPtr;

    newPtr = malloc(sizeof(TV));
    newPtr->id =  headPtr->id;
    strcpy(newPtr->name,headPtr->name);
    newPtr->next = topPtr;
    topPtr = newPtr;

    tempPtr = headPtr;
    strcpy(tv.name, headPtr->name);
    delete();
    
    free(tempPtr);
    headPtr = headPtr->next;

    
    menu();
}

//!Function to delete node from linked list and rearrange linked list
void delete(  )
{
	TVptr previousPtr; 
	TVptr currentPtr; 
	TVptr tempPtr= startPtr;
	if ( strcmp(tv.name , (startPtr )->name) == 0 )
	{
		startPtr = ( startPtr )->next; 
		free( tempPtr );
		
	} 
	else
	{
		previousPtr = startPtr;
		currentPtr = ( startPtr )->next;
		while ( currentPtr != NULL && strcmp(currentPtr->name, tv.name) != 0)
		{
			previousPtr = currentPtr; 
			currentPtr = currentPtr -> next; 
		} 
		if ( currentPtr != NULL )
		{
			tempPtr = currentPtr;
			previousPtr->next = currentPtr->next;
			free( tempPtr );
			
		} 
	} 
	
}

//!Function to add top node of stack to linked list
void stackToList()
{
    tv.id = topPtr->id;
    strcpy(tv.name, topPtr->name);
    Insert(&startPtr);
    topPtr = topPtr->next;
    menu();
}

//!Function to display node in stack
void DisplayStack()
{
    printf("\nLast order:\nTV's Id: %d \nTV's Name: %s", topPtr->id, topPtr->name);
    topPtr = topPtr->next;
    main();
}

//!Function to update file with nodes in linked list
void UpdateFile()
{
    FILE *fp = fopen("text.txt","w");
    TVptr temp = startPtr;
    while(temp!=NULL)
    {
        fprintf(fp,"%d", temp->id);
        fprintf(fp,"%s", temp->name);
        temp = temp->next;
    }
    main();
}