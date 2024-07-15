#include <bits/stdc++.h>
using namespace std;

void printFirstNegetive(int *arr,int n, int k){
	deque<int>dq;
	
	//process first k elements-first window
	
	for(int i=0;i<k;i++){
		int element = arr[i];
		if(element <0){
			dq.push_back(i);
		}
	}
	
	//process remaining windows
	//->removeal
	//->addition
	
	for(int i=k;i<n;i++){
		//aage badhne se phele
		// purani window ka ans nikalo
		
		if(dq.empty()){
			cout<<"0"<<endl;
		}
		else{
			cout<<arr[dq.front()]<<" ";
		}
		
		
		//removal- jo bhi index out
		//of range hai use queue se remove krdo
		if(i - dq.front() >=k){
			dq.pop_front();
		}
		
		//addition
		if(arr[i]<0){
			dq.push_back(i);
		}
		
	}
	
	//last window ka answer print krdo
	if(dq.empty()){
		cout<<"0"<<endl;
	}
	else{
		cout<<arr[dq.front()]<<" ";
	}
}

int main(){
	
	// queue<int>q;
	// q.push(-2);
	// q.push(-5);
	// q.push(3);
	// q.push(-1);
	// q.push(-2);
	// q.push(0);
	// q.push(5);
	int arr[] = {2,-5,4,-1,-2,0,5};
	int size = 7;
	int k = 3;
	
	printFirstNegetive(arr,size,k);
	
	
	// cout<<"Print Queue"<<endl;
// 	
	// while(!q.empty()){
		// int element = q.front();
		// q.pop();
		// cout<<element<<" ";
	// }
	
	
}