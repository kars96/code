n,k=map(int,input().split(' '))
luck=0
a=[]
for i in range(n):
	t1,t2=map(int,input().split(' '))
	if t2 is 0:
		luck+=t1
	else:
		a.append(t1)
a.sort()
# print(a,a[:n-k],a[n-k:])
ni=a[-1:-k-1:-1]
i=list(filter(lambda x: x not in ni,a))
luck+=-sum(i)+sum(ni)
print(luck)