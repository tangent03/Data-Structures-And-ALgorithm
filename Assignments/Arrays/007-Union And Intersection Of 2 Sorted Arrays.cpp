#include <bits/stdc++.h>
using namespace std;

/*
Brute Force

Time Complexity: O((m+n)log(m+n)). Inserting a key in a set takes
 logN time, where N is the number of elements in the set. At max,
  the set can store m+n elements (when there are no common 
  elements and elements in arr1 and arr2 are distinct). 
  So inserting the m+n-th element takes log(m+n) time. 
  Upon approximation across insertion of all elements 
  in the worst case, it would take O((m+n)log(m+n)) time.

Using HashMap also takes the same time. On average, insertion in
 unordered_map takes O(1) time, but sorting the union vector
  takes O((m+n)log(m+n)) time because at max, the union vector
   can have m+n elements.

Space Complexity: O(m+n) {If space of the union vector is
 considered}
O(1) {If space of the union vector is not considered}
*/

// Function to find union using a set (Brute Force)
vector<int> FindUnionSet(int arr1[], int arr2[], int n, int m) {
    set<int> st;
    vector<int> Union;

    for (int i = 0; i < n; i++) {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        st.insert(arr2[i]);
    }

    for (auto it : st) {
        Union.push_back(it);
    }
    return Union;
}

// Function to find union using two-pointer technique
/*
Time Complexity is O(n+m);
*/
vector<int> FindUnion(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        } else {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

// Function to find intersection using brute force approach
/*
Time Complexity is O(n1*n2)
*/
vector<int> intersectionArrayBruteForce(vector<int>& a, vector<int>& b, int n, int m) {
    vector<int> ans;
    vector<int> vis(m, 0);  // Initialize visited array with 0

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && vis[j] == 0) {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
        }
    }
    return ans;
}

// Function to find intersection using two-pointer technique
/*
Time Complexity is O(n + m)
*/
vector<int> intersectionArray(vector<int>& a, vector<int>& b, int n, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    vector<int> vec1(arr1, arr1 + n);
    vector<int> vec2(arr2, arr2 + m);

    // Find Union
    vector<int> Union = FindUnion(vec1, vec2);
    cout << "Union of arr1 and arr2 is: ";
    for (auto& val : Union) {
        cout << val << " ";
    }
    cout << endl;

    // Find Intersection using brute force
    vector<int> IntersectionBF = intersectionArrayBruteForce(vec1, vec2, n, m);
    cout << "Intersection of arr1 and arr2 (Brute Force) is: ";
    for (auto& val : IntersectionBF) {
        cout << val << " ";
    }
    cout << endl;

    // Find Intersection using two-pointer technique
    vector<int> Intersection = intersectionArray(vec1, vec2, n, m);
    cout << "Intersection of arr1 and arr2 (Two-Pointer) is: ";
    for (auto& val : Intersection) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
