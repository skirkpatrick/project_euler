#include <stdio.h>
#include <stdarg.h>

/* Forward Declarations */
int sum_multiples(int limit, int a, int b);


/* Function Definitions */

int main()
{
    printf("%d\n", sum_multiples(1000, 3, 5));
}


// Sums the multiples, less than limit,
// of the two integers passed into it.
int sum_multiples(int limit, int a, int b)
{
    int i;
    int sum = 0;

    for (i = 1; i < limit; ++i)
        if (!(i % a) || !(i % b))
            sum += i;

    return sum;
}
