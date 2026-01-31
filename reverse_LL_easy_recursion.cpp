#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

// Function to print the linked list
void print(Node* head){
    if(head == nullptr){
        cout << "No nodes exist!!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list using recursion
Node* reverse(Node* head){
    // Base case: if head is nullptr or only one node, no need to reverse
    if(head == nullptr || head->next == nullptr) 
        return head;

    // Recur for the rest of the list
    Node* newHead = reverse(head->next);

    // Reverse the links
    head->next->next = head;  // Point the next node's next to current node
    head->next = nullptr;     // Make current node the last node
//cout<< head->data<<endl;
    return newHead;  // Return the new head of the reversed list
}

int main(){
    // Creating a linked list: 3 -> 5 -> 7 -> 9
    Node* first = new Node(3);
    first->next = new Node(5);
    first->next->next = new Node(7);
    first->next->next->next = new Node(9);

    Node* head = first;

    cout << "Original List: ";
    print(head);  // Print original list

    // Reverse the linked list and get the new head
    head = reverse(head);

    cout << "Reversed List: ";
    print(head);  // Print reversed list
}
