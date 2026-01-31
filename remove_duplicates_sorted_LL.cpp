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
void remove_duplicates(Node*head){
    if(head==nullptr){cout<<"nothing is there!!";return;}
    Node*curr=head;
    Node*nexxt=nullptr;
    while(curr->next!=nullptr){
        if(curr->data==curr->next->data){
            nexxt=curr->next->next;
            curr->next->next=nullptr;
            delete curr->next;
            curr->next=nexxt;
            

        }
        else{
            curr=curr->next;
        }
    }

}

int main(){
Node*first=new Node(0);
first->next=new Node(2);
first->next->next=new Node(2);
first->next->next->next=new Node(3);
first->next->next->next->next=new Node(3);
first->next->next->next->next->next=new Node(4);

Node*head=first;int k=3;

print(head);
remove_duplicates(head);
print(head);

}