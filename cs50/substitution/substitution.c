#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool validateKey(string key);
void encryptPlainText(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (argc == 2)
    {
        string key = argv[1];

        if (!validateKey(key))
        {
            return 1;
        }

        string plainText = get_string("plaintext: ");

        encryptPlainText(plainText, key);

        return 0;
    }
}

bool validateKey(string key)
{
    bool isKeyValid = true;
    int key_length = strlen(key);

    // check length of cipher key
    if (key_length < 26 || key_length > 26)
    {
        isKeyValid = false;
        printf("Key must contain 26 characters.\n");
    }

    // ensure all letters in key are alphabetic
    for (int i = 0; i < key_length; i++)
    {
        // if a non-alphabetic letter was found
        if (!isalpha(key[i]))
        {
            isKeyValid = false;
            printf("Invalid Key - contains non-alphabetic character(s).\n");
            break;
        }

        // inner loop to check each char of key against itself for duplication.
        for (int j = 0; j < key_length; j++)
        {
            if (i != j && tolower(key[i]) == tolower(key[j]))
            {
                isKeyValid = false;
                printf("Invalid Key - duplicated character(S).\n");
                break;
            }
        }

        // duplicated characters exists
        if (!isKeyValid)
        {
            break;
        }
    }

    return isKeyValid;
}

void encryptPlainText(string plaintext, string key)
{
    string cipher = "";
    int index;
    char curr_char;

    const char UPPER_LOWERBOUND = 'A';
    const char LOWER_LOWERBOUND = 'a';

    int plainTextLength = strlen(plaintext);

    char cipher_letters[plainTextLength];
    /*
        1. loop through the plain text.
        2. determine if character is alphabetical and either upper or lowercase.
        3. get the ASCII number equivalent and subtract to get the index of the letter
           within the 26 letter alphabet.
        4. use the index to pull from the key string (array of strings).
        5. formulate cipher text.
    */

    for (int i = 0; i < plainTextLength; i++)
    {
        curr_char = plaintext[i];

        // preserve spacing
        if (isspace(curr_char))
        {
            cipher_letters[i] = curr_char;
            continue; // go to next iteration of loop
        }

        if (isalpha(curr_char))
        {
            if (islower(curr_char)) // preserve lowercase
            {
                index = curr_char - LOWER_LOWERBOUND;
                cipher_letters[i] = tolower(key[index]);
            }
            else // preserve uppercase
            {
                index = curr_char - UPPER_LOWERBOUND;
                cipher_letters[i] = toupper(key[index]);
            }
        }
        else
        {
            cipher_letters[i] = curr_char;
        }
    }

    // set end of cipher string
    cipher_letters[plainTextLength] = '\0';

    // print cipher text
    printf("ciphertext: %s\n", cipher_letters);
}