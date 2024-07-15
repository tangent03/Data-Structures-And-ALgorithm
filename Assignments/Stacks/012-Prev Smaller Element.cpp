#include <bits/stdc++.h>
using namespace std;


vector<int> previousSmallerElement(int *arr , int size, vector<int> &ans){
	stack<int>st;
	st.push(-1);
	
	for(int i=0 ;i<size ;i++){
		int curr = arr[i];
		
		//ans find kro curr ke lie
		while(st.top() >= curr){
			st.pop();
		}
		
		ans[i] = st.top();
		
		st.push(curr);
	}
	return ans;
}


int main(){
	
	int arr[5] = {8,4,6,2,3};
	int size = 5;
	vector<int>ans(size);
	ans = previousSmallerElement(arr,size,ans);
	for(auto i : ans){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}