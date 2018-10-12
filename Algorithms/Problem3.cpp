/*
 * Problem3.cpp
 *
 * Solves problem #3 on projecteuler.net
 *
 * "The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143?"
 *
 * Written By Alan Bishop 
 * Last Updated 4/6/2014
 */

#include <stdio.h>

#define BIG_NUMBER 600851475143


long long int Problem3(void);

//Small main to allow problems to all be combined into one program
int main(int argc, char * argv[])
{
    Problem3();
    return 0;
}

long long int Problem3(void)
{
    //Factor!
    long long int cur = BIG_NUMBER;
    long long int i = 2;
    long long int lf = i; //Last factor
    while(cur > i)
    {
        for(i = lf; i < cur; ++i)
        {
            if(cur%i == 0)
            {
                cur = cur/i;
                lf = i;
                break;
            }
        }
    }
    printf("The largest prime factor of %lld is %lld\n", BIG_NUMBER,cur);
}
