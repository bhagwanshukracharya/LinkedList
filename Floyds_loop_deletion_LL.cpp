#include<iostream>
#include<map>
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
void floyds_Loop_Deletion(Node*head){
    if(head==nullptr){cout<<"no node exist !! ";return;}

    Node*slow=head,*fast=head;
    do{
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        slow=slow->next;
    }
    while(fast!=slow&&fast!=nullptr);
    if(fast==nullptr)return;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    Node*temp=slow;
    while(temp->next!=slow){
        temp=temp->next;
    }temp->next=nullptr;
    
    
    /* if(fast==slow)cout<<"loop found!!"<<endl;
    else{cout<<"no loop!!"<<endl;} */
}


int main(){
Node*first=new Node(1);
first->next=new Node(2);
first->next->next=new Node(3);
first->next->next->next=new Node(4);
first->next->next->next->next=new Node(5);
first->next->next->next->next->next=new Node(6);
first->next->next->next->next->next->next=first->next->next;
Node*head=first;int k=3;
floyds_Loop_Deletion(head);
print(head);


}