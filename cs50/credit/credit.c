#include <cs50.h>
#include <stdio.h>


long validateCarNumberLength(long card_number);
int getCardLength(long card_number);
string validateCardTypes(long number);
string performCheckSum(string card_type, long card_number);
bool calculateCheckSum(long card_numbner);





int main(void)
{
    long card_number = validateCarNumberLength(get_long("Number: "));
    /*
        prompt for credit card number and validate length.
        if length is a valid length for either AMEX/VISA/MASTERCARD
        proceed to validate the card and perform checksum, otherwise,
        card is invalid.
    */
    if (card_number != 0)
    {
        // validate first 2 digits of credit card
        string card_type = validateCardTypes(card_number);

        /*
            calculate checksum once credit card is either a potential
            VISA, AMEX or MASTERCARD
        */
        card_type = performCheckSum(card_type, card_number);

        // print AMEX/MASTERCARD/VISA/INVALID
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}




long validateCarNumberLength(long card_number)
{
    int digit_counter = 0;

    // length is 1, so false
    if (card_number == 0)
    {
        return 0;
    }

    // get the length of the card number - fractional part will be ignored
    digit_counter = getCardLength(card_number);

    // check the length of the card number entered
    if ((digit_counter == 13) || (digit_counter == 15) || (digit_counter == 16))
    {
        return card_number;
    }
    else
    {
        return 0;
    }
}

int getCardLength(long number)
{
    long card_number = number;
    int digit_counter = 0;

    // get the length of the card number - fractional part will be ignored
    while (card_number != 0)
    {
        card_number = card_number / 10;
        digit_counter++;
    }

    return digit_counter;
}

string validateCardTypes(long card_number)
{
    string card_type = "";
    long card_digits = 0;
    card_digits = card_number;

    //get length of card
    int card_number_length = getCardLength(card_number);

    /*
        get the first 2 digits of card number.
        loop 2 times less than the length of card
        while dividing by 10.
    */
    for (int i = 0; i < card_number_length - 2; i++)
    {
        card_digits /= 10; // card_digits = card_digits / 10;
    }

    // determine card type based on frist 2 digits and length of card number
    if ((card_digits == 34 || card_digits == 37) && card_number_length == 15)
    {
        card_type = "AMEX";
    }
    else if ((card_digits == 51 || card_digits == 52 || card_digits == 53 || card_digits == 54 || card_digits == 55) &&
             card_number_length == 16)
    {
        card_type = "MASTERCARD";
    }
    else if ((card_digits / 10) == 4 && (card_number_length == 13 || card_number_length == 16)) // check first digit
    {
        card_type = "VISA";
    }
    else
    {
        card_type = "INVALID";
    }

    return card_type;
}

string performCheckSum(string card_type, long card_number)
{
    const string invalid = "INVALID";

    if (card_type != invalid)
    {
        if (calculateCheckSum(card_number))
        {
            return card_type;
        }
        else
        {
            /*
                change from potential VISA, AMEX or MASTERCARD
                to invalid since card failed the checksum.
            */
            card_type = invalid;
        }
    }

    return card_type;
}

bool calculateCheckSum(long card_number)
{
    long card = card_number;
    long product;
    int last_digit;
    int digit_sum_multiple = 0;
    int digit_sum = 0;
    int check_sum_total = 0;

    // get the length of the card
    int card_length = getCardLength(card);

    for (int j = 1; j <= card_length; j++)
    {
        // get the current last digit of card number
        last_digit = card % 10;

        // remove last digit from card for next iteration of loop.
        card /= 10;

        /*
            check if loop variable j, is divisible by 2 fully.
            That is the modulus of 2 returns 0, which means that
            digit is to be multiplied by 2.
        */
        if ((j % 2) == 0)
        {
            product = last_digit * 2;

            // loop to get individual digits from product of 2
            while (product != 0)
            {
                // get last digit of product
                digit_sum_multiple += (product % 10);

                // update product to next digit if available, otherwise 0.
                product = product / 10;
            }
        }
        else
        {
            digit_sum += last_digit;
        }
    }

    check_sum_total = digit_sum_multiple + digit_sum;

    /*
        check if checksum total last digit is 0, thus credit card is valid.
    */
    if ((check_sum_total % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


