

p=[]
m,n=list(map(int,input().split(',')))
r=[]

def ghsaf(i,j):
	#print("in")
	#print(i,j,m,n)
	if(i<m and i>-1 and j<n and j>-1):
		return True
	return False

def k(r,i,j):
	max=-1
	global m,n
	#print(i,j)
	if( ghsaf(i+1,j) is True ):
		if(r[i+1][j]>max and r[i+1][j]<r[i][j]):
			maxi=i+1
			maxj=j
			max=r[i+1][j]
	if( ghsaf(i-1,j) and r[i-1][j]>max and r[i-1][j]<r[i][j]):
		maxi=i-1
		maxj=j
		max=r[i-1][j]
	elif(( ghsaf(i-1,j) and r[i-1][j]==max)):
		p.append([i-1,j])
	if( ghsaf(i,j+1) and r[i][j+1]>max and r[i][j+1]<r[i][j]):
		maxi=i
		maxj=j+1
		max=r[i][j+1]
	elif(( ghsaf(i,j+1) and r[i][j+1]==max)):
		p.append([i,j+1])
	if( ghsaf(i,j-1,) and r[i][j-1]>max and r[i][j-1]<r[i][j]):
		maxi=i
		maxj=j-1
		max=r[i][j-1]
	elif(( ghsaf(i,j-1) and r[i][j-1]==max)):
		p.append([i,j-1])

	if(max==-1):
		return
	else:
		p.append([maxi,maxj])
		k(r,maxi,maxj)

for i in range(m):
	temp=list(map(int,input().split(',')))
	# for j in range(n):
	# temp.append(list(map(int,input().split(','))))
	r.append(temp)
gi,gj=list(map(int,input().split(',')))
#print(gi,gj,m,n)
#print(r)
k(r,gi-1,gj-1)
#print(p)
print(len(p)+1)