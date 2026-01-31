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
    Node*head1=head;
    Node*head2=cloneHead;
    Node*next1=nullptr;
    while(head1!=nullptr&&head2!=nullptr){
        next1=head1->next;
        head1->next=head2;
        head1=next1;

        next1=head2->next;
        head2->next=head1;
        head2=next1;
    }
    temp=head;head2=cloneHead;
    while(temp!=nullptr){
        temp->next->random=temp->random?temp->random->next:nullptr;
        temp=temp->next;
        if(temp!=nullptr)
        temp=temp->next;
    }
     temp=head;head2=cloneHead;
    while(temp!=nullptr){
        temp->next=temp->next->next;

        head2->next=head2->next?head2->next->next:nullptr;
        temp=temp->next;
        head2=head2->next;
    }
    return cloneHead;
   

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