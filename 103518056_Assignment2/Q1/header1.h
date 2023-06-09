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
#define SIZE 10


//!Create structure for struct with array value1 value2 value3 as its elements
typedef struct Struct{
    char array[20];
    int value1;
    int value2;
    double value3;
    struct Struct *next;
} Struct;

//!Set struct array size to SIZE
Struct s[SIZE];
typedef Struct *StructPtr;
