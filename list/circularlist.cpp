#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // 1. Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself (circular)
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Last node points to new node
            newNode->next = head; // New node points to head
            head = newNode;       // Update head
        }
    }

    // 2. Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Circular reference
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Last node points to new node
            newNode->next = head; // New node points to head
        }
    }

    // 3. Insert at a specific position (1-based index)
    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp->next == head) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == head) { // If only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next; // Traverse to the last node
        }
        Node* toDelete = head;
        head = head->next; // Update head to the next node
        temp->next = head; // Last node points to new head
        delete toDelete;
    }

    // 5. Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == head) { // If only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next; // Traverse to the last node
        }
        prev->next = head; // Second-last node points to head
        delete temp;
    }

    // 6. Delete from a specific position (1-based index)
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                cout << "Position out of range\n";
                return;
            }
        }
        prev->next = temp->next; // Skip the node to delete
        delete temp;
    }

    // 7. Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    // 8. Search for an element
    bool search(int value) {
        if (head == nullptr) return false;
        Node* temp = head;
        do {
            if (temp->data == value) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // 9. Count the nodes
    int count() {
        if (head == nullptr) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    CircularLinkedList cll;

    // Insertion
    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtPosition(15, 2);
    cout << "Circular Linked List: ";
    cll.display(); // Output: 10 15 20

    // Deletion
    cll.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    cll.display(); // Output: 15 20

    cll.deleteFromEnd();
    cout << "After deleting from end: ";
    cll.display(); // Output: 15

    // Search
    cout << (cll.search(15) ? "15 Found\n" : "15 Not Found\n"); // Output: 15 Found

    // Count
    cout << "Total Nodes: " << cll.count() << "\n"; // Output: 1

    return 0;
}