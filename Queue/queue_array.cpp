#include <iostream>
#define MAX 1000

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        std::cout << value << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front++];
        if (front > rear) front = rear = -1;
        return value;
    }

    int frontElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int rearElement() {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue q(MAX);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    std::cout << q.dequeue() << " dequeued from queue\n";

    std::cout << "Front item is " << q.frontElement() << std::endl;
    std::cout << "Rear item is " << q.rearElement() << std::endl;

    return 0;
}