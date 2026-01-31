#include<iostream>
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
Node* mergeList(Node*first,Node*second){
        if(first->next==nullptr){
        first->next=second;
        return first;
    }
    Node*curr1=first;
    Node*curr2=second;
    Node*next1=curr1->next;
    Node*next2=curr2->next;
    
    while(next1!=nullptr&&curr2!=nullptr){
        if(curr2->data>=curr1->data&&curr2->data<next1->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==nullptr){
                curr1->next=curr2;
                return first;
            }
        }
    }return first;
}
Node*check(Node*first,Node*second){
if(!first)return second;
    if(!second)return first;
    if(first->data<=second->data)
   return(mergeList(first,second));
   else 
    return(mergeList(second,first));
}
int main() {
    Node* first = new Node(7);
    first->next = new Node(7);
    first->next->next = new Node(7);
    Node*second = new Node(9);
    second->next = new Node(10);
    second->next->next= new Node(10);
    second->next->next->next= new Node(19);
    Node* head1 = first;
    Node* head2 = second;
    cout << "Original List1: ";
    print(head1);
    cout << "Original List2: ";
    print(head2);
    
     cout << "Sorted List : ";
     print(check(first,second));
    
    

    return 0; 
}
