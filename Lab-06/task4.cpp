//Name : Muhammad Riyan Khalid
//CMS ID : 559090
//Section : BSCS15-D
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full (overflow). Cannot insert " << value << "." << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    items[++rear] = value;
    cout << value << " inserted." << endl;
}

void display() {
    if (front == -1) {
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
    display();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    enqueue(40);
    enqueue(50);
    display();

    enqueue(60);

    return 0;
}