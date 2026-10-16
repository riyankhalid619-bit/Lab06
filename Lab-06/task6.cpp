//Name : Muhammad Riyan Khalid
//CMS ID : 559090
//Section : BSCS15-D
#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front=-1;
int rear=-1;

void enqueue(int token) {
    if (rear == SIZE - 1) {
        cout << "Queue is full (overflow).Cannot add token " << token << "." << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    items[++rear] = token;
    cout<<"Token " << token << " added."<<endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty (underflow). No customer to serve." << endl;
        return;
    }
    cout << "Serving token " << items[front] << "." << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout << "Queue is empty. No customer waiting." << endl;
        return;
    }
    cout << "Next customer: token " << items[front] << "." << endl;
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

bool readInt(int &value) {
    if (cin >> value) {
        return true;
    }
    if (cin.eof()) {
        return false;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    value = -1;
    return true;
}

int main() {
    int choice = 0;

    do {
        cout << "\n1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        if (!readInt(choice)) {
            break;
        }

        switch (choice) {
            case 1: {
                int token;
                cout << "Enter token number: ";
                if (!readInt(token) || token < 0) {
                    cout << "Invalid token number." << endl;
                    break;
                }
                enqueue(token);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}