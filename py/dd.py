n=int(input())
a=[]
for i in range(n):
	s=list(map(int,input().split(" ")))
	a.append(s)
s=0
s1=0
for i in range(n):
	s+=a[i][i]
	s1+=a[i][(n-1)-i]

from math import fabs
print(int(fabs(s1-s)))