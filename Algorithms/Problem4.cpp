/*
 * Problem1.cpp
 *
 * Solves problem #4 on projecteuler.net
 * 
 *
 * "A palindromic number reads the same both ways. 
 *  The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *  Find the largest palindrome made from the product of two 3-digit numbers."
 *
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

int Problem4(void);
bool isPalindrome(int n);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem4();
    return 0;
}

/* Iterates over all numbers 100-1000 and checks if they're palindromes
   I've improved this to start high instead of low
 */
int Problem4(void)
{
    int highest = 0;
    int cur = 0;
    for(int i = 1000; i >= 100; --i) {
        for(int j = 1000; j >= 100; --j) {
            cur = i*j;
			// The order here matters, if cur is less than highest
			// then the palindrome logic will never execute, saving time
            if(cur > highest && isPalindrome(cur)) {
                highest = cur;   
            }
        }
    }
    
    printf("The highest 3-digit palindrome is %d\n",highest);
    return highest;
}

/* This is an interesting algorithm
   Relies on the fact that n/10 truncates
   I took this part from StackOverflow, found it very interesting
 */
bool isPalindrome(int n)
{
    int r = 0;
    int num = n;
    int d;
    while(num > 0) {
        d = num % 10;
        r = r * 10 + d;
        num = num / 10;
    }
    return n == r;
}
