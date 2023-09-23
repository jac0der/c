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

double factorial(int number)
{
    double fact;

    // 1! is 1 so return 1
    if(number == 1)
    {
        return number;
    }

    fact = number * factorial(number -1);

    return fact;
}