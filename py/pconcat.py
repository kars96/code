from math import sqrt,floor
def SieveOfEratosthenes(prime,n):
     
    # Create a boolean array "prime[0..n]" and initialize
    #  all entries it as true. A value in prime[i] will
    # finally be false if i is Not a prime, else true.
    p=2
    x=[]
    while(p * p <= n):
         
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
            x.append(p) 
            # Update all multiples of p
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p+=1
    lis =[]
    # print(prime)
    return prime
    # Print all prime numbers
    
def isPrime(x):
    for i in range(2,floor(sqrt(x))+1):
        if(x%i == 0):
            return False
    return True
# driver program
if __name__=='__main__':
    n = int(input())
    # n=53
    prime = [True for i in range(n+1)]
    s=SieveOfEratosthenes(prime,n)
    # print(s)
    c=[]
    count=0
    q=list()
    for i in range(2,len(prime)):
        if prime[i]:
            c.append(i)
    # print(c)
    for i in range(len(c)):
        for j in range(len(c)):
            
            if(isPrime(int(str(c[i])+str(c[j])))):
                # print(int(str(c[i])+str(c[j])))
                count+=1
                q.append(int(str(c[i])+str(c[j])))
    print(len(set(q)))
    # print "Following are the prime numbers smaller",
    # print "than or equal to", n
    # SieveOfEratosthenes(n)