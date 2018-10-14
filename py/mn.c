#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>
long long solve (long long* a ,int n) {
    long long s=0,d;
    long long M=pow(10,10)+11;
    for(int i=0;i<n;i++)
    {
        d=a[i];
        while(d!=0)
        {
            if(d%2 == 1) s=(s+1)%(M);
            d/=2;
        }
    }
    return s;
   // Write your code here
}

int main() {
    int n;
    scanf("%d", &n);
    int i_a;
    long long *a = (long long  *)malloc(sizeof(int));
    for(i_a=0; i_a<n; i_a++)
    	scanf("%lld", &a[i_a]);

    long long out_ = solve(a,n);
    printf("%lld", out_);
}