#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

/*
    Linear search implementation to find an element in a list
    @datetime:: September 25, 2023 11:16 am (UTC-5)
    @lastModified:: September 26, 2023 5:09 am (UTC-5)
    @author:: jac0der
"""
*/

// define list maximum elements
const int LISTLENGTH = 15;

// accept command line arguments
int main(int argc, string argv[])
{
    // ensure 1 argument is passed at commannd prompt
    if(argc == 1 || argc > 2)
    {
        printf("Invalid input for %s\n", argv[0]);
        return 1;
    }

    int search_list[] = {11, 23, 8, 14, 30, 9, 6, 17, 22,
                28, 25, 15, 7, 10, 19};
    
    // loop through each element until target is found
    for(int i = 0; i < LISTLENGTH; i++)
    {
        if(search_list[i] == atoi(argv[1]))
        {  
            printf("Target %s is in list\n", argv[1]);
            return 0;
        }
    }
    
    printf("Target %s is not in list\n", argv[1]);
    return 1;

}