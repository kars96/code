#!/bin/python3
n,k=list(map(int,input().strip().split(' ')))
a=list(map(int,input().strip().split(' ')))
a.sort(reverse=True)
i=0
cost=0
e=0
while i<n:
	for j in range(k):
		if i<n:
			cost+=(e+1)*a[i] 
		i+=1
	e+=1
print(cost)