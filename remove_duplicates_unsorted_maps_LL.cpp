#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void print(Node* head) {
    if (head == nullptr) {
        cout << "No node exists." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void sort(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    map<int, bool> seen;  // Map to store node values and check for duplicates

    while (curr != nullptr) {
        // Check if the current node's value is already in the map
        if (seen.find(curr->data) != seen.end()) {
            // If the value exists in the map, remove the current node
            prev->next = curr->next;
            delete curr;
        } else {
            // If the value doesn't exist in the map, add it to the map and continue
            seen[curr->data] = true;
            prev = curr;
        }
        curr = prev->next;  // Move to the next node
    }
}

int main() {
    Node* first = new Node(0);
    first->next = new Node(4);
    first->next->next = new Node(4);
    first->next->next->next = new Node(5);
    first->next->next->next->next = new Node(4);
    first->next->next->next->next->next = new Node(1);

    Node* head = first;
    cout << "Original List: ";
    print(head);

    sort(head);

    cout << "Sorted List (Duplicates Removed): ";
    print(head);

    return 0;
}
