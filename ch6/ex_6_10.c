/*
6.10
Sales Commissions
Use a one-dimensional array to solve the following problem. A company pays its
salespeople on a commission basis. The salespeople receive $200 per week plus 9%
of their gross sales for that week. For example, a salesperson who grosses $3,000
in sales in a week receives $200 plus 9% of $3,000, or a total of $470. Write a
C program (using an array of counters) that determines how many of the salespeople
earned salaries in each of the following ranges (assume that each salesperson’s
salary is truncated to an integer amount):
a) $200–299
b) $300–399
c) $400–499
d) $500–599
e) $600–699
f) $700–799
g) $800–899
h) $900–999
i) $1000 and over
*/

#include <stdio.h>

#define EMPLOYEES 10
#define GROUPS 9
#define COMMISION 9 // in percent

void countSalaries(int sales[], int number_of_employees, int counter[]);
void printCounter(int counter[]);

int main(void)
{
    // sales per each employee
    int sales[EMPLOYEES] = { 1000, 2250, 2300, 3400, 2500, 3600, 4700, 5800, 2900, 15000 };
    // counter for count employees' salaries by group
    int counter[GROUPS] = { 0 };

    countSalaries(sales, EMPLOYEES, counter);
    printCounter(counter);

    return 0;
}

// calculates and groups salaries in counter array
// with next indices for each group:
// 0 - $200–299
// 1 - $300–399
// 2 - $400–499
// 3 - $500–599
// 4 - $600–699
// 5 - $700–799
// 6 - $800–899
// 7 - $900–999
// 8 - $1000 and over
void countSalaries(int sales[], int number_of_employees, int counter[])
{
    // loop through each employee's sale
    // calculate salary and
    // add to the counter
    for (int i = 0; i < number_of_employees; i++)
    {
        int salary = 200 + COMMISION * sales[i] / 100;
        if (salary >= 1000) counter[8]++;
        else if (salary >= 900) counter[7]++;
        else if (salary >= 800) counter[6]++;
        else if (salary >= 700) counter[5]++;
        else if (salary >= 600) counter[4]++;
        else if (salary >= 500) counter[3]++;
        else if (salary >= 400) counter[2]++;
        else if (salary >= 300) counter[1]++;
        else if (salary >= 200) counter[0]++;
    }
}

// prints counter for each group
void printCounter(int count[])
{
    printf("Salary groups\n");
    printf("=============\n");
    for (int i = 0; i < GROUPS; i++)
    {
        // not last group
        if (i < GROUPS - 1)
        {
            // calculate lower value from group
            int low = (i + 2) * 100;
            // print group and counter value
            printf("$%d-%d: %d\n", low, low + 99, count[i]);
        }
        // for last group
        else
        {
            printf("  $1000+: %d\n", count[i]);
        }
    }
}
