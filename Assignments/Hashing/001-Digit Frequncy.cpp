/*

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	//precompute
	int hash[13] = {0};
	for(int i=0;i<n;i++){
		hash[arr[i]] += 1;
	}
	
	int q;
	cin>>q;
	while(q--){
		int number;
		cin>>number;
		
	//fetch
	
	cout<<hash[number] <<endl;
	}
	
	
	return 0;
}

*/
//if we are doing hashing witha rray we can do it only till 10^6 not beyond that inside main.
//but if we initailise it globally then we can go till 10^7

//ASCII - American Standard Code for Information Interchange.


//map stores the value in Sorted Order

#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	
	//pre-compute
	
	map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
	
	
	//iterating the map
	for(auto it : mpp){
		cout<<it.first << "->" << it.second<<endl;
	}
	
	int q;
	cin>>q;
	
	while(q--){
		int number;
		cin>>number;
		
		//fetch
		cout<<mpp[number]<<endl;
	}
	
	
	
	return 0;
}