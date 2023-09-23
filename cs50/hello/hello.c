#include <stdio.h>
#include<cs50.h>

int main(void)
{
    // receiving user input and storing in variable 'name'
    string name = get_string("What is your name? ");
    int age = get_int("Your age please: ");

    // printing entered name
    printf("hello, %s\n", name);
    printf("age, %i", age);
}