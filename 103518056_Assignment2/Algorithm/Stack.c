/* A simple stack program*/
#include <stdio.h>
#include <stdlib.h>
/* self-referential structure*/
struct stackNode
{
	int data; /* define data as an int */
	struct stackNode *nextPtr; /* stackNode pointer*/
}; /* end structure stackNode */
typedef struct stackNode StackNode; /* synonym for struct stackNode */
typedef StackNode *StackNodePtr; /* synonym for  StackNode* */
/* prototypes*/
void push( StackNodePtr *topPtr, int info);
int pop( StackNodePtr *topPtr );
int isEmpty( StackNodePtr topPtr);
void printStack( StackNodePtr currentPtr );
void instructions( void);
/* function main begins program execution */
int main( void )
{
	StackNodePtr stackPtr = NULL; /*	points to stack top */
	unsigned int choice; /* user's menu choice */
	int value; /* int input by user*/
	instructions(); /* display the menu */
	printf( "%s", "?" );
	scanf( "%u" , &choice);
	/* while user does not enter 3 */
	while (choice != 3 )
	{
		switch (choice )
		{
			/* push value onto stack */
		case 1:
			printf( "%s", "Enter an integer: ");
			scanf( "%d", &value);
			push( &stackPtr, value);
			printStack( stackPtr );
			break;
			/* pop value off stack */
		case 2:
			/* if stack is not empty */
			if (!isEmpty( stackPtr))
			{
				printf( "The popped value is %d.\n", pop( &stackPtr ));
			} /* end if */
			printStack( stackPtr );
			break;
		default:
			puts( "Invalid choice.\n" );
			instructions();
			break;
		} /* end switch */
		printf( "%s", "?");
		scanf( "%u" , &choice);
	} /* end while */
	puts( "End of run" );
} /* end main */
/* display program instructions to user */
void instructions( void )
{
	puts( "Enter choice:\n"
	      "1 to push a value on the stack\n"
	      "2 to pop a value off the stack\n"
	      "3 to end program" );
} /* end function instructions */
/* insert a node at the stack top */
void push( StackNodePtr *topPtr, int info )
{
	StackNodePtr newPtr; /* pointer to new node */
	newPtr = malloc( sizeof( StackNode ));
	/* insert the node at stack top */
	if ( newPtr != NULL)
	{
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} /* end if */
	else  /* no space available */
	{
		printf( "%d not inserted. No memory available.\n", info);
	}/* end else */
} /* end function push */
/* remove a node from the stack top */
int pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr; /* temporary node pointer */
	int popValue; /* node value */
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr );
	return popValue;
} /* end function pop */
/* print the stack */
void printStack( StackNodePtr currentPtr )
{
	/* if stack is empty */
	if ( currentPtr == NULL )
	{
		puts( "The stack is empty.\n" );
	} /* end if */
	else
	{
		puts( "The stack is:" );
		/* while not the end of the stack */
		while ( currentPtr != NULL )
		{
			printf( "%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		} /* end while */
		puts(	"NULL\n");
	}/* end else */
} /* end function printList */
/* return 1 if the stack is empty, 0 otherwise */
int isEmpty( StackNodePtr topPtr )
{
	return topPtr == NULL;
} /* end function isEmpty */

