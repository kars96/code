
def median(a):
 a.sort()
 if len(a)%2 is 0:
  f=(a[len(a)//2-1]+a[len(a)//2])/2
 else:
  f=a[len(a)//2]
 return f

def quartile(a):
	q1,q2,q3=0.0,0.0,0.0
	if len(a)%2 is 0:
	 q1=median(a[:(len(a))//2])
	 q2=median (a)
	 q3=median(a[(len(a)//2):])
	else:
	 q1=median(a[:(len(a))//2])
	 q2=median (a)
	 q3=median(a[(len(a)//2)+1:])
	return float(q1),float(q2),float(q3)

n=int(input())
a=list(map(int,input().strip().split(' ')))
f=list(map(int,input().strip().split(' ')))
x=[]
for i in range(len(a)):
	x+=[a[i]]*f[i]
x.sort()
# print(x)
q1,q2,q3=(quartile(x))
# q1,q2,q3=quartile(x)
 # print(a[(len(a)//2)+1:])
print (round(q3-q1,1))