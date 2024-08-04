#include <bits/stdc++.h>
using namespace std;

// Brute Force Method
int majorityElementBruteForce(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            return v[i];
        }
    }
    return -1;
}

// Better Solution using HashMap
int majorityElementBetterSolution(vector<int>& v) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < v.size(); i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > v.size() / 2) {
            return it.first;
        }
    }
    return -1;
}

// Optimal Solution using Moore's Voting Algorithm
int majorityElementOptimalSolution(vector<int>& v) {
    int candidate = INT_MIN;
    int life = 0;
    int n = v.size();
    for(int i=0;i<n;i++){
    	if(v[i] == candidate){
    		life++;
    	}
    	else if(life == 0){
    		candidate = v[i];
    		life = 1;
    	}
    	else{
    		life--;
    	}
    }
    return candidate;
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int ansBruteForce = majorityElementBruteForce(arr);
    cout << "The majority element using Brute Force is: " << ansBruteForce << endl;

    int ansBetterSolution = majorityElementBetterSolution(arr);
    cout << "The majority element using Better Solution is: " << ansBetterSolution << endl;

    int ansOptimalSolution = majorityElementOptimalSolution(arr);
    cout << "The majority element using Optimal Solution is: " << ansOptimalSolution << endl;

    return 0;
}
