#include <bits/stdc++.h>
using namespace std;



/*

isme phele pop krte jao fir middle elemt ko 
print ya deelte krdo using recursion and backtracking


*/

void solve(stack<int>&st,int& pos ,int &ans){
	//base case
	if(pos==1){

		//ans = st.top();
		cout<<"Deleting : "<<st.top()<<endl;
		st.pop();
		return;
	}
	
	//1 case hum solve krenge
	
	pos--;
	int temp = st.top();
	st.pop();
	
	//recursion
	solve(st,pos,ans);
	
	//backtracking
	
	st.push(temp);
	
}


int getMiddleElement(stack<int> &st){
	int size=st.size();
	if(st.empty()){
		return -1;
	}
	else{
		//stack is not empty;
		//odd
		int pos=0;
		if(size & 1){ //odd check krne ka tareka bitwise wala
			pos=size/2 + 1;
		}
		else{
			//even
			pos = size/2;
		}
		
		int ans = -1;
		solve(st,pos,ans);
		return ans;
	}
}


int main(){
	
	stack<int>st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	//st.push(60);
	
	
	cout<<"Before Size : "<<st.size()<<endl;
	int mid = getMiddleElement(st );
	cout<<"Middle Element : "<<mid<<endl;
	cout<<"After Size : "<<st.size()<<endl;
	
	return 0;
}