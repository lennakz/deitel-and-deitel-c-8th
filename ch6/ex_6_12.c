/*
6.12
Write loops that perform each of the following one-dimensional array operations:
a) Initialize the 10 elements of integer array counts to zeros.
b) Add 1 to each of the 15 elements of integer array bonus.
c) Read the 12 values of floating-point array monthlyTemperatures from the keyboard.
d) Print the five values of integer array bestScores in column format.
*/

#include <stdio.h>

#define COUNTS_SIZE 10
#define BONUS_SIZE 15
#define MONTHLY_TEMP_SIZE 12
#define BEST_SCORES_SIZE 5

int main(void)
{
    // a) Initialize the 10 elements of integer array counts to zeros.
    int counts[COUNTS_SIZE];
    for (size_t i = 0; i < COUNTS_SIZE; i++)
    {
        counts[i] = 0;
    }

    // b) Add 1 to each of the 15 elements of integer array bonus.
    int bonus[BONUS_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    for (size_t i = 0; i < BONUS_SIZE; i++)
    {
        bonus[i]++;
    }

    // c) Read the 12 values of floating-point array monthlyTemperatures from the keyboard.
    float monthlyTemperatures[MONTHLY_TEMP_SIZE];
    for (size_t i = 0; i < MONTHLY_TEMP_SIZE; i++)
    {
        printf("\nEnter temperature for month #%lu: ", i + 1);
        scanf("%f", monthlyTemperatures + i);
    }

    // d) Print the five values of integer array bestScores in column format.
    int bestScores[BEST_SCORES_SIZE] = { 10, 20, 30, 40, 50 };
    for (size_t i = 0; i < BEST_SCORES_SIZE; i++)
    {
        printf("\n%5d\n", bestScores[i]);
    }

    return 0;
}
