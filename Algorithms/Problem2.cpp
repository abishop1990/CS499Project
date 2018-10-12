/*
 * Problem2.cpp
 *
 * Solves problem #2 on projecteuler.net
 *
 * "Each new term in the Fibonacci sequence is generated by adding the previous two terms.
 * By starting with 1 and 2, the first 10 terms will be: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
 * find the sum of the even-valued terms."
 *
 * Written By Alan Bishop 
 * Last Updated 4/6/2014
 */


#include <stdio.h>

int Problem2(void);

//Small main to allow problems to all be combined into one program
int main(int argc, char * argv[])
{
    Problem2();
    return 0;
}

int Problem2(void)
{
    //Iteration #1 "Brute Force"
    int sum = 0;
    int prev = 1;
    int cur = 2;
    int mid = 0;
    while(cur < 4000000)
    {
        if(cur%2 == 0) sum += cur;
        mid = cur;
        cur = prev + cur;
        prev = mid;
    }

    printf("The sum of all Fibonacci sequence numbers less than 4000000 is %d\n",sum);
    return sum;
}
