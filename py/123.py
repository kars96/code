from __future__ import division, print_function
from builtins import input
f=[1]
def fac(n):
    if (n+1)<len(f):
        return f[n]
    else:
        for i in range(len(f),n+1):
            f.append(f[i-1]*i)
        return f[n]

def p(n,r):
    # print(fac(n),fac(n-r))
    return fac(n)/fac(n-r)

m=10**9+7

t=int(input())
for i in range(t):
    a=input()
    # a=['j']*(10**6)
    b=input()
    A=[0]*26
    B=[0]*26
    for j in a:
            A[ord(j)-97]+=1
    for j in b:
            B[ord(j)-97]+=1
    # print(A,B)
    x=1
    for j in range(len(B)):
        if B[j]!=0:
            # print(A[j],B[j])
            # print(p(A[j],B[j]))
            # print(f)
            x*=p(A[j],B[j])%m
    print(int(x))
