#include<stdio.h>
#include<algorithm>
using namespace std;
struct x{
	int a;
	int b;
};

bool f(x &q, x &w){
	if(q.a < w.a)return 1;
	return 0;
}
int main(){
	x t[3];
	t[0].a=3;
	t[1].a=9;
	t[2].a=2;
	t[0].b=7;
	t[1].b=3;
	t[2].b=9;
	sort(t, t+3, f);
	for(int i=0; i<3; i++)printf("%d->%d\n",t[i].a, t[i].b );
		return 0;
}