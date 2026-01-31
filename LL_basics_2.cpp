#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;this->next=NULL;
        }cout<<"memory is free for node with data "<<value<<endl;
    }
};
void print(Node*head){
    int count=0;Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
        count++;
    }cout<<endl;
}
void valueAthead(Node*&head,int data){
    Node*temp=new Node(data);
    temp->next=head;
    head=temp;
}
void valueAttail(Node*&tail,int  data){
    Node*temp=new Node(data);
    tail->next=temp;
    temp->next=NULL;
    tail=temp;
}
void  valueAtposition(Node*&head,Node*&tail,int pos,int data){
    Node*temp=head;
    int cnt=1;
    if(pos==1){
        valueAthead(head,data);
        return;
    }
    
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }  if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    } if(temp->next==NULL){
        valueAttail(tail,data);
        return;
    }

    Node*node=new Node(data);
    node->next=temp->next;
    temp->next=node;
}
void deleteNode(Node*&head,int pos){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if(pos==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;

    }
    else{
    Node*prev=NULL,*curr=head;
    int count=1;
    while(count<pos){
        prev=curr;
        curr=curr->next;
        count++;
    } if (curr == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}}

int main (){Node*node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
   /*  print(head);
    valueAthead(head,100);
    valueAthead(head,1000);
    valueAthead(head,10000);
    print(head);
    */ 
   valueAttail(tail,100);
    valueAttail(tail,1000);
    valueAttail(tail,10000);
    valueAtposition(head,tail,3,999);
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;
    print(head);
    deleteNode(head,1);
    print(head);
}