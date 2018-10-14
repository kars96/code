#include<iostream>
#include<list>
using namespace std;
class l: public list <int>
{
public:
	void push(int x)
	{
		push_back(x);
	}
	void empty()
	{
		if(list::empty()) cout<<"List is empty\n";
		else cout<<"List is not empty\n";
	}
	void print()
	{
		for(list<int>::iterator i=begin(); i != end(); i++)
			cout<<*i<<endl;
	}
	void clear()
	{
		list::clear();
	}
	int pop()
	{
		int s=back();
		pop_back();
		return s;
	}
};

int main()
{
	l a;
	a.push(67);
	a.push(90);
	a.push(90);
	a.push(56);
	a.print();
	a.unique();
	a.print();
	a.empty();
	// cout<<a.pop()<<endl;
	a.clear();
	a.empty();
}