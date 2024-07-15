#include <bits/stdc++.h>
using namespace std;



/*
TC =O(NSqurae);
*/

void insertSorted(stack<int> &st, int element){
	//base case
	if(st.empty() || element > st.top()){
		st.push(element);
		return;
	}
	
	//1 case hum sambhalenge
	int temp = st.top();
	st.pop();
	
	//recursion
	insertSorted(st,element);
	//backtrack
	
	st.push(temp);
}

int main(){
	
	stack<int> st;
	st.push(10);
	st.push(7);
	st.push(12);
	st.push(5);
	st.push(11);
	
	insertSorted(st,15);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	
	
	
	return 0;
}