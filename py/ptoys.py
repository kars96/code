#!/bin/python3
n=int(input().strip())
a=list(map(int,input().strip().split(' ')))
a.sort()
m=0
i=0
print(a)
while i<n:
	j=i+1
	while  j<n  and a[j]-a[i]<=4:
		j+=1
	else:
		m+=1
	i=j
print (m)
