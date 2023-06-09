#include <iostream>

using namespace std;
//!Declare global variables
int array[20];
int Sum1 = 0;
int Sum2 = 0;

//!Function prototypes
void sum1(int);
void sum2(int);
void checksum(int);

int main()
{
    //!Declare variables
    int temp, i, j;
    //!Ask for input from user
    cout << "Enter integers: \n";
    //!For loop to validate and insert values into array
    for (i = 0; i<20 ; i++)
    {
        cin >> temp;
        if (temp == -1)
            break;
        else
            array[i] = temp;
    }
    //!For loop to display array
    for (j = 0; j<i ; j++)
    {
        cout <<array[j] <<"---->";
    }
    cout<< "NULL\n";

    sum1(i);
    sum2(i);
    checksum(i);
}

//!Function to double every 2nd element from end of array excluding the last element of the array, sum those values and if the new values is more than 1 digits, sum of its digits will be the value for that element
void sum1(int size)
{
    int i, j, num = 0, m = 0, newNum = 0;
    for (i=size; i>=0; i = i-2)
    {
        array[i] = 2*array[i];
    }
    
    for (i=size; i>=0; i = i-2)
    {
        if (array[i]>=10)
        {
            num = array[i];
            while(num>0)
            {
                m = num%10;
                newNum += m;
                num = num/10;
                if (newNum >= 10)
                {
                    newNum = newNum%10;
                }
            }
            array[i] = newNum;
            m = 0, newNum = 0, num = 0; 
        }
    }
    cout << "\nSum1 =";
    for (i=0; i<size; i = i+2)
    {
        cout <<array[i] <<" + ";
        Sum1 += array[i];
    }

    cout<< "NULL = "<< Sum1;
}

//!Function to sum the left over value from sum1
void sum2(int size)
{
    int i;
    cout << "\nSum2 =";
    for (i=1; i<size-1; i = i+2)
    {
        cout <<array[i] <<" + ";
        Sum2 += array[i];
    }

    cout << "NULL = "<< Sum2;
}

//!Function to check if the credit card is valid by summing sum1 and sum2, times it by 9 and compare the last digit of the product with the last digit of the credit card number to validate
void checksum(int size)
{
    int total = 0, checksum = 0;
    total = Sum1 + Sum2;
    cout << "\nTotal =" << Sum1 << " + " << Sum2 << " = " << total;
    cout << "\n" << total;
    total = total*9;
    cout << " * 9 = "<< total;

    checksum = total%10;
    cout <<"\n"<<checksum << " is the check sum digit.";
    
    if (array[size-1] == checksum)
    {
        cout << "\n\nThis is a valid card.\n";
    }
    else
    {
        cout << "\n\nThis is not a valid card.\n";
    }
}