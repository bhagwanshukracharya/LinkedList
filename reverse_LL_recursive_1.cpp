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
    if(head==nullptr){
        cout<<"no node exist!!"<<endl;
        return;
    }
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }cout<<endl;
}
void reverse(Node*&head,Node*prev,Node*curr){
    if(curr==nullptr){
        head=prev;
        return;
    }Node*forward=curr->next;
   reverse(head,curr,forward);
   curr->next=prev;
}
int main(){
    Node*first=new Node(3);
    first->next=new Node(5);
    first->next->next=new Node(7);
    Node*head=first;
    print(head);
    Node*prev=nullptr;
    Node*curr=head;
    
  reverse(head,prev,curr);
  print(head);
}