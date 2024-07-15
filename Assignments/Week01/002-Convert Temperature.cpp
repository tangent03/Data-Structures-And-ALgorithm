								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - conert temperature - 2469
// 
// You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.
// 
// You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].
// 
// Return the array ans. Answers within 10-5 of the actual answer will be accepted.
// 
// Note that:
// 
// Kelvin = Celsius + 273.15
// Fahrenheit = Celsius * 1.80 + 32.00
//  
// 
// Example 1:
// 
// Input: celsius = 36.50
// Output: [309.65000,97.70000]
// Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
// Example 2:
// 
// Input: celsius = 122.11
// Output: [395.26000,251.79800]
// Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
//  
// 
// Constraints:
// 
// 0 <= celsius <= 1000
// 

#include <bits/stdc++.h>
using namespace std;

// Function to convert Celsius to Kelvin and Fahrenheit
vector<double> convertTemperature(double celsius) {
    double kelvin = 273.15 + celsius;
    double fahrenheit = celsius * 1.80 + 32.00;

    vector<double> v;
    v.push_back(kelvin);
    v.push_back(fahrenheit);
    return v;
}

int main() {
    double celsius;
    
    cin >> celsius;

    vector<double> result = convertTemperature(celsius);

    cout << "Kelvin: " << result[0] << endl;
    cout << "Fahrenheit: " << result[1] << endl;

    return 0;
}
