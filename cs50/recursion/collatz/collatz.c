#include <cs50.h>
#include <stdio.h>

/*
    Recursive program that calculates how many steps it takes 
    to get to 1 if you start from n and recurse as indicated in README_COLLATZ.
*/

// function prototype definitions
int collatz(int number);
bool isEven(int number);

int main(void)
{
    // get input from user.
    int number = get_int("Enter number: ");

    if(number < 1)
    {
        printf("Invalid input");
        return 1;
    }

    printf("Steps count is: %i", collatz(number));
}

/*
    Function to implement the Collatz Conjecture algorithm
*/
int collatz(int number)
{
    int step_count = 0;

    // base case is met when number becomes 1, or is initially 1.
    if(number == 1)
    {
        return 0;
    }

    if(isEven(number))
    {
        step_count = 1 + collatz(number / 2);
    }
    else
    {
        step_count = 1 + collatz((3 * number) + 1);
    }

    return step_count;
}

/*
    Function to determine if a number is even or odd.
*/
bool isEven(int number)
{
    /*
        get modulus of number / 2.  If there
        is no remainder, it means number is exactly 
        divissible by 2, Thus number is even, otherwise odd.
    */ 
    if((number % 2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

