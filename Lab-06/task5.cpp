//Name : Muhammad Riyan Khalid
//CMS ID : 559090
//Section : BSCS15-D
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front= -1;
int rear= -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout<<"Queue is full (overflow). Cannot insert " << value << "." << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    items[++rear] = value;
    cout << value << " inserted." << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty (underflow). Nothing to remove." << endl;
        return;
    }
    cout << items[front] << " removed." << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<items[front] << " is the value at front." << endl;
}

void display() {
    if (front== -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue from front to rear: ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    peekFront();
    display();

    dequeue();
    dequeue();
    dequeue();

    enqueue(40);
    display();

    return 0;
}