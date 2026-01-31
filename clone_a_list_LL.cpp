#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
int data;
Node*next;
Node*random;
Node(int data){
this->data=data;
next=nullptr;
random=nullptr;
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
void insertAtTail(Node*&head,Node*&tail,int data){
     Node*temp=new Node(data);
    if(head==nullptr) {head=tail=temp;return;}
    tail->next=temp;
    tail=tail->next;
}
Node*copylist(Node*head){Node*temp=head;
    Node*cloneHead=nullptr,*cloneTail=nullptr;
    while(temp!=nullptr){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    temp=head;
    Node*head2=cloneHead;
    unordered_map<Node*,Node*>mapping;
    while(temp!=nullptr){
        mapping[temp]=head2;
        temp=temp->next;
        head2=head2->next;
    }
    head2=cloneHead;
    temp=head;
    while(temp!=nullptr){
        //1 line gpt ne suggest kiya hai ki agar clone creation random ho tab next set rhe
        head2->next = mapping[temp->next];
        head2->random=temp->random?mapping[temp->random]:nullptr;
        temp=temp->next;
        head2=head2->next;
    }return cloneHead;

}

int main(){
    Node*first=new Node(1);
    first->next=new Node(2);
    first->next->next=new Node(3);
    first->next->next->next=new Node(4);
    first->next->next->next->next=new Node(5);
    first->random= first->next->next;
    first->next->random=first;
    first->next->next->random= first->next->next->next->next;
    first->next->next->next->random=first->next->next;
    first->next->next->next->next->random=first->next;
    Node*head=first;
    cout<<"Original List:- "<<endl;
    print(head);
    cout<<"Sorted List:- "<<endl;
  print( copylist(head));
    
    

}