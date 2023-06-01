#include <cs50.h>
#include <stdio.h>


// function declarations
int getPyramidSize();
void generatePyramid(int size);
void printLeftPyramid(int space_count_threshold, int hash_count_threshold);
void printRightPyramid(int hash_count_threshold);



int main(void)
{
    /*
        prompt user for positive pyramid
        size and return size as input to
        the generatePyramid function.
    */
    generatePyramid(getPyramidSize());
}




int getPyramidSize()
{
    int pyramid_size = 0;

    do
    {
        pyramid_size = get_int("Pyramid size: ");
    }
    while (pyramid_size < 1 || pyramid_size > 8);

    return pyramid_size;
}

void generatePyramid(int pyramid_size)
{
    // spaces is 1 less than the size of the pyramid
    int left_space_count = pyramid_size - 1;

    // couinter to control loop to pprint hash - starting at printing 1 hash
    int hash_count = 1;

    // loop to control the printing of the
    // pyramid size entered by user.
    for (int i = 0; i < pyramid_size; i++)
    {
        // print left pyramid
        printLeftPyramid(left_space_count, hash_count);

        // decrement space print counter
        left_space_count--;

        // print separator space between pyramids
        printf("  ");

        // print right pyramid
        printRightPyramid(hash_count);

        // increment hash print counter
        hash_count++;

        // break to next line
        printf("\n");
    }
}

void printLeftPyramid(int space_count_threshold, int hash_count_threshold)
{
    // print spaces
    for (int k = 0; k < space_count_threshold; k++)
    {
        printf(" ");
    }

    // print hash
    for (int j = 0; j < hash_count_threshold; j++)
    {
        printf("#");
    }
}

void printRightPyramid(int hash_count_threshold)
{
    for (int j = 0; j < hash_count_threshold; j++)
    {
        printf("#");
    }
}