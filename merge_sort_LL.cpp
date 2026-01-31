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
Node*merge(Node*left,Node*right){Node*ans=new Node(-1);Node*Nodehead=ans,*Nodetail=ans;
    if(left==nullptr)return right;
    if(right==nullptr)return left;
    while(left!=nullptr&&right!=nullptr){
        if(left->data<right->data){
            insertAtTail(Nodehead,Nodetail,left->data);
            left=left->next;
            
        }
        else{
             insertAtTail(Nodehead,Nodetail,right->data);
             right=right->next;
        }
    }
    while(left!=nullptr){ insertAtTail(Nodehead,Nodetail,left->data);
            left=left->next;}
     while(right!=nullptr){ insertAtTail(Nodehead,Nodetail,right->data);
            right=right->next;}
    return ans->next;
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