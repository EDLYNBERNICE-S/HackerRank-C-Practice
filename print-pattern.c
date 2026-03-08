/*
Problem: Printing the Pattern (HackerRank)

Description:
Given an integer n, print a square pattern of size (2n-1) × (2n-1).
The pattern forms concentric layers where the outermost layer
contains the number n, the next layer contains n-1, and so on
until the center which contains 1.

Example:

Input:
2

Output:
2 2 2
2 1 2
2 2 2

Input:
4

Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4


Approach:

1. The total pattern size is (2*n - 1).
2. Traverse each cell using two nested loops.
3. For each position (i, j), compute the minimum distance
   from all four edges.
4. Subtract that minimum value from n to determine
   which number to print.
5. Print the value for each cell.

Key Idea:
Each layer moves inward and decreases the value by 1.


Time Complexity:
O(n²)

Because we iterate through a grid of size (2n-1) × (2n-1).


Space Complexity:
O(1)

Only a few integer variables are used.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i, j;
    int size = 2 * n - 1;

    for (i = 0; i < size; i++) {

        for (j = 0; j < size; j++) {

            int min = i;

            if (j < min)
                min = j;

            if (size - i - 1 < min)
                min = size - i - 1;

            if (size - j - 1 < min)
                min = size - j - 1;

            printf("%d ", n - min);
        }

        printf("\n");
    }

    return 0;
}
