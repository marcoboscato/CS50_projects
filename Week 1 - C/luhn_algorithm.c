#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This is a small program that identifies the type of credit card based on its number.
    The algorithm is based on Luhn's algorithm.
*/

void put_digits(long num, int num_digits[]);
int calculate_productdigits(int num_digits[], int len);
int check_validation(int n);
void card_type(long user_number, int len_number);

// --- main function ---
int main(void)
{
    // get user input
    string user_input = get_string("Insert your credit card number here: ");
    // trasform into int32
    long user_number = atol(user_input);

    // get the lenght of the string input
    int len_number = strlen(user_input);
    printf("lenghth of the card numer: %i\n", len_number);

    // initialize an array to store the digits
    int num_digits[len_number];
    put_digits(user_number, num_digits);

    // check print: Print all credit card digits
    printf("Credit card digits: (last to first)\n");
    for (int i = 0; i < len_number; i++)
    {
        printf("%i ", num_digits[i]);
    }
    printf("\n");

    // sum of the product terms
    int prod_sum = calculate_productdigits(num_digits, len_number);

    // add the other digits
    int otherhalf_sum = 0;
    printf("other remain digits: (last to first)\n");
    for (int i = 0; i < len_number; i += 2)
    {
        printf("%i ", num_digits[i]); // check print
        otherhalf_sum += num_digits[i];
    }
    printf("\n");

    // total sum
    int total_sum = otherhalf_sum + prod_sum;

    printf("Total sum: %i\n", total_sum);

    // check validation
    int validation = check_validation(total_sum);

    // Give answer
    if (validation != 1 || len_number > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        card_type(user_number, len_number);
    }
}

// --- utility functions
void put_digits(long num, int num_digits[])
{
    // store the number digits inside the array (mirrored)
    int c = 0;
    while (num != 0)
    {
        num_digits[c] = num % 10;
        num /= 10;
        c++;
    }
}

int calculate_productdigits(int num_digits[], int len)
{
    int prod_digits_array[len / 2];

    int j = 0;
    for (int i = 1; i < len; i = i + 2)
    {
        prod_digits_array[j] = 2 * num_digits[i];
        j++;
    }
    // check print
    printf("Product of pair digits (second-to-last)\n");
    for (int i = 0; i < len / 2; i++)
    {
        printf("%i ", prod_digits_array[i]);
    }
    printf("\n");

    // sum the product digits
    int sum = 0;
    for (int i = 0; i < len / 2; i++)
    {
        if (prod_digits_array[i] >= 10)
        {
            int temp_a = prod_digits_array[i] % 10;
            int temp_b = prod_digits_array[i] / 10;
            sum = sum + temp_a + temp_b;
        }
        else
        {
            sum = sum + prod_digits_array[i];
        }
    }
    printf("Sum of the pair product digits: %i \n", sum);
    return sum;
}

int check_validation(int n)
{
    if (n % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void card_type(long user_number, int len_number)
{
    // Get first two digits
    long temp = user_number;
    while (temp >= 100)
    {
        temp /= 10;
    }
    int two_digits = temp;
    printf("first credt card tow digits: %i\n", two_digits);

    // American Express
    if (len_number == 15 && (two_digits == 34 || two_digits == 37))
    {
        printf("AMEX\n");
    }
    // MasterCard
    else if (len_number == 16 && two_digits >= 51 && two_digits <= 55)
    {
        printf("MASTERCARD\n");
    }
    // Visa
    else if ((two_digits / 10) == 4 && (len_number == 13 || len_number == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
