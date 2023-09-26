#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

const int LISTLENGTH = 15;
const int TARGET = 7;

int main(int argc, string argv[])
{
    if(argc == 0 || argc > 2)
    {
        printf("Invalid input for %s", argv[0]);
        return 1;
    }

    int search_list[] = {11, 23, 8, 14, 30, 9, 6, 17, 22,
                28, 25, 15, 7, 10, 19};
    
    for(int i = 0; i < LISTLENGTH; i++)
    {
        if(search_list[i] == atoi(argv[1]))
        {  
            printf("Target %s is in list", argv[1]);
            return 0;
        }
    }
    
    printf("Target %s is not in list", argv[1]);
    return 1;

}