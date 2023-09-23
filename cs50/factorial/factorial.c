#include <cs50.h>
#include <stdio.h>

/*
    C implementation of finding the Factorial of a number.
*/

// define function prototype
double factorial(int number);


int main(void)
{
    int number = get_int("Enter number: ");

    printf("Factorial of %i is: %f", number, factorial(number));

    return 0;
}

/***
    Function to fing the factorial of a number
    @input:: number to retrieve factorial for
    @output:: factorial of input number
*/
double factorial(int number)
{
    double fact;

    // 1! is 1 so return 1 - base case met
    if(number == 1)
    {
        return number;
    }

    // recursively call factorial on n - 1
    fact = number * factorial(number -1);

    return fact;
}