#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    function declarations
*/
bool only_digits(string key, string firstarg);
void rotate(string plaintext, int key);
char getCipherChar(char curr_char, int key, int next_char_index, char upper_bound, char lower_bound);

int main(int argc, string argv[])
{
    // ensure 2 arguments are passed into main
    if (argc == 1 || argc > 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (argc == 2)
    {
        string key = argv[1];

        // key failed validation so exit prgram.
        if (!only_digits(key, argv[0]))
        {
            return 1;
        }

        // convert valid key to integer
        int ikey = atoi(key);

        // prompt user for plaintext.
        string plaintext = get_string("plaintext:  ");

        // calculate caesar cipher and print out result
        rotate(plaintext, ikey);

        // successful return from program
        return 0;
    }
}

/*
    function to validate the key to ensure it is a valid
    positive digit/number
*/
bool only_digits(string key, string firstarg)
{
    bool isKeyValid = true;

    for (int i = 0, len = strlen(key); i < len; i++)
    {
        // once atleast 1 character that is not a digit is found, break loop and return false.
        if (!isdigit(key[i]))
        {
            isKeyValid = false;
            printf("Usage: %s key\n", firstarg);
            break;
        }
    }

    return isKeyValid;
}

/*
    function to calculate the resulting caesar cipher from
    plain text.
*/
void rotate(string plaintext, int key)
{
    const char UPPER_LOWERBOUND = 'A';
    const char LOWER_LOWERBOUND = 'a';

    const char UPPER_UPPERBOUND = 'Z';
    const char LOWER_UPPERBOUND = 'z';

    int cipher_length = strlen(plaintext);
    int next_char_index;

    char caesar_cipher[cipher_length];
    char curr_char;
    char cipherchar;

    // calculate the caesar cipher for each letter in plain text
    for (int i = 0; i < cipher_length; i++)
    {
        curr_char = plaintext[i];

        if (isalpha(curr_char))
        {
            if (islower(curr_char))
            {
                next_char_index = curr_char + key;

                cipherchar = getCipherChar(curr_char, key, next_char_index, LOWER_UPPERBOUND, LOWER_LOWERBOUND);
                caesar_cipher[i] = cipherchar;
            }
            else // uppercase
            {
                next_char_index = curr_char + key;

                cipherchar = getCipherChar(curr_char, key, next_char_index, UPPER_UPPERBOUND, UPPER_LOWERBOUND);
                caesar_cipher[i] = cipherchar;
            }
        }
        else
        {
            // preserve non-alphanumeric characters
            caesar_cipher[i] = curr_char;
        }
    }

    // set end of cipher string
    caesar_cipher[cipher_length] = '\0';

    // print cipher text
    printf("ciphertext: %s\n", caesar_cipher);
}

/*
    function to determine the shifted cipher character for the inputted character,
    whether lower case or upper case.
*/
char getCipherChar(char curr_char, int key, int next_char_index, char upper_bound, char lower_bound)
{
    char cipherchar;
    int difference;
    int alpha_modulus;
    const int ALPHA_TOTAL = 26;

    if (next_char_index > upper_bound)
    {
        /*
             get the integer difference between the next
             integer index/value for a character based on the added key value.
             This difference puts the check for the remainder from the end of
             wither the lowercase alphabet or uppercase alphabet.

             Then, from this remainder, the modulus of 26 is taken, since there
             are 26 characters in the alphabet, thus any equal divisions out from the 26
             means a looping back to the end charater of the alphabet, but the modulus remainder
             is then what is added to the first character in the alphabet to get the next
             cipher text.
        */
        difference = next_char_index - upper_bound;

        alpha_modulus = (difference % ALPHA_TOTAL);

        cipherchar = lower_bound + (alpha_modulus - 1);
    }
    else
    {
        cipherchar = curr_char + key;
    }

    return cipherchar;
}