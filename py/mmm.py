n=int(input())
a=list(map(float,input().strip().split(' ')))
a.sort()
mean=sum(a)/n
# print(a[n//2],a[n//2+1],a)
if n%2 is 0:
	median=(a[n//2]+a[n//2-1])/2
else:
	median=a[ceil(n/2)]
s={}
o=0
mode=0.0
for i in a:
	if i  not in s:
		s[(i)]=0
	s[(i)]+=1
	if s[(i)]>o:
		mode=i
		o=s[(i)]
print(round(mean,1),round(median,1),round(mode,1),sep='\n')