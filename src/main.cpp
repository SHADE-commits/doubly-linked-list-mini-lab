#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string d) : data(d), prev(nullptr), next(nullptr) {}
};

int main() {
    return 0;
}