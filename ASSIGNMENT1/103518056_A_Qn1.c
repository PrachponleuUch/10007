/*
Name: Prachponleu Uch
Student Number: 103518056
Unit: Developing Technical Software
Unit Code: COS10007
*/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

//!Declare self referential structure with letter as it element
struct studentname  
{ 
char letter; 
struct studentname *next; 
}; 

typedef struct studentname STUDENTName; 

//!Pointer for STUDENTName
typedef STUDENTName *STUDENTNamePtr;

void displayList(STUDENTNamePtr startPtr);

int main()
{
    //!Name: Prachponleu Uch
    //!Declare pointers
    STUDENTNamePtr newPtr;
    STUDENTNamePtr startPtr;
    STUDENTNamePtr tempPtr;
    STUDENTNamePtr P1;
    STUDENTNamePtr P2;
    STUDENTNamePtr P3;
    //!Adding U to the list
    newPtr = (STUDENTName*)malloc(sizeof(STUDENTName));
    newPtr->letter = 'U';
    newPtr->next = NULL;
    startPtr = newPtr;
    P1 = newPtr;
    //!Adding c before U
    newPtr = (STUDENTName*)malloc(sizeof(STUDENTName));
    newPtr->letter = 'c';
    newPtr->next = startPtr;
    startPtr = newPtr;
    //!Adding h between c and U
    newPtr = (STUDENTName*)malloc(sizeof(STUDENTName));
    newPtr->letter = 'h';
    newPtr->next = P1;
    startPtr->next = newPtr;
    P2 = newPtr;
    //!Adding P between h and U
    newPtr = (STUDENTName*)malloc(sizeof(STUDENTName));
    newPtr->letter = 'P';
    newPtr->next = P1;
    P2->next = newPtr;
    P3 = newPtr; 
    //!Adding r between p and U
    newPtr = (STUDENTName*)malloc(sizeof(STUDENTName));
    newPtr->letter = 'r';
    newPtr->next = P1;
    P3->next = newPtr;
    //!Print output
    displayList(startPtr);
    printf("NULL");
}

//!Display list in alphabetical order
void displayList(STUDENTNamePtr startPtr)
{
    //!While loop to print letter in the linked list
    while(startPtr != NULL)
    {
        printf("%c-->", startPtr->letter);
        startPtr=startPtr->next;
    }
}