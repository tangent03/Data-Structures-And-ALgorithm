#include <bits/stdc++.h>
using namespace std;

//T(C) = O(N)

void reverseQueue(queue<int>&q){
	
	if(k>n || k==0){
		return;
	}
	stack<int>s;
	//one by on queue se element log and stack me dallo
	while(!q.empty()){
		int frontElement = q.front();
		q.pop();
		s.push(frontElement);
	}
	//one by one stack se lo and queue me push karo
	
	while(!s.empty()){
		int element = s.top();
		s.pop();
		q.push(element);
	}
}

void reverse(queue<int>&q){
	//base case
	if(q.empty()){
		return;
	}
	
	int element = q.front();
	q.pop();
	
	//recursion
	
	reverse(q);
	
	//backtrackking
	
	q.push(element);
	
}
void reverseFirstK(queue<int> &q ,int k){
	stack<int> s;
	int n = q.size();
	//psuh first k elemnt into stack
	for(int i=0;i<k;i++){
		int temp=q.front();
		q.pop();
		s.push(temp);
	}
	// push all k elemrnts in queue
	
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		q.push(temp);
	}
	//pop and psuh (n-k) elements 
	//into queue again
	
	for(int i=0;i<(n-k);i++){
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	
	
}

int main(){
	
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	// cout<<"Before Reversing : "<<endl;
	// while(!q.empty()){
		// int element = q.front();
		// q.pop();
		// cout<<element<<" ";
	// }
	// cout<<endl;
	
	
	// reverseQueue(q);
	
	//reverse(q);
	reverseFirstK(q,4);
	
	cout<<"Print Queue"<<endl;
	
	while(!q.empty()){
		int element = q.front();
		q.pop();
		cout<<element<<" ";
	}
	
}