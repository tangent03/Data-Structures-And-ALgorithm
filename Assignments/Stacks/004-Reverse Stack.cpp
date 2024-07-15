	#include <bits/stdc++.h>
	using namespace std;
	
	
	
	/*
	TC =O(NSqurae);
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
	
	
	
	void reverseStack(stack<int> &st){
		//base case
		if(st.empty()){
			return;
		}
		
		//1 case me solve krunga
		int temp = st.top();
		st.pop();
		
		//recursion
		
		reverseStack(st);
		
		//backtracking
		
		insertAtBottom(st,temp);
	}
	
	
	int main(){
		
		stack<int> st;
		st.push(10);
		st.push(20);
		st.push(30);
		
	
		
		
		// cout<<"Without Reverse: "<<endl;
		// while(!st.empty()){
			// cout<<st.top()<<" ";
			// st.pop();
		// }
		// cout<<endl;
		
		
		reverseStack(st);
		cout<<"After Reverse: "<<endl;
		while(!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
		
		
		return 0;
	}