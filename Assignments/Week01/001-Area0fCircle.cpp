							//JAI SHREE RAM
							//JAI BAJRANG BALI
							//OM NAMAH SHIVAYE



//Week 1 Assignments (Other than Patterns)

//QUESTION 1 :- Make a function to display area of circle


#include <bits/stdc++.h>
using namespace std;



//QUESTION 1 :- Make a function to display area of circle

float area_circle(float radius){
	float area = 3.14 * radius * radius;
	return area;
}


int main(){
	float radius;
	cin>>radius;
	float area = area_circle(radius);
	cout<<"Area of Circle is : "<<area<<endl;
	return 0;
	
}