#include <stdio.h>
#include<math.h>
struct h{
	int a;
	// struct h j;
};
int main() 
{
   unsigned int i = 1;
   char *c = (char*)&i;
   int *z;
   float q = (float)pow(2, 8*9);
   if (*c)    
       printf("Little endian");
   else
       printf("Big endian");
   char f[]={21,22,23,24};
   float* d=(float*)f;
   // printf("\n%f",*d);
   printf("%f\n", q );
   return 0;
}