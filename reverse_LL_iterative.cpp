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
void reverse(Node*&head){
    if(head==nullptr||head->next==nullptr){
        return;
    }
    Node*prev=nullptr;
    Node*curr=head;
    Node*forward=curr->next;
    while(curr!=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }head=prev;
}
int main(){
    Node*first=new Node(3);
    first->next=new Node(5);
    first->next->next=new Node(7);
    Node*head=first;
    print(head);
  reverse(head);
  print(head);
}