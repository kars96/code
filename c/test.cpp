#include<iostream>
using namespace std;
int main (int argc, char const* argv[])
{
	int a=0;
	if(a && ++a)
		cout<<a;
	else
		cout<<a+1;
	return 0;
}
