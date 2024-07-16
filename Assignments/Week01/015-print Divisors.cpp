#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n){
	vector<int> v;
	
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			v.push_back(i);
			if((n/i) != i){
				v.push_back(n/i);
			}
		}
	}
	
	sort(v.begin(),v.end());
	for(auto it : v){
		cout<<it<<" ";
	}
}

int main(){
	int n;
	cin>>n;
	printDivisors(n);
	
	return 0;
}


//i * n/i ka pattern banta hai
//1 * 36
//2* 18
//3* 12
//4* 9
//6* 6

//isme n/i != i hona chaiye to dubara print krna