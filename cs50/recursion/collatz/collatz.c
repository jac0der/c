#include <cs50.h>
#include <stdio.h>

/*
    Recursive program that calculates how many steps it takes 
    to get to 1 if you start from n and recurse as indicated in README_COLLATZ.
    @datetime:: September 24, 2023 8:11 am (UTC-5)
    @author:: jac0der
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

    // print out number of steps.
    printf("Steps count is: %i", collatz(number));
}

/*
    Function to implement the Collatz Conjecture algorithm -
    which is to calculate the number of steps taken
    to get to 1, given a number n, using the algorithm
    for the collatz sequence, as outlined in the 
    README_COLLATZ read me file.
    @input:: value enetered by user
    @output:: number of steps taking to get to 1, from 
              a number n.
"""
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
    Function to determine if an integer is even or odd.
    Modulus operator wqas used to get the modulus of number / 2.  If there
    is no remainder, it means number is exactly
    divissible by 2, Thus number is even, otherwise odd.
    @input:: number entered by user.
    @output:: True if number is Even, otherwise False.
*/
bool isEven(int number)
{
    if( (number % 2) == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

