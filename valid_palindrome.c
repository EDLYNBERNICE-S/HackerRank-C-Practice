/*
 Problem: Largest Palindrome Product

 Description:
 For each test case, given an integer N, find the largest palindrome
 made from the product of two 3-digit numbers that is less than N.

 A palindrome number reads the same forward and backward.

 Approach:
 - Generate products of all pairs of 3-digit numbers (100 to 999).
 - Check if the product is less than N.
 - Reverse the number to verify if it is a palindrome.
 - Track the maximum palindrome found.

 Time Complexity: O(1)
   - The range of 3-digit numbers is fixed (900 × 900 iterations).

 Space Complexity: O(1)
   - Only a few variables are used.
*/

#include <stdio.h>
#include <stdbool.h>

int isPalindrome(int num) {

    int original = num;
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {

        int n;
        scanf("%d", &n);

        int maxPalindrome = 0;

        for (int i = 100; i < 1000; i++) {
            for (int j = 100; j < 1000; j++) {

                int product = i * j;

                if (product < n && isPalindrome(product)) {
                    if (product > maxPalindrome) {
                        maxPalindrome = product;
                    }
                }
            }
        }

        printf("%d\n", maxPalindrome);
    }

    return 0;
}
