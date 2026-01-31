#include<iostream>
using namespace std;
class Node{
    public:
int data;
Node*next;
Node(int data){
this->data=data;
next=nullptr;
}

};
void print(Node*head){
    if(head==nullptr){cout<<"no Node exist!! "<<endl;return;}
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }cout<<endl;   
}
Node*getmid(Node*head){
    if(head==nullptr||head->next==nullptr)return head;
    Node*slow=head,*fast=head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        }return slow;
}
void insertAtTail(Node*&head,Node*&tail,int data){
     Node*temp=new Node(data);
    if(head==nullptr) {head=tail=temp;return;}
    tail->next=temp;
    tail=tail->next;
}
Node* merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Initialize head
    if(left->data < right->data){
        head = tail = left;
        left = left->next;
    } else {
        head = tail = right;
        right = right->next;
    }

    // Merge by re-linking nodes
    while(left && right){
        if(left->data < right->data){
            tail->next = left;
            tail = left;
            left = left->next;
        } else {
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }

    // Attach remaining nodes
    tail->next = (left) ? left : right;

    return head;
}

Node*mergesort(Node*head){
    if(head==nullptr||head->next==nullptr)return head;
     Node*mid=getmid(head);
    Node*left=head;
    Node*right=mid->next;
    mid->next=nullptr;
    left=mergesort(left);
    right=mergesort(right);
    return merge(left,right);
    
    
}

int main(){
    Node*first=new Node(9);
    first->next=new Node(8);
    first->next->next=new Node(7);
    first->next->next->next=new Node(6);
    first->next->next->next->next=new Node(5);
    Node*head=first;
    cout<<"Original List:- "<<endl;
    print(head);
    cout<<"Sorted List:- "<<endl;
  print( mergesort(head));
    
    

}