#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "You cannot. Queue is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr)
                tail = nullptr; // important to reset tail when queue becomes empty
        }
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }

    void printQ() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.printQ(); // Expected output: 5 10 15

    q.pop();
    q.printQ(); // Expected output: 10 15

    cout << "Front element: " << q.front() << endl; // Output: 10
    return 0;
}
