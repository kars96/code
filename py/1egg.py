d=list(map(int,input().strip().split(' ')))
if(len(d)==2):
	m,x=d
else:
	m=d[0]
	x=int(input())
# print(x)
c=list()
for i in range(m):
	c.append(int(input()))
# print(c)
t=sum(c)
# print(t)
if x>(t-1):
	print("Sorry, we can only supply %d eggs"%(t-1))
	min=9999999999999
	mini=0
	for i in range(len(c)):
		if c[i]<min:
			min=c[i]
			mini=i

	for i in range(len(c)):
		if i!=mini:
			print(c[i],c[i],0)
		else:
			print(c[i],c[i]-1,1)

else:
	print("Thank you, your order for %d eggs are accepted"%x)
	# d={}
	# for i in c:
	# 	d[i]=0
	# # print(d, d.keys())
	# f=[i for i in d.keys()]
	# f.sort(reverse=True)
	# # print(f)
	# # ne=1
	# for i in f:
	# 	if(i<=x):
	# 		d[i]=i
	# 		x-=i
	# 		print(x)
	# 	else:
	# 		d[i]=i-x
	# 		break
	# for i in c:
	# 	print(i,d[i],i-d[i])
	v=[0 for i in range(len(c))]
	a=[0 for i in range(len(c))]
	for i in range(len(c)):
		max=-1
		maxi=-1
		if(x==0):
			break
		for j in range(len(c)):
			if( c[j]>max and v[j]==0):
				max=c[j]
				maxi=j
		v[maxi]=1
		if max>x:
			a[maxi]=x
			x=0
		else:
			x-=max
			a[maxi]=max
	for i in range(len(c)):
		print(c[i],a[i],c[i]-a[i])

