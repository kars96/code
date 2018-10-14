#include <stdio.h>
#include <math.h>

int main()
	{	

		long long t;
		scanf("%lld",&t);

		for(int z=0; z<t; z++){
			long n;
			scanf("%ld",&n);
			long long a[n][n];
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					scanf("%lld", &a[i][j]);

			long long s=0, s2=0;
			for(int i=0; i<n; i++){
				s+=a[i][i];
				s2+=a[i][(n-1)-i];
			}
			printf("%lld\n", (s-s2)>=0?(s-s2):(s2-s));
		}

	}