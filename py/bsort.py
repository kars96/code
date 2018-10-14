n=eval(input())

a=str(input())
a=a.split(' ')
a=list(map(lambda x:int(x),a))
for i in range(n-1):
	for j in range(n-i-1):
		if a[j]<a[j+1]:
			a[j],a[j+1]=a[j+1],a[j]
map(lambda x:print(x,end='\t'),a)


