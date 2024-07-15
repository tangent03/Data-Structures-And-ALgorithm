#include <bits/stdc++.h>
using namespace std;

bool checkRedundant(string &str){
	stack<char>st;
	
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		
		if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			st.push(ch);
		}
		else if(ch==')'){
			int operatorCount = 0;
			while(!st.empty() && st.top()!='('){
				char temp = st.top();
				if(temp=='+' || temp=='-' || temp=='*' || temp=='/'){
					operatorCount++;
				}
				st.pop();
			}
			//yahan tab pohvhoge jab stack empty ya stack ke top pe bracket hoga;
			st.pop();
			
			if(operatorCount==0){
				return true;
			}
		}
	}
	
	//yahan aaya to har bracket ke bich me ek operator hoga
	return false;
}

int main(){
	string str = "((a+b)*(c+d))";
	bool ans = checkRedundant(str);
	
	if(ans==true){
		cout<<"Redundant Brackets Present"<<endl;
	}
	else{
		cout<<"Redundant Brackets Not Present"<<endl;
	}
}