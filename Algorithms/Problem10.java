/* Problem10.java
 *
 * Solves problem 10 on projecteuler.net
 *
 * Find the sum of all the primes below two million.
 * 
 * Written by Alan Bishop
 * Last modified 10/11/2018
 */

import java.util.*;

public class Problem10
{
	/* This is just using the plain find each prime and count them up method
	 * Not flashy but it works */
    public static void main(String [] args) {
        long sum = 2;
        boolean p;
        for(int i = 3; i < 2000000; ++i)
        {
            p = true;
            for(int j = 2; j <= Math.sqrt(i); ++j) { 
                if(i%j==0) { 
					p = false; 
					break; 
				}
            }
            if(p) sum += i;
        }
        System.out.println("The sum of all primes less than 2 million is " + sum);
    }
}