#include <iostream>
using namespace std;

void convertToUpperCase(char ch[], int n) {
    int index = 0;
    while (ch[index] != '\0') {
        char currCharacter = ch[index];
        // check if lowercase, then convert to uppercase
        if (currCharacter >= 'a' && currCharacter <= 'z') {
            ch[index] = currCharacter - 'a' + 'A';
        }
        index++;
    }
}

int main() {
    char str[] = "hello world";
    int n = sizeof(str) / sizeof(str[0]);
    convertToUpperCase(str, n);
    cout << str << endl; // Output should be "HELLO WORLD"
    return 0;
}
