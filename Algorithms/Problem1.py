#PE Problem #1 In Python
#Because why not and learning?
#Written By Alan Bishop 7/22/14

MAX = 999

def sumOfSequence(N):
    sum3 = sumOfProgression(N,3)
    sum5 = sumOfProgression(N,5)
    sum15 = sumOfProgression(N,15)
    return sum3 + sum5 - sum15

def sumOfProgression(N, mult):
    if N < mult:
        return 0
    n = int(N/mult)
    end = n*mult
    start = mult
    return int(n * (start+end)/2)

print("The sum of the sequence is {}".format(sumOfSequence(MAX)))
