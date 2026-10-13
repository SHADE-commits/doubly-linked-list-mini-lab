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

    // Browser history
    append(head, tail, "google.com");
    append(head, tail, "youtube.com");
    append(head, tail, "github.com");
    append(head, tail, "tokopedia.com");
    append(head, tail, "telkomuniversity.ac.id");

    cout << "Browser history:" << endl;
    displayList(head);
    printForward(head);
    printBackward(tail);

    cout << "\n--- Visit instagram.com after youtube.com ---" << endl;
    insertAfter(head, tail, "youtube.com", "instagram.com");