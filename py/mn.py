from itertools import accumulate
def solve (a):
    sum=0
    for i in a:
        b="{0:b}".format(i)
        # print(b)
        s=list(map(int,str(b)))
        # print(s)
        c=list(map(int,s))
        # print(c)
        sum+=(list(accumulate(c,lambda x, y: x+y))[-1])
        
    return sum
    # Write your code here

n = int(input())
a = map(int, input().split())

out_ = solve(a)
print (out_)