#include <stdio.h>
#include <cs50.h>

/*
Small script that prints a double half-pyramid of a specified height, based on the classic Super Mario Bros. game.
The user is prompted to input the height of the pyramid, which must be between 1 and 8 inclusive.
*/


int choose_high(void);
void print_block(int n);
void print_space(int n);
void make_pyramid(int high);


// main
int main(void)
{
    int high = choose_high();

    make_pyramid(high);
}



// functions

int choose_high(void)
{
    int high;

    while(true)
    {
        high = get_int("How tall is the pyramid? [1-8] ");

        if (high>=1 & high<=8)
        {
            break;
        }
        else
        {
            printf("Must be between 1 and 8!\n");
            continue;
        }
    }

    return high;
}



void print_block(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("#");
    }
}

void print_space(int n)
{
    for(int i=0; i<n; i++)
    {
        printf(" ");
    }
}


void make_pyramid(int high)
{
    //initial space block
    int s = high-1;
    //initial # block
    int b = 1;

    for(int i=high; i>0; i--)
    {
        print_space(s);
        print_block(b);
        print_space(2);
        print_block(b);
        printf("\n");
        s--;
        b++;
    }
}
