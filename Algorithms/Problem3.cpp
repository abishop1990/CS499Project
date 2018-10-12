/*
 * Problem3.cpp
 *
 * Solves problem #3 on projecteuler.net
 *
 * "The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143?"
 *
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

#define BIG_NUMBER 600851475143

long long Problem3(void);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem3();
    return 0;
}

/* Like a lot of these the idea is to factor primes out 
   A more in depth code review would make a common prime factor library
   I'll keep existing logic for preservation sake for now */
long long Problem3(void)
{
    long long int cur = BIG_NUMBER;
    long long int i = 2;
    long long int lf = i; //Last factor
    // Brute force search for the factor
	// A more proper way would be to build or use a prime array
	// and then iterate further
	while(cur > i) {
        for(i = lf; i < cur; ++i) {
            if(cur%i == 0) {
                cur = cur / i;
                lf = i;
                break;
            }
        }
    }
    printf("The largest prime factor of %lld is %lld\n", BIG_NUMBER, cur);
}
