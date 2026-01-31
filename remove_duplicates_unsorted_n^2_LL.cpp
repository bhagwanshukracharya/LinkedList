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
    if(head==nullptr)cout<<"no element/node present !! "<<endl;
    Node*curr=head;
    while(curr->next!=nullptr){
        Node*curr2=curr->next,*prev2=curr;
        while(curr2!=nullptr){
            if(curr->data==curr2->data){
                prev2->next=curr2->next;
                delete curr2;
                curr2=prev2->next;


            }
            else{
                prev2=curr2;
                curr2=curr2->next;
            }
        }
        curr=curr->next;
    }
}

int main(){
Node*first=new Node(4);
first->next=new Node(2);
first->next->next=new Node(3);
first->next->next->next=new Node(4);
first->next->next->next->next=new Node(2);
first->next->next->next->next->next=new Node(4);


Node*head=first;int k=3;

print(head);
remove_duplicates(head);
print(head);

}