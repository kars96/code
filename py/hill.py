   

       
from itertools import permutations

def isAs(list):
    previous = list[0]
    for number in list:
        if number < previous:
            return False
        previous = number
    return True

def isDes(list):
    previous = list[0]
    for number in list:
        if number > previous:
            return False
        previous = number
    return True
n=int(input())
a=[ i for i in range(1,n) ]

c=0
for k in permutations(a):
    for i in range(1,len(a)):
        if isAs(k[:i]) and isDes(k[i:]):
            # print(k[:i],n,k[i:])
            c+=1
print( c%(10**9+7))
    