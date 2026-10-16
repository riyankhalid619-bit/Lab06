//Name : Muhammad Riyan Khalid
//CMS ID : 559090
//Section : BSCS15-D
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
public:
    Node* top = nullptr;

    ~Stack() {
        clearStack();
    }

    void push(int value) {
        Node* n = new Node(value);
        n->next = top;
        top = n;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty (underflow)." << endl;
            return;
        }
        Node* curr = top;
        top = top->next;
        delete curr;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << top->data << " is the value at top." << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void clearStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node* curr = top;
        cout << "Stack from top to bottom: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(15);
    s.push(25);
    s.display();

    s.pop();
    s.peek();
    s.display();

    Stack empty;
    empty.pop();

    s.clearStack();
    s.display();

    return 0;
}
