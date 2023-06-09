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

//!Create structure for personTag with name and age as its elements
typedef struct personTag
{ 
    char name[20];
    int age;
} personTag;

//!Create structure for officialTag with deptId, cmpName and salary as its elements
typedef struct officialTag
{
    int deptId;
    char cmpName[20];
    double salary;
} officialTag;

//!Create a nested self referential structure for employeeTag with personTag structure and officialTag structure as its elements
typedef struct employeeTag
{
    personTag personTag;
    officialTag officialTag;
    struct employeeTag *next;
} employeeTag;

//!Pointer for employeeTag
typedef employeeTag *employeeTagPtr;

//!Function prototypes
void introduction();
employeeTagPtr readFile();
int menu();
void insert(employeeTagPtr *sPtr, char perName[20], int age, int deptId, char offName[20], double salary);
void displayEmployee(employeeTagPtr);
void searchEmployee(employeeTagPtr *sPtr, char perName[20]);
void findMaximum(employeeTagPtr startPtr);
void lowerSalary(employeeTagPtr startPtr);
void averageSalary(employeeTagPtr startPtr, char cmpName[20]);
void updateFile(employeeTagPtr startPtr);

int main()
{
    employeeTagPtr startPtr = NULL;
    int userInput = 0;
    char perName[20], cmpName[20];
    introduction(); //!Call to function to print introduction
    userInput = menu(); //!Call to function to get user input
    startPtr = readFile(); //!Call to function to read file and return pointer

    //!Infinite loop to follow user input
    while(1)
    {
        switch(userInput)
        { 
            case 1:
            displayEmployee(startPtr);
            break;
            case 2:
            printf("Enter a name to search: \n");
            scanf("%s", perName);
            searchEmployee(&startPtr, perName);
            break;
            case 3:
            findMaximum(startPtr);
            break;
            case 4:
            lowerSalary(startPtr);
            break;
            case 5:
            printf("Enter a company name to search: \n");
            scanf("%s", cmpName);
            averageSalary(startPtr, cmpName);
            break;
            case 6:
            updateFile(startPtr);
            break;
            case 7:
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

//!Print welcome message
void introduction()
{
    printf("\nHello! Welcome to C Programming!\n");
}

//!Display menu and get user input
int menu()
{
    int userInput;

    printf("\n(1) Display employees' details \n");
    printf("(2) Search for an employee's salary \n");
    printf("(3) Find the details of employee with the largest salary  \n");
    printf("(4) Find the details of all employees having salary less than 5000 \n");
    printf("(5) Find the average salary of a company  \n");
    printf("(6) Add new employee to the record \n");
    printf("(7) Quit program  \n");

    printf("Please choose an option: \n");
    scanf("%d", &userInput);

    return userInput;
}

//!Read information from employee.txt file
employeeTagPtr readFile()
{
    employeeTagPtr startPtr = NULL;
    char perName[20], offName[20];
    int age, deptId;
    double salary;
    //!Assign a pointer to read file
    FILE *fp = fopen("employee.txt","r");

    //!While loop to scan until end of file and call insert function to insert value in to linked list 
    while (!feof(fp))
    {
        
        fscanf(fp,"%s",perName);
        fscanf(fp,"%d",&age);
        fscanf(fp,"%d",&deptId);
        fscanf(fp,"%s",offName);
        fscanf(fp,"%lf",&salary);
        insert(&startPtr, perName, age, deptId, offName, salary);
    }

    //!Close file
    fclose(fp);
    return startPtr;
}

//!Insert values into a linked list and rearrange it in alphabetical order
void insert(employeeTagPtr *sPtr, char perName[20], int age, int deptId, char offName[20], double salary)
{
    //!Declare pointers
	employeeTagPtr newPtr; 
	employeeTagPtr previousPtr; 
	employeeTagPtr currentPtr; 
	newPtr = malloc( sizeof( employeeTag ));

    //!IF statement to insert values into linked list
	if ( newPtr != NULL )  
	{
		strcpy(newPtr->personTag.name,perName);
        newPtr->personTag.age = age;
        strcpy(newPtr->officialTag.cmpName,offName);
        newPtr->officialTag.deptId = deptId;
        newPtr->officialTag.salary = salary;
		newPtr->next = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;
		
        //!While loop to rearrange employee details by name in alphabetical order
		while ( currentPtr != NULL && strcmp(perName,currentPtr->personTag.name) > 0)
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

//!Display employee details from linked list
void displayEmployee(employeeTagPtr currPtr)
{
    printf("\nEmployees' Information:\n");

    //!While loop to print all employees details
    while(currPtr!=NULL)
    {
        printf("Employee`s Name: %s\nEmployee`s Age: %d\nEmployee`s DeptId: %d\nEmployee`s Company: %s\nEmployee`s salary: $%.2lf\n\n",currPtr->personTag.name,currPtr->personTag.age,currPtr->officialTag.deptId,currPtr->officialTag.cmpName,currPtr->officialTag.salary);
        currPtr=currPtr->next;
    }
    main();
}

//!Search for employee details inside the linked list and display them
void searchEmployee(employeeTagPtr *sPtr, char perName[20])
{
    //!Declare pointer
	employeeTagPtr previousPtr; 
	employeeTagPtr currentPtr; 
	employeeTagPtr tempPtr=*sPtr;

    //!IF statement to search for employee name and print output
	if ( strcmp(perName,(*sPtr)->personTag.name) == 0)
	{
        printf("Employee`s Name: %s\nEmployee`s Age: %d\nEmployee`s DeptId: %d\nEmployee`s Company: %s\nEmployee`s salary: %.2lf\n\n",(*sPtr)->personTag.name,(*sPtr)->personTag.age,(*sPtr)->officialTag.deptId,(*sPtr)->officialTag.cmpName,(*sPtr)->officialTag.salary);
	}
	else
	{
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->next;
		
        //!While loop to find a matching name to the user input
		while ( currentPtr != NULL && strcmp(perName,currentPtr->personTag.name) != 0)
		{
            previousPtr = currentPtr; 
			currentPtr = currentPtr -> next; 
		}

        //!IF statement to check if its the end of th linked list
        if ( currentPtr != NULL )
		{
			tempPtr = currentPtr;
            printf("\nEmployee`s Name: %s\nEmployee`s Age: %d\nEmployee`s DeptId: %d\nEmployee`s Company: %s\nEmployee`s salary: $%.2lf\n\n",currentPtr->personTag.name,currentPtr->personTag.age,currentPtr->officialTag.deptId,currentPtr->officialTag.cmpName,currentPtr->officialTag.salary);
            main();
		}
        else
        {
            printf("\nEmployee`s name doesn't exist.\n\n");
            main();
        } 
    }
}

//!Search for employee details with the highest salary inside the linked list
void findMaximum(employeeTagPtr startPtr)
{
    employeeTagPtr tempPtr;
    double maxSalary = 0;

    //!While loop to compare employee salary
    while (startPtr != NULL)
    {
        //!IF statement to compare employee salary and store it inside temporary variable/pointer
        if(startPtr->officialTag.salary>maxSalary)
        {
            maxSalary = startPtr->officialTag.salary;
            tempPtr = startPtr; 
        }
        startPtr = startPtr->next;
    }
    printf("Details of employee with the largest salary:\nEmployee`s Name: %s\nEmployee`s Age: %d\nEmployee`s DeptId: %d\nEmployee`s Company: %s\nEmployee`s salary: $%.2lf\n\n",tempPtr->personTag.name,tempPtr->personTag.age,tempPtr->officialTag.deptId,tempPtr->officialTag.cmpName,tempPtr->officialTag.salary);
    main();
}

//!Search for employee details with the salary lower than 5000 inside the linked list
void lowerSalary(employeeTagPtr startPtr)
{
    employeeTagPtr tempPtr;
    int salaryCheck = 5000;

    //!While loop to find employee/s with salary less than 5000
    while (startPtr != NULL)
    {
        //!IF statement to compare employees salary with the 5000 threshold and store them inside a temporary pointer then print them out
        if(startPtr->officialTag.salary<salaryCheck)
        {
            tempPtr = startPtr;
            printf("Details of employee with salary less than 5000:\nEmployee`s Name: %s\nEmployee`s Age: %d\nEmployee`s DeptId: %d\nEmployee`s Company: %s\nEmployee`s salary: $%.2lf\n\n",tempPtr->personTag.name,tempPtr->personTag.age,tempPtr->officialTag.deptId,tempPtr->officialTag.cmpName,tempPtr->officialTag.salary);
        }
        startPtr = startPtr->next;
    }
    main();
}

//!Search for company average salary based on the linked list
void averageSalary(employeeTagPtr startPtr, char cmpName[20])
{
    double avgSalary = 0, allSalary = 0;
    int count = 0;

    //!While loop to find company name within the linked list
    while (startPtr != NULL)
    {
        //!IF statement to compare company names within the linked list with the user input
        if(strcmp(cmpName,startPtr->officialTag.cmpName) == 0)
        {
            allSalary = allSalary + startPtr->officialTag.salary;
            count++;
        }
        startPtr = startPtr->next;
    }
    avgSalary = allSalary/count;

    //!IF statement to see if the user input exist inside the linked list
    if (allSalary == 0)
    {
        printf("There is no such company in the list.");
    }
    else
    {
    printf("\n\nAverage Salary: $%.2lf\n\n", avgSalary);
    }
    main();
}

//!Update file and add the new employee details into the linked list following the alphabetical order
void updateFile(employeeTagPtr startPtr)
{
    //!Assign a pointer to append file
    FILE *fp = fopen("employee.txt","a");
    char perName[20] = {0}, age[20] = {0}, deptId[20] = {0}, cmpName[20] = {0}, salary[20] = {0};
    int choice = 0;

    printf("Please enter new employee information\n");
    
    //!Infinite loop to add new employee details
    while(1)
    {
        printf("Enter name:\n");
        scanf("%s", perName);
        
        printf("Enter age:\n");
        scanf("%s", age);
        
        printf("Enter deptId:\n");
        scanf("%s", deptId);
        
        printf("Enter company's name:\n");
        scanf("%s", cmpName);
        
        printf("Enter salary:\n");
        scanf("%s", &salary);
        
        fprintf(fp,"\n%s\n",perName);
        fprintf(fp,"%s\n",&age);
        fprintf(fp,"%s\n",&deptId);
        fprintf(fp,"%s\n",cmpName);
        fprintf(fp,"%s",&salary);

        printf("Enter '0' to exit or any other number to continue: \n");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
    }
    //!Close file
    fclose(fp);
    startPtr = readFile();    
    displayEmployee(startPtr);
}