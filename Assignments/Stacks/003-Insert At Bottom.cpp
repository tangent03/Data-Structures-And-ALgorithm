#include <bits/stdc++.h>
using namespace std;



/*

*/

void insertAtBottom(stack<int> &st,int element){
	//base case
	  if(st.empty()){
	  	st.push(element);
	  	return;
	  }
	  
	  
	  //1 case me solve krunga
	  
	  int temp = st.top();
	  st.pop();
	  
	  //baki recursion krega
	  insertAtBottom(st,element);
	  
	  //ab backtracking ka jalwa
	  
	  st.push(temp);
}


int main(){
	
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	
	int element = 400;
	insertAtBottom(st,element);
	
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	return 0;
}