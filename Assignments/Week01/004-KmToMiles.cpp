								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - conert km to miles

//
// 

#include <bits/stdc++.h>
using namespace std;

double KmToMiles(double km){
	double OneKmInMiles= 0.621371;
	double miles = km * OneKmInMiles;
	return miles;
}


int main() {
    double km;
    cin>>km;
    double miles = KmToMiles(km);
    cout<<km<<"km in Miles is "<<miles;
}
