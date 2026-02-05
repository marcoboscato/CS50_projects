#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_points(string word, const char letters[], const int points[]);

int main(void)
{
    // points system: each number correspond to a letter (a,b,c,d,e,f,...,z)
    const char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    const int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // get the words of the two players:
    string words[2];

    for (int i = 0; i < 2; i++)
    {
        int p = i + 1;
        words[i] = get_string("Player %i: ", p);
    }

    // printf("%s\n", words[0]);  To print a string
    int score1 = count_points(words[0], letters, points);
    int score2 = count_points(words[1], letters, points);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

// helper function
int count_points(string word, const char letters[], const int points[])
{
    // initialize the scores for the player
    int score = 0;

    // count the points
    int len = strlen(word);

    for (int j = 0; j < len; j++)
    {
        for (int n = 0; n < 26; n++)
        {
            // convert to lowercase
            char letter = tolower(word[j]);

            if (letter == letters[n])
            {
                score += points[n];
            }
            else
            {
                continue;
            }
        }
    }
    return score;
}