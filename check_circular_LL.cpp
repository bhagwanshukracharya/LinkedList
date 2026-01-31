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
bool is_circular(Node*&head){
    if(head==nullptr)return true;
    if(head->next==head)return true;
    if(head->next==nullptr)return false;
    Node*temp=head->next;
    while(temp!=nullptr&&temp!=head){
        temp=temp->next;
    }
    if(temp==nullptr)return false;
    else return true;

}

int main(){
Node*first=new Node(1);
first->next=new Node(2);
first->next->next=new Node(3);
first->next->next->next=new Node(4);
first->next->next->next->next=new Node(5);
first->next->next->next->next->next=new Node(6);
//first->next->next->next->next->next->next=first;
Node*head=first;int k=3;
print(head);
(is_circular(head))?cout<<"is circular":cout<<"non-circular";
}