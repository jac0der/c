#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    // get input from user
    string text = get_string("Text ");

    // counting letters, words and sentences respectively
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // calculating letter and sentence average per 100 words.
    float L = ((float) letter_count / (float) word_count) * 100;
    float S = ((float) sentence_count / (float) word_count) * 100;

    // calculating the reading index - round to nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

/*
    function to count the amount of words
    in a given text.
*/
int count_letters(string text)
{
    int char_count = 0;
    char upperChar;
    const int ASCII_LOWER_BOUND = 'A'; // 65
    const int ASCII_UPPER_BOUND = 'Z'; // 90

    // loop through the string
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        /*
            check if character is a punctuation or space to ignore those characters...
            ispunct function checks the punctuation status of each character
            This function returns a non-zero int if c is punctuation and 0 if c is not punctuation.
        */
        if (ispunct(text[i]) != 0 || isspace(text[i]))
        {
            continue; // ignore this iteration and move unto next iteration of loop
        }

        /*
            ensure character is valid alphabetical character - either a - z / A - Z.
            uppercase each character.
        */
        upperChar = toupper(text[i]);

        // letter is between A - Z, so count letter
        if (upperChar >= ASCII_LOWER_BOUND && upperChar <= ASCII_UPPER_BOUND)
        {
            char_count++;
        }
    }

    return char_count;
}

/*
    function to count the amount of words
    in a given text.
*/
int count_words(string text)
{
    int word_count = 0;
    bool is_char_found = false;

    // loop through the string
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        /*
            if I reach a space and a character was previously found,
            then I have come to the end of a word, so increment word_count,
            and set is_char_found back to false, to restart the cycle
            of checking for a word after a space.
        */
        if (isspace(text[i]) && is_char_found)
        {
            word_count++;
            is_char_found = false;
        }
        else if (!isspace(text[i]))
        {
            // no space - thus a character was found, meaning a word was started
            // or i'm in a word.
            is_char_found = true;
        }
    }

    /*
        add an extra 1 to word_count for cases where text
        doesn't end with a space, to cater for last word in text.
    */
    if (is_char_found)
    {
        word_count++;
    }

    return word_count;
}

/*
    function to count the amount of sentences
    within a given text.
*/
int count_sentences(string text)
{
    int sentence_count = 0;
    bool is_char_found = false;

    // loop through the string
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        /*
            check if character is a punctuation, then test for the type
            of punctuation and if a character was previously found.
        */
        if ((ispunct(text[i]) && (text[i] == '?' || text[i] == '!' || text[i] == '.')) && is_char_found)
        {
            sentence_count++;
            is_char_found = false;
        }
        else if (!ispunct(text[i]) && !isspace(text[i]))
        {
            is_char_found = true;
        }
    }

    return sentence_count;
}