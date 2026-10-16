//Name : Muhammad Riyan Khalid
//CMS ID : 559090
//Section : BSCS15-D
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX = 20;
char stackArr[MAX];
int top = -1;
bool push(char c) {
    if (top == MAX - 1) {
        cout << "Stack is full (overflow)." << endl;
        return false;
    }
    stackArr[++top] = c;
    return true;
}
char pop() {
    if (top == -1) {
        cout << "Stack is empty (underflow)." << endl;
        return '\0';
    }
    return stackArr[top--];
}
int main() {
    char word[100];

    cout << "Enter a word (max 20 characters): ";
    cin >> setw(100) >> word;

    if (strlen(word) > MAX) {
        cout << "Word is too long. Maximum is " << MAX << " characters." << endl;
        return 0;
    }

    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]);
    }

    cout << "Reversed: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}