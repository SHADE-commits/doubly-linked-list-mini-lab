#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string d) : data(d), prev(nullptr), next(nullptr) {}
};

void append(Node*& head, Node*& tail, string data) {
    Node* n = new Node(data);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void displayList(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data;
        if (cur->next) cout << " <-> ";
    }
    cout << endl;
}

void printBackward(Node* tail) {
    cout << "Backward:" << endl;
    for (Node* cur = tail; cur != nullptr; cur = cur->prev) {
        cout << cur->data << endl;
    }
}

bool deleteNode(Node*& head, Node*& tail, string target) {
    Node* cur = head;
    while (cur != nullptr && cur->data != target) cur = cur->next;
    if (cur == nullptr) return false;

    if (cur->prev != nullptr)
        cur->prev->next = cur->next;
    else
        head = cur->next;

    if (cur->next != nullptr)
        cur->next->prev = cur->prev;
    else
        tail = cur->prev;

    delete cur;
    return true;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    append(head, tail, "A");
    append(head, tail, "B");
    append(head, tail, "C");
    append(head, tail, "D");

    cout << "Before delete: ";
    displayList(head);

    deleteNode(head, tail, "C");

    cout << "After delete C: ";
    displayList(head);
    printBackward(tail);
    return 0;
}