def solve (a):
    mv=0
    for i in range(1,len(a)):
        if (a[i]<a[1-1]):
            mv+=a[i-1]-a[i]+1
            a[i]+=(a[i-1]-a[i])+1
    return mv        
    
    # Write your code here

n = int(input())
a = map(int, input().split())

out_ = solve(a)
print (out_)