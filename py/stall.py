from itertools import compress
n,k=list(map(int,input().split(',')))
a=[]
for i in range(n):
	a.append(int(input()))
cost=0

def mt(pos,s,code):
	
	global cost
	if(pos>=n):
		# w=[i=='1' for i in code ]
		#print(code,w)
		temp=[]
		for i in range(n):
			if code[i] == '1':
				temp.append(a[i])
		if cost <sum(temp):
			cost=sum(temp)
		# cost.append(sum(temp))
		# cost=list(set(cost))
		# cost=t2
	else:
		if(s == 0):
			#print(pos,code)

			mt(pos+1,0,code+'0')
			#print(pos,code)

			mt(pos+1,1,code+'1')
		if(s ==1):
			# if((pos+k)>n):
			# 	f=n-pos
			# else:
			# 	f=k
			f=k
			code=code+'0'*f
			mt(pos+f+1,0,code+'0')
			mt(pos+f+1,1,code+'1')
mt(0,0,'0')
mt(0,1,'1')
#print(cost)
print((cost))