#include<iostream>
#include<vector>
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
bool palindrome(const vector<int>&arr){
int s=0,e=arr.size()-1;
while(s<=e){
    if(arr[s++]!=arr[e--])return false;
}return true;
}
void check_palindrome(Node*head){
    Node*temp=head;
    vector<int>arr;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    (palindrome(arr))?cout<<"palindrome !! ":cout<<"not a palindrome !! ";
}
int main() {
    Node* first = new Node(1);
    first->next = new Node(7);
    first->next->next = new Node(7);
    first->next->next->next = new Node(1);
   
    Node* head = first;
    cout << "Original List1: ";
    print(head);
    check_palindrome(head);
    
    
    

    return 0; 
}
