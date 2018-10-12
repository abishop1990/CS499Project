/*
 * Problem1.cpp
 *
 * Solves problem #1 on projecteuler.net
 * 
 * "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 *  The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000."
 *
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

int Problem1(void);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem1();
}

/* Gets the sum of all numbers where multiple of 3 or 5 */
int Problem1(void)
{
    int sum = 0;
    for(int i = 1; i < 1000; ++i)
    {
        if(i%3 == 0 || i%5 == 0) 
			sum += i;
    }
    printf("The sum of all multiples of 3 or 5 below 1000 is %d\n", sum);
    return sum;
}
