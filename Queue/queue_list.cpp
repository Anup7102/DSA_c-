#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();  // Attempt to dequeue from an empty queue

    return 0;
}