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
void check_loop(Node*head){
    if(head==nullptr){cout<<"no node exist!!";return;}
    map<Node*,bool>visited;
    Node*temp=head;
    while(visited[temp]!=true&&temp!=nullptr){
        visited[temp]=true;
        temp=temp->next;
    }if(temp==nullptr)cout<<"loop not present !!"<<endl;
    else cout<<"loop is present at :- "<<temp->data<<endl;
}

int main(){
Node*first=new Node(1);first->next=nullptr;
/* first->next=new Node(2);
first->next->next=new Node(3);
first->next->next->next=new Node(4);
first->next->next->next->next=new Node(5);
first->next->next->next->next->next=new Node(6);
first->next->next->next->next->next->next=first->next->next->next; */
Node*head=first;int k=3;
//print(head);
check_loop(head);

}