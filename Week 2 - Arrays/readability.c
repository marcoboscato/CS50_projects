#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calculate_L(int letters, int words);
float calculate_S(int senteces, int words);
void grade(float index);

int main(void)
{
    string text = get_string("Text: ");
    int len_text = strlen(text);

    // counting words, senteces and letters
    int words = 1;
    int senteces = 0;
    int letters = 0;

    for (int i = 0; i < len_text; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters ++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            senteces++;
        }
        else if (isblank(text[i]) != 0)
        {
            words++;
        }
        else
        {
            continue;
        }
    }
    // printf("words: %i, senteces: %i, letters: %i\n", words, senteces, letters);
    float L = calculate_L(letters, words);
    float S = calculate_S(senteces, words);

    // calculate the index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print result
    // printf("index %f\n", index);
    grade(index);

}

//helper functions
float calculate_L(int letters, int words)
{
    return (letters / (float) words) * 100.0;
}

float calculate_S(int senteces, int words)
{
    return (senteces / (float) words) * 100.0;
}

void grade(float index)
{
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}