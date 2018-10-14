n=int(input())
a=list(map(int,input().split(',')))
a.sort(reverse=True)
a=a[:6]
a.sort()
# print(a)
# g=list()

# g.append([a[1],a[3],a[4],a[5],a[2],a[0]])
q=[[a[1],a[3],a[4],a[5],a[2],a[0]]]

# print(g)
z=None
h=6*5*4*3*2
h/=2
from itertools import permutations
for p in permutations(q[0]):
	# print(p)
	if(h==0):
		break
	v=6
	g=list()
	g.append(p)
	# print(g)
	for i in range(4):
		temp=[]
		for j in range(v-1):
			temp.append(g[i][j]+g[i][j+1])
		g.append(temp)
		v-=1
		# print(g)
	s=g[4][0]*g[4][1]
	if z is None:
		z=s
	elif s>z:
		z=s
		break
	h-=1
print(z)
		