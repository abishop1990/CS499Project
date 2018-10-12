/*
 * Problem1.cpp
 *
 * Solves problem #1 on projecteuler.net
 * 
 * "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 *  The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000."
 *
 * Written By Alan Bishop 
 * Last Updated 4/6/2014
 */


#include <stdio.h>

int Problem1(void);

//Small main to allow problems to all be combined into one program
int main(int argc, char * argv[])
{
    Problem1();
    return 0;
}

int Problem1(void)
{
    int i;
    int sum = 0;
    for(i = 1; i < 1000; ++i)
    {
        if(i%3 == 0 || i%5 == 0) sum += i;
    }
    printf("The sum of all multiples of 3 or 5 below 1000 is %d\n", sum);
    return sum;
}
