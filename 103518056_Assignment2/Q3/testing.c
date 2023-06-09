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

typedef struct TV{
    int id;
    char name[50];
    struct TV *next;
} TV;

typedef TV *TVptr;
TVptr startPtr = NULL;
TVptr headPtr = NULL;
TVptr tailPtr = NULL;
TVptr topPtr = NULL;
TV tv;
int ii = 0; 
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
void Free();

int main()
{    
    readTVs();
    menu();
}

void readTVs()
{
    
    FILE *fp = fopen("text.txt","r");

    while(!(feof(fp)))
    {
        fscanf(fp,"%d",&tv.id);
        fgets (tv.name, 50, fp);
        //fscanf(fp, "%[^\n]s", tv.name);
        Insert(&startPtr);
        enQ();
    }
    fclose(fp);
}


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
		
        //!While loop to rearrange employee details by name in alphabetical order
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

void menu()
{
    int userInput;
    //readTVs();
    printf("\n(1) Display the current stock of TVs \n");
    printf("(2) Add a new TV to stock \n");
    printf("(3) Display next order information  \n");
    printf("(4) Display all orders \n");
    printf("(5) Add order to queue  \n");
    printf("(6) Process the next order \n");
    printf("(7) Cancel last order  \n");
    printf("(8)  Display info of last order  \n");
    printf("(9) Update TV file\n");
    printf("(10) Quit program  \n");

    printf("Please choose an option: \n");
    scanf("%d", &userInput);

    while(1)
    {
        switch(userInput)
        {
            case 1:
            //readTVs();
            Display();
            break;
            case 2:
            Add();
            break;
            case 3:
            ii++;
            //printf("--------->%d", ii);
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

void Add()
{
    int choice;
    //char name[50] = {0}, id[50] = {0};
    //FILE *fp = fopen("text.txt","a");
    while(1)
    {
        printf("Enter id:\n");
        scanf("%d", &tv.id);

        //printf("Enter name:\n");
        //scanf(" %s", tv.name);
        printf("Enter name (press space before entering name):\n");
        getchar();
        fflush(stdin);
        fgets(tv.name, 50, stdin);
        //fflush(stdin);

        // fprintf(fp,"\n%s",id);
        // fprintf(fp," %s",name);
        //Free();
        Insert(&startPtr);
        //readTVs();

        printf("Enter '0' to exit or any other number to continue: \n");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
    }
    //fclose(fp);
    //readTVs();
    //Display();
    menu();
}

void enQ(  )
{
	TVptr newPtr; /* pointer to new node */
	newPtr = malloc( sizeof( TV ));
	if ( newPtr != NULL) /* is space available */
	{
		newPtr->id = tv.id;
        strcpy(newPtr->name, tv.name);
		newPtr->next = NULL;
/* if empty, insert node at head */
		if ( headPtr == NULL)
		{
			headPtr = newPtr;
		} 
		else
		{
			tailPtr->next = newPtr;
		}
        tailPtr = newPtr;
	} /* end if */
	else
	{
		printf( "%c not inserted. No memory available.\n", newPtr->name);
	}/* end else */
}/* end function enqueue */

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

void enQinput()
{
    int choice;
    while(1)
    {
        printf("Enter name:\n");
        scanf("%s", tv.name);
        // printf("Enter name (press space before entering name):\n");
        // getchar();
        // fgets(tv.name, 50, stdin);

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

    //printf("------------%d %s", topPtr->id, topPtr->name);
    menu();
}

void delete(  )
{
	TVptr previousPtr; /* pointer to previous node in list*/
	TVptr currentPtr; /* pointer to current node in list*/
	//ListNodePtr tempPtr=*sPtr; /* temporary node pointer*/
	/* delete first node*/
	TVptr tempPtr= startPtr;
	if ( strcmp(tv.name , (startPtr )->name) == 0 )
	{
		startPtr = ( startPtr )->next; /* de-thread the node*/
		free( tempPtr ); /* free the de-threaded node*/
		
	} /* end if*/
	else
	{
		previousPtr = startPtr;
		currentPtr = ( startPtr )->next;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && strcmp(currentPtr->name, tv.name) != 0)
		{
			previousPtr = currentPtr; /* walk to ...*/
			currentPtr = currentPtr -> next; /*... next node*/
		} /*	end while*/
		/* delete node at currentPtr*/
		if ( currentPtr != NULL )
		{
			tempPtr = currentPtr;
			previousPtr->next = currentPtr->next;
			free( tempPtr );
			
		} /* end if*/
	} /* end else*/
	
} /* end function delete*/
/* return 1 if the list is empty, 0 otherwise*/

void stackToList()
{
    tv.id = topPtr->id;
    strcpy(tv.name, topPtr->name);
    Insert(&startPtr);
    topPtr = topPtr->next;
    menu();
}

void DisplayStack()
{
    printf("\nLast order:\nTV's Id: %d \nTV's Name: %s", topPtr->id, topPtr->name);
    topPtr = topPtr->next;
    main();
}

void UpdateFile()
{
    FILE *fp = fopen("text.txt","w");
    TVptr temp = startPtr;
    while(temp!=NULL)
    {
        fprintf(fp,"%d", temp->id);
        fflush(stdout);
        fprintf(fp," %s", temp->name);
        fflush(stdout);
        temp = temp->next;
    }
    main();
}

void Free()
{
    TVptr temp;
    while(startPtr!=NULL)
    {
        temp = startPtr;
        startPtr = startPtr->next;
        free(temp);
    }
}