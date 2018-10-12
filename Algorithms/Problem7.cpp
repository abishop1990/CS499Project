/*
 * Problem7.cpp
 *
 * Solves problem #1 on projecteuler.net
 *
 * "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *  What is the 10 001st prime number?"
 * 
 * Written By Alan Bishop 
 * Last Updated 10/11/2018
 */

#include <stdio.h>

long long Problem7(void);
bool isPrime(long long int n);

/* I fit a pattern here to make sure that every main can be consistent in these */
int main(int argc, char * argv[])
{
    Problem7();
}

/* Another problem where the isPrime could be cleaned up or use a library for these 
 * This solution works fine for finding the problem answer in a decent time though
 */
long long Problem7(void)
{
    long long i = 2;
    int n = 0;
    for(i = 2; n != 10001; ++i) {
        if(isPrime(i)) ++n;
    }
    printf("The 10,001st prime number is %lld\n",i);
    return i;
}

bool isPrime(long long int n)
{
    long long int i;
    bool prime = true;
    for(i = 2; i < n; ++i) {
        if(n%i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}