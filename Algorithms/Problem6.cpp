/*
 * Problem6.cpp
 *
 * Solves problem #6 on projecteuler.net
 *
 *"The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *( 1 + 2 + ... + 10)2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the 
 * square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers 
 * and the square of the sum."
 *
 *
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

int Problem6(void);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem6();
}

/* This is a brute force solution because it's been suficient to solve the problem in time 
 * Since all these calculations are neccessary I don't think this can be improved much O(N) time
 */
int Problem6(void)
{
    int i;
    int sqsum = 0; // Square sum
    int sumsq = 0; // Sum of squares
	// For each number 1-100, add the square sum and sum of squares to a total
    for(i = 1; i < 101; ++i)
    {
        sqsum += i;
        sumsq += i * i;
    }
    int diff = sqsum * sqsum - sumsq;
    printf("The difference between the sum of squared of the first 100 natural numbers is %d\n", diff);
    return diff;
}