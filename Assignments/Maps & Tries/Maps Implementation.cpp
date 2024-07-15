#include <bits/stdc++.h>
using namespace std;


int main(){
	
	//creation of map
	unordered_map<string,int>mapping;
	
	//insertion
	pair<string,int> p = make_pair("Aman",20);
	
	pair<string,int> q("Dixit",24);
	
	pair<string,int> r;
	r.first="Arun";
	r.second = 21;
	
	//INSERTION
	mapping.insert(p);
	mapping.insert(q);
	mapping.insert(r);
	
	cout<<"Size of Map is : "<<mapping.size()<<endl;
	
	//ACCESS
	cout<<mapping.at("Aman")<<endl;
	cout<<mapping["Aman"]<<endl;
	
	
	//SEARCHING - count - vo key agar present hai map me to 1 nahi to 0
	cout<<mapping.count("Aman")<<endl;
	cout<<"Size of Map is : "<<mapping.size()<<endl;
	
	//FIND
	if(mapping.find("Dixit") != mapping.end()){
		cout<<"FOUND"<<endl;
	}
	else{
		cout<<"NOT FOUND"<<endl;
	}
	
	cout<<"Size of Map is : "<<mapping.size()<<endl;
	cout<<mapping["Kumar"]<<endl;
	cout<<"Size of Map is : "<<mapping.size()<<endl;
	//agar square bracket is acces dhundte hai aur nahi milta to last me jake
	// vo entry save hojati hai
	//aur size badh jata hai
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}