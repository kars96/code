
def median(a):
 a.sort()
 if len(a)%2 is 0:
  f=(a[len(a)//2-1]+a[len(a)//2])/2
 else:
  f=a[len(a)//2]
 return f

n=int(input())
a=list(map(int,input().strip().split(' ')))
a.sort()
# print(a)
q1,q2,q3=0,0,0
if len(a)%2 is 0:
 q1=median(a[:(len(a))//2])
 q2=median (a)
 q3=median(a[(len(a)//2):])
else:
 q1=median(a[:(len(a))//2])
 q2=median (a)
 q3=median(a[(len(a)//2)+1:])
 # print(a[(len(a)//2)+1:])
print (q1,q2,q3,sep='\n')