#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

struct comparator{
	bool operator()(int i, int j){
		return i<j;
	}
};

int main(){
	priority_queue<int, vector<int>, comparator> minHeap;
	minHeap.push(10);
	minHeap.push(5);
	minHeap.push(12);
	minHeap.push(3);
	minHeap.push(4);
	while(!minHeap.empty()){
		cout<<minHeap.top()<<" ";
		minHeap.pop();
	}
}