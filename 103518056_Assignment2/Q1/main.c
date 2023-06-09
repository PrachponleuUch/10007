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


int main()
{
    //!Declare variables
    int userInput, value1, value2, value3, ascORdes, searchInput, sortUserInput;
    char array[20];
    StructPtr startPtr = NULL;
    //!Call to readFile function
    readFile();
    //!Call to menu function
    userInput = menu();
    //!Loop for switch case
    while(1)
    {
        //!Switch case for user input
        switch(userInput)
        { 
            case 1:
                displayArray();
                break;
            case 2:
                ascORdes = AscORDes();
                sortUserInput = SortInput();
                Sort(sortUserInput, ascORdes);
                break;
            case 3:
                searchInput = SearchInput();
                Search(searchInput);
                break;
            case 4:
                for(int i=0; i<SIZE; i++)
                {
                    insert(&startPtr, s[i].array, s[i].value1, s[i].value2, s[i].value3);
                }
                displayNode(startPtr);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
            printf("\nPlease enter a valid option.\n");
            main();
            break;
        }
    }
}
