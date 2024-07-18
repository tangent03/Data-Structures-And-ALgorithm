#include <bits/stdc++.h>
using namespace std;

void printNameNTimes(int i, int n){
	//base case
	if(i>n){
		return;
	}
	
	//1 case hum baki recursion
	cout<<"Dixit"<<endl;
	
	printNameNTimes(i+1,n);
	
	
}

void printTillN(int i,int x){
	//base case
	if(i>x){
		return;
	}
	
	//1 case hum
	cout<<i<<endl;
	
	//recursion
	printTillN(i+1,x);
}

void printTillOne(int i,int y){
	//base case
	if(i<1){
		return;
	}
	
	//1 case hum
	cout<<i<<endl;
	
	//recursion
	printTillOne(i-1,y);
}
int main(){
	
	int n=4;
	printNameNTimes(1,n);
	int x=5;
	printTillN(1,x);
	int y=5;
		printTillOne(y,y);
	
	return 0;
}