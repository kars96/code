m=[]
p=[]
a=[]
s=[]
n=tuple(map(lambda x:int(x),input().split()))
for i in range(n[0]):
	a=input()
	a=list(map(lambda x:int(x),a.split()))
	m.append(a)
input()
o=tuple(map(lambda x:int(x),input().split()))
#print(m)
for i in range(o[0]):
	a=input()
	a=list(map(lambda x:int(x),a.split()))
	p.append(a)
if n[1]==o[0]:
	for i in range(n[0]):
		for j in range(o[1]):
			sum=0
			for k in range(n[1]):
				sum+=m[i][k]*p[k][j]
			print(sum,end='\t')
		print()
			
			
