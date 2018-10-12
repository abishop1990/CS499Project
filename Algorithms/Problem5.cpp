/*
 * Problem5.cpp
 *
 * Solves problem #5 on projecteuler.net
 *
 * "2520 is the smallest number that can be divided by each of the numbers 
 *  from 1 to 10 without any remainder. What is the smallest positive number
 *  that is evenly divisible by all of the numbers from 1 to 20?"
 *
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

long int Problem5(void);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem5();
    return 0;
}

/* This appears to be another brute force solution 
 * Search each number to check it's divisibility until we find one
 */
long int Problem5(void)
{
    long  n = 21;
    bool done = false;
    while(!done) {
        done = true;
		// Go from largest to smallest because it's more likely the larger the number
		// that it won't be divisible by that number first instead of up.
        for(long i = 20; i > 1; --i) {
            if(n%i != 0) {
                done = false;
                break;
            }
        }
        if(!done) ++n;
    }

    printf("The smallest number divisible by 1-20 is %ld\n", n);
    return n;
}
