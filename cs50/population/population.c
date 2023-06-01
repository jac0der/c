#include <cs50.h>
#include <stdio.h>

int getSize(int minimum, string tag, char startend);
int calculateYears(int start_size, int end_size);

int main(void)
{
    int minimum_size = 9;
    int start_size;
    int end_size;
    int years = 0;

    // TODO: Prompt for start size
    start_size = getSize(minimum_size, "Start size: ", 's');

    // TODO: Prompt for end size
    end_size = getSize(start_size, "End size: ", 'e');

    // TODO: Calculate number of years until we reach threshold
    years = calculateYears(start_size, end_size);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int getSize(int minimum, string tag, char startend)
{
    int size;

    do
    {
        size = get_int("%s", tag);

        /*
            cannot have the same end size as the start size.
            so years would be 0, since we are already at the end size.
        */
        if (startend == 'e' && size == minimum)
        {
            size = 0;
            break; // exit loop
        }
    }
    while (size < minimum);

    return size;
}

int calculateYears(int start_size, int end_size)
{
    int years = 0;

    // checking for when threshold is reached
    while (start_size < end_size)
    {
        start_size = ((start_size + (start_size / 3)) - (start_size / 4));
        years++;
    }

    return years;
}

