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
    if(head==nullptr){cout<<"no node exist"<<endl;return;}
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
Node*kreverse(Node*&head,int k){
    if(head==nullptr)return head;
    Node*prev=nullptr,*curr=head,*forward=nullptr;
    int count =0;
    while(count<k&&curr!=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }if(forward!=nullptr)
    head->next=kreverse(forward,k);
    return prev;

}

int main(){
Node*first=new Node(1);
first->next=new Node(2);
first->next->next=new Node(3);
first->next->next->next=new Node(4);
first->next->next->next->next=new Node(5);
first->next->next->next->next->next=new Node(6);
Node*head=first;int k=3;
print(head);
print(kreverse(head,k));
}