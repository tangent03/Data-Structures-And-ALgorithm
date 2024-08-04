#include<bits/stdc++.h>
using namespace std;

/*
Function to remove adjacent duplicates from a string.
Time Complexity: O(n) - Each character is processed once.
Space Complexity: O(n) - In the worst case, all characters could be in the stack.
*/
string removeDuplicates(string s) {
    int n = s.size();
    stack<char> st;
    int i = 0;

    // Iterate through the string
    while (i < n) {
        // If the stack is empty or the top of the stack is not equal to the current character,
        // push the current character onto the stack
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            // If the top of the stack is equal to the current character, pop the stack
            st.pop();
        }
        i++;
    }

    // Build the result string from the stack
    string ans = "";
    while (!st.empty()) {
        char ele = st.top();
        st.pop();
        ans = ans + ele;
    }

    // Reverse the string to get the correct order
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string input = "abbaca"; // Example input
    string result = removeDuplicates(input);
    cout << "Result after removing duplicates: " << result << endl; // Expected output: "ca"
    return 0;
}
