t=int(input())

for i in range(t):
	n=0
	s=[]
	n=(int(input()))
	for j in range(n):
		s.append(list(input()))
		s[j].sort()
	for k in range(1,n):
		if s[k-1]<=s[k]:
			continue
		else:
			print("NO")
			break
	else:
		print("YES")