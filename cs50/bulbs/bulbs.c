#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    function declarations.
*/
void getCharDecimals(string message, int decimals[]);
void decimalToBinary(int array_length, int decimals[], string binaries[]);
void display_bulb(int array_length, string binaries[]);
void print_bulb(int bit);

int main(void)
{
    // get message for encoding
    string message = get_string("Message: ");

    /*
        declare array of size message_length to hold decimal
        equivalents for each cahracter in message.

        Array is a reference type - so can be passed (by reference) to other
        functions and have its actual values updated within those
        function calls, unlike passing by value which pass a copy of a variable.
    */
    int array_length = strlen(message);

    // array to store decimal equivalent of each character in message.
    int message_decimals[array_length];

    // array to store the binary equivalent of the decimals for each character in message.
    string binary_equivalents[array_length];

    // convert message characters to decimal - pass array (message_decimals) by REFERENCE
    getCharDecimals(message, message_decimals);

    // convert each character decimal message equivalent to binary
    decimalToBinary(array_length, message_decimals, binary_equivalents);

    // print binary message
    display_bulb(array_length, binary_equivalents);
}

/*
    function to get the decimal equivalent for each character
    in the message, and store in decimals array.
*/
void getCharDecimals(string message, int decimals[])
{
    /*
        loop through each character in message to
        get the ASCII decimal equivalent.
    */
    for (int i = 0, len = strlen(message); i < len; i++)
    {
        decimals[i] = (int)message[i];
    }
}

/*
    function to convert the message decimal equivalents to their
    respective binary equivalents.
*/
void decimalToBinary(int array_length, int decimals[], string binaries[])
{
    const int BITS = 8;

    int curr_decimal;
    int remainder;
    char reverse_binary[] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};

    for (int j = 0; j < array_length; j++)
    {
        /*
            reset the memory location for the binary char values to set the new
            binary calculation values of next decimal.
        */
        char binary[] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};

        // get each decimal from decimal array
        curr_decimal = decimals[j];

        int counter = 0;

        do
        {
            // convert each decimal to binary
            remainder = curr_decimal % 2;
            curr_decimal /= 2;

            if (remainder == 0) // no remainder
            {
                binary[counter] = '0';
            }
            else // remainder
            {
                binary[counter] = '1';
            }

            counter++;
        }
        while (curr_decimal > 0);

        // reverse binary char array
        int reduce = BITS - 1;
        for (int i = 0; i < BITS; i++)
        {
            reverse_binary[reduce] = binary[i];
            reduce--;
        }

        /*
            copy contents of array of chars 'reverse_binary' to a different
            memory location to be used to set each index in the binaries
            string array of binary equivalents for each decimal.

            This is necessary so as not to have the same binary value
            for each index, because arrays are reference types which
            means the same memory location is updated in each of the iteration
            of the do...while loop above.

            So copy the calculated binary value to a different memory location
            using 'malloc'.
        */
        char *new_mem_loca_cpy = malloc(9);
        strcpy(new_mem_loca_cpy, reverse_binary);

        // set j-index to new copied calculated binary value
        binaries[j] = new_mem_loca_cpy;
    }
}

/*
    function to iterate over the binary equivalents of the messagge,
    and get each bit to be passed to the print_bulb function.
*/
void display_bulb(int array_length, string binaries[])
{
    string binary_equivalent;
    char charbit;
    int bit;
    int blength = 0;
    char buffer[9]; // store 8 bits for Decimal binary representation + \0

    // loop through each binary value.
    for (int k = 0; k < array_length; k++)
    {
        // print binary value to a string buffer to prevent changing
        sprintf(buffer, "%s", binaries[k]);
        binary_equivalent = buffer;
        blength = strlen(binary_equivalent);

        // loop through each binary digit
        for (int i = 0; i < blength; i++)
        {
            // get a bit
            charbit = binary_equivalent[i];

            switch (charbit)
            {
                case '0':
                    bit = 0;
                    break;

                case '1':
                    bit = 1;
                    break;
            }

            print_bulb(bit);
        }
        printf("\n");
    }
}

/*
    function to display to the user the resulting
    1's and 0's produced from the message.
*/
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
