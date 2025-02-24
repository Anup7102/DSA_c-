#include <iostream>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the list from the beginning
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Function to display the list from the end
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

    // Function to delete a node from the list
    void deleteNode(int key) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) return; // Node not found

        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;

        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;

        delete temp;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    std::cout << "List in forward order: ";
    list.displayForward();

    std::cout << "List in backward order: ";
    list.displayBackward();

    list.deleteNode(20);
    std::cout << "List after deleting 20: ";
    list.displayForward();

    return 0;
}