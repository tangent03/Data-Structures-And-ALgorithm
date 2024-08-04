#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char ch[], int n) {
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (ch[i] == ch[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    char str[] = "madam";
    int n = strlen(str);
    if (checkPalindrome(str, n)) {
        cout << str << " is a palindrome" << endl;
    } else {
        cout << str << " is not a palindrome" << endl;
    }
    return 0;
}
