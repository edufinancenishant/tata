#include <iostream>
using namespace std;

#define MAX 5   // Maximum number of orders

class Queue {
    int front, rear;
    int q[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void addJob(int job) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot take more orders.\n";
            return;
        }
        if (front == -1) front = 0;
        q[++rear] = job;
        cout << "Order " << job << " added.\n";
    }

    void serveJob() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Order " << q[front] << " served.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending orders: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue obj;
    int ch, job;

    do {
        cout << "\n--- Pizza Parlor Order Menu ---\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter Order Number: ";
                cin >> job;
                obj.addJob(job);
                break;
            case 2:
                obj.serveJob();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (ch != 4);

    return 0;
}
