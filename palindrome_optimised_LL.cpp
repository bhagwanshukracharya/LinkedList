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
bool check_palindrome(Node*head1,Node*head2){
while(head2!=nullptr){
    if(head1->data!=head2->data)return false;
    head1=head1->next;
    head2=head2->next;
}return true;
}
Node*getmid(Node*&head){
    Node*slow=head,*fast=head->next;
    while(fast!=nullptr){
        fast=fast->next;
        if(fast!=nullptr)
        fast=fast->next;
        slow=slow->next;
    }return slow;
}
Node* reverse(Node*head){
    Node*prev=nullptr,*curr=head,*next1=nullptr;
    while(curr!=nullptr){
        //if(next1!=nullptr)
        next1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;

    }return prev;
}

int main() {
    Node* first = new Node(12);
    first->next = new Node(7);
    first->next->next = new Node(7);
    first->next->next->next = new Node(12);
    Node* head = first;
    cout << "Original List1: ";
    print(head);
    Node*middle=getmid(head);
    Node*head2=reverse(middle->next);
    check_palindrome(head,head2)?cout<<"is_Palindrome!! "<<endl:cout<<"not_a_Palindrome!! "<<endl;
    //head2=reverse(middle->next);
    print(head2);
    return 0; 
}
