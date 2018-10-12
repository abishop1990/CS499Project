# Project Euler Problem #1 In Python
# Solves problem #1 on projecteuler.net
# 
# "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
# The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000."
# Written By Alan Bishop 7/22/14
# Updated 10/11/18

# Change this for a different result
MAX_PRIME = 999

# The idea here is to get the sum of mults of 3 and 5
# Since they have common points at multiples of 15, we need to subtract those duplicates
def sumOfSequence(N):
    sum3 = sumOfProgression(N,3)
    sum5 = sumOfProgression(N,5)
	sum15 = sumOfProgression(N,15)
    return sum3 + sum5 - sum15

# Here N is the max number and mult is the multiple
def sumOfProgression(N, mult):
    if N < mult:
        return 0
    n = int(N / mult)
    end = n * mult
    start = mult
    return int(n * (start + end) / 2)

# Print the result
print("The sum of the sequence is {}".format( sumOfSequence( MAX_PRIME ) ) )