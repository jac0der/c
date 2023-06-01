#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void printWinner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    printWinner(score1, score2);
}

/*
        loop through each scrabble word to get each letter.
        Decide on wether to use ASCII lower or Upper case - I decided on UPPERCASE.
        Use ASCII to determine the position of each letter within the alphabet which has 26 letters.
            This is done by remembering that 'A' maps to 65 in ASCII, thus printing the number for the
            letter gives its number equivalent, which may then have 65 (ASCII A value) subtracted from
            it to get the letter's position in the POINTS array.
        Use the letters position as index within the POINTS array to get the amount the letter is worth.
        Sum that amount to previous letter's sum.
        Also note the end of a string which is \0, thus loop to 1 less that the length of the string.
        return the total sum/worth for the word.
*/
int compute_score(string word)
{
    const int ASCII_LOWER_BOUND = 65; // A
    const int ASCII_UPPER_BOUND = 90; // Z
    int char_ascii_value;
    int sum = 0;
    int index;

    /*
        loop to 1 less than length of word in order to ignore the
        last string end character \0.
    */
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        /*
            get index of character in the POINTS array, by
            first converting char to uppercase, then subtracting
            65 (the ASCII number value map for uppercase A),
            from the char ASCII number mapping value.
        */
        char_ascii_value = toupper(word[i]);

        // ensure letter is an uppercase value - ignoring all other ASCII character values
        if (char_ascii_value >= ASCII_LOWER_BOUND && char_ascii_value <= ASCII_UPPER_BOUND)
        {
            index = char_ascii_value - ASCII_LOWER_BOUND;

            // totaling the points for each character in word.
            sum += POINTS[index];
        }
    }

    return sum;
}

void printWinner(int score1, int score2)
{
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}