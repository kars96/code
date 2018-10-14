n=int(input())
inf=list()
g=list()
for i in range(n):
	f=input().strip().split(' ')
	print(f)
	g.append(list(map(int,f)))
	inf.append([0]*n)
ii,ij=list(map(int,input().strip().split(' ')))
ii-=1
ij-=1
ai,aj=list(map(int,input().strip().split(' ')))
ai-=1
aj-=1
# inf[ii][ij]=1
# g[ii][ij]=5

def safe(i,j):
	global n
	if(i>-1 and j>-1 and i<n and j<n):
		return True
	return False
flag=1
# def infect(i,j,l):
# 	global g
# 	global inf
# 	global flag
# 	if flag==1:
# 		if (safe(i,j) and l!=1 and inf[i][j]!=1 and g[i][j]!=0):
# 			g[i][j]=l
# 			inf[i][j]=1
# 			infect(i+1,j-1,l)
# 			infect(i-1,j,l)
# 			infect(i,j+1,l)
# 			infect(i,j-1,l)
# 			infect(i+1,j+1,l)
# 			infect(i+1,j-1,l)
# 			infect(i-1,j+1,l)
# 			infect(i-1,j-1,l)
# 			flag=0
# 	else:
# 		if (safe(i,j) and l!=1 and inf[i][j]!=1 and g[i][j]!=0):
# 			g[i][j]=l
# 			inf[i][j]=1
# 			infect(i+1,j,l-1)
# 			infect(i-1,j,l-1)
# 			infect(i,j+1,l-1)
# 			infect(i,j-1,l-1)
# 			infect(i+1,j+1,l-1)
# 			infect(i+1,j-1,l-1)
# 			infect(i-1,j+1,l-1)
# 			infect(i-1,j-1,l-1)
# flag=1
# def infect(i,j,l,flag):
# 	global g
# 	global inf
# 	t=[-1,0,1]
# 	print('hello')
# 	# global flag
# 	if flag is 1:
# 		g[i][j]=l
# 		inf[i][j]=1
# 		# t=[-1,0,1]
# 		for x in t:
# 			for y in t:
# 				if x!=0 and y!=0:
# 					print(x,y)
# 					if( safe(i+x,j+y) and l!=1 and inf[i+x][j+y]!=1 and g[i+x][j+y]!=0):
# 						print(i+x,j+y)
# 						g[i+x][j+y]=l
# 						inf[i+x][j+y]=1
# 		for x in t:
# 			for y in t:
# 				if( safe(i+x,j+y) and g[i+x][j+y]!=0):
# 					if x!=0 and y!=0:
# 						infect(i+x,j+y,l-1,0)
	
# 	else:
# 		for x in t:
# 			for y in t:
# 				if x!=0 and y!=0:
# 					print(x,y)
# 					if( safe(i+x,j+y) and l!=1 and inf[i+x][j+y]!=1 and g[i+x][j+y]!=0):
# 						print(i+x,j+y,'hello')
# 						g[i+x][j+y]=l
# 						inf[i+x][j+y]=1
# 		for x in t:
# 			for y in t:
# 				if( safe(i+x,j+y) and (l-1)!=1 and inf[i+x][j+y]!=1 and g[i+x][j+y]!=0):
# 					if x!=0 and y!=0:
# 						infect(i+x,j+y,l-1,0)

# infect(ii,ij,5,1)

t=[-1,0,1]
def infect(i,j,l):
	for x in t:
		for y in t:
			if x!=0 and y!=0:
				if(safe(i+x,j+y) and inf[i+x][j+y]==0 and g[i+x][j+y]!=0):
					print(i+x,j+y)
					g[i+x][j+y]=l
					inf[i+x][j+y]=1
	print(g)
	for x in t:
		for y in t:
			if (x!=0 and y!=0):
				if(safe(i+x,j+y) and g[i+x][j+y]!=0 and l-1!=1):
					infect(i+x,j+y,l-1)


for i in t:
	for j in t:
		if(safe(ii+i,ij+j) and g[ii+i][ij+j]!=0):
			g[ii+i][ij+j]=5
			inf[ii+i][ij+j]=1

for i in t:
	for j in t:
		if(safe(ii+i,ij+j) and g[ii+i][ij+j]!=0):
			infect(ii+i,ij+j,4)


print(g)
print(inf)

