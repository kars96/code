#include<stdio.h>

int fnumber(long input1,int input2_size, int* input2)
    {
        //Write code here
        long sum = 0;
        long k = input1;
        int n = input2_size;
        int flag = 0;
        int i, n2 = n;
        
        for ( i = 1; i <= n; i++ )
        {
           sum += n2--;
           if( sum > k)
           {
               return i;
           }
        }
        return -1;
    }

    int main()
    {
    	long k; int n;
    	printf("K?");
    	scanf("%ld", &k);
    	printf("N?");
    	scanf("%d", &n);
    	printf("%d\n", fnumber(k, n, '\0') );

    }