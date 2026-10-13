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

void printForward(Node* head) {
    cout << "Forward:" << endl;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << endl;
    }
}

void printBackward(Node* tail) {
    cout << "Backward:" << endl;
    for (Node* cur = tail; cur != nullptr; cur = cur->prev) {
        cout << cur->data << endl;
    }
}

bool insertAfter(Node* head, Node*& tail, string target, string newData) {
    Node* cur = head;
    while (cur != nullptr && cur->data != target) cur = cur->next;
    if (cur == nullptr) return false;

    Node* n = new Node(newData);
    n->prev = cur;
    n->next = cur->next;
    if (cur->next != nullptr)
        cur->next->prev = n;
    else
        tail = n;
    cur->next = n;
    return true;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    append(head, tail, "Song A");
    append(head, tail, "Song B");
    append(head, tail, "Song C");
    append(head, tail, "Song D");
    append(head, tail, "Song E");
    displayList(head);
    printForward(head);
    printBackward(tail);
    cout << "\n--- After inserting Song X ---" << endl;
    insertAfter(head, tail, "Song B", "Song X");
    printForward(head);
    printBackward(tail);
    return 0;
}