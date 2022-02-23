/*
6.11
Bubble Sort
The bubble sort presented in Fig. 6.15 is inefficient for large arrays. Make the
following simple modifications to improve its performance.
a) After the first pass, the largest number is guaranteed to be in the highest-numbered
element of the array; after the second pass, the two highest numbers are “in place,” and
so on. Instead of making nine comparisons on every pass, modify the bubble sort to make
eight comparisons on the second pass, seven on the third pass and so on.
b) The data in the array may already be in the proper or near-proper order, so why make
nine passes if fewer will suffice? Modify the sort to check at the end of each pass whether
any swaps have been made. If none has been made, then the data must already be in the proper
order, so the program should terminate. If swaps have been made, then at least one more pass is needed.
*/

// Fig. 6.15: fig06_15.c
// Sorting an array's values into ascending order.
#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // output original array
    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    // bubble sort
    // loop to control number of passes
    for (unsigned int pass = 1; pass < SIZE; ++pass)
    {
        short swap_made = 0;
        // loop to control number of comparisons per pass
        for (size_t i = 0; i < SIZE - pass; ++i)
        {
            // compare adjacent elements and swap them if first
            // element is greater than second element
            if (a[i] > a[i + 1])
            {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
                swap_made = 1;
            }
        }

        if (!swap_made)
        {
            break;
        }
    }

    puts("\nData items in ascending order");

    // output sorted array
    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");
}