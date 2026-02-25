/*
 Problem: Sum of Prime Numbers

 Description:
 For each test case, the program reads an integer N and calculates
 the sum of all prime numbers from 2 up to N.

 Approach:
 - Iterate through numbers from 2 to N.
 - Handle small primes (2 and 3) directly.
 - Skip numbers divisible by 2 or 3.
 - Check divisibility only up to sqrt(i) using the 6k ± 1 optimization.
 - If a number is prime, add it to the total sum.

 Time Complexity: O(n √n)
   - Each number up to N is checked for primality.
   - Divisibility is checked only up to √n.

 Space Complexity: O(1)
   - Only a few variables are used.
*/

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int test = 0; test < t; test++) {

        int n;
        long long sum = 0;
        scanf("%d", &n);

        for (int i = 2; i <= n; i++) {

            if (i == 2 || i == 3) {
                sum += i;
                continue;
            }

            if (i % 2 == 0 || i % 3 == 0)
                continue;

            int isPrime = 1;

            for (int j = 5; j * j <= i; j += 6) {
                if (i % j == 0 || i % (j + 2) == 0) {
                    isPrime = 0;
                    break;
                }
            }

            if (isPrime)
                sum += i;
        }

        printf("%lld\n", sum);
    }

    return 0;
}
