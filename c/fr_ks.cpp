#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct item{
	int w;
	int v;
	char n;
};

struct comparator{
	bool operator()(item x, item y){
		// cout<<x.n<<" < "<<y.n<<"  "<<((x.v/x.w)*10<(y.v/y.w)*10)<<endl;
		// printf(" %c %d %d  ")
		return ((float)x.v/x.w)<((float)y.v/y.w);
		
	}
};

int main(){
	priority_queue<item, vector<item>, comparator> p;
	int w;
	cin>>w;
	item s;
	for(int i=0; i<6; i++){
		// printf("Item %d\nweight:",i);
		cin>>s.w;
		// printf("Value:");
		cin>>s.v;
		s.n=65+i;
		p.push(s);

	}
	int c=0;
	while(!p.empty() && w>0){
		s = p.top();
		p.pop();
		if ( s.w <= w)
		{
			printf("%c %d %d\n", s.n, s.w, s.v );
			w-=s.w;
		}
		else if(w>0){
			printf("%c %d %f\n", s.n, w, (float)s.v/s.w*w );
			w=0;
		}
	}
}