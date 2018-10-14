def mean(a):
	return sum(a)/len(a)

n=int(input())
a=list(map(int,input().strip().split()))
m=mean(a)
t=list(map(lambda x: (m-x)**2, a))
# print(t)
from math import sqrt
print('%.1f'%(sqrt(sum(t)/len(t))))