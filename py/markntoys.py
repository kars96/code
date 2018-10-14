#!/bin/python
n,k=list(map(int,input().strip().split(' ')))
a=list(map(int,input().strip().split(' ')))
a.sort()
t=0
p=0
for i in a:
	if t+i<k:
		t+=i
		p+=1
print(p)