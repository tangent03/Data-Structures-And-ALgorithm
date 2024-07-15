								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			//TIME COMPLEXITY - O(N)
			//SPACE COMPLEXITY - O(1)
			
			
//QUESTION : - Find The Union And Intersection Of Two SORTED arrays.

//IN INTERVIEWS - GO FROM BRUTE FORCE SOLUTION -> BETTER SOLUTION -> OPTIMAL SOLUTION


#include <iostream>
#include <vector>
using namespace std;

vector<int> unionArrays( vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArray;
    
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (unionArray.empty() || unionArray.back() != a[i]) {
                unionArray.push_back(a[i]);
            }
            i++;
        } 
        else {
            if (unionArray.empty() || unionArray.back() != b[j]) {
                unionArray.push_back(b[j]);
            }
            j++;
        }
    }
    
    while (i < n1) {
        if (unionArray.empty() || unionArray.back() != a[i]) {
            unionArray.push_back(a[i]);
        }
        i++;
    }
    
    while (j < n2) {
        if (unionArray.empty() || unionArray.back() != b[j]) {
            unionArray.push_back(b[j]);
        }
        j++;
    }
    
    return unionArray;
}


vector<int> intersectingArrays(vector<int>a , vector<int>b){
	int n1=a.size();
	int n2=b.size();
	int i=0;
	int j=0;
	vector<int>intersectingArray;
	while(i<n1 && j<n2){
		if(a[i]<b[j]){
			i++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else{
			intersectingArray.push_back(a[i]);
			i++;
			j++;
		}
	}
	return intersectingArray;
}

int main() {
    int n1, n2;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; ++i) {
        cin >> a[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; ++i) {
        cin >> b[i];
    }

    cout << "Union of the two sorted arrays is: " << endl;
    vector<int> c = unionArrays(a, b);
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    cout << "Intersection of the two sorted arrays is: " << endl;
    vector<int> d = intersectingArrays(a, b);
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}

