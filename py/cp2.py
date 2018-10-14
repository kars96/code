t=int(input())
min=9999999999
max=-1
l,r=list(),list()
for i in range(t):
	x,y=list(map(int,input().split(' ')))
	l.append(x)
	if x<min:
		min=x
	r.append(y)
	if y>max:
		max=y

from math import sqrt,floor
def SieveOfEratosthenes(n):
	# Create a boolean array "prime[0..n]" and initialize
	#  all entries it as true. A value in prime[i] will
	# finally be false if i is Not a prime, else true.
	# if p<2:
	p=2
	x=[]
	prime = [True for i in range(max+1)]
	while(p * p <= n):

	# If prime[p] is not changed, then it is a prime
		if (prime[p] == True):
			x.append(p) 
			# Update all multiples of p
			for i in range(p * 2, n+1, p):
				prime[i] = False
		p+=1
	lis =[]
	# #print(prime)
	prime[0]=False
	prime[1]=False
	return prime
	# #print all prime numbers

s=SieveOfEratosthenes(max)
#print(s)
# del prime
c=[i for i in s]
for i in range(1,len(s)):
	s[i]=s[i]+s[i-1]
s[0]=0
#print(s)
h=list()
for i in range(len(s)):
	h.append(c[s[i]])
del c
del s
# print(h)
for i in range(t):
	b=(sum(h[l[i]:r[i]]))
	if b is 0:
		print("NONE")
	else:
		print(b)
