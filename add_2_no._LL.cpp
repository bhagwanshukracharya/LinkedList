#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void print(Node* head) {
    if (head == nullptr) {
        cout << "No node exists." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(Node*&head,Node*&tail,int data){
    if(head==nullptr){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        tail->next=new Node(data);
        tail=tail->next;
    }

}
Node*add(Node*head1,Node*head2){int carry=0,sum=0,digit=0;
    Node*temp=nullptr;Node*tempHead=temp,*tempTail=temp;
while(head1!=nullptr&&head2!=nullptr){
    sum=head1->data+head2->data+carry;
    carry=sum/10;
    digit=sum%10;
    insertAtTail(tempHead,tempTail,digit);
    head1=head1->next;   
    head2=head2->next;}
while(head1!=nullptr){
    sum=head1->data+carry;
    carry=sum/10;
    digit=sum%10;
    insertAtTail(tempHead,tempTail,digit);
    head1=head1->next;
}
while(head2!=nullptr){
    sum=head2->data+carry;
    carry=sum/10;
    digit=sum%10;
    insertAtTail(tempHead,tempTail,digit);
    head2=head2->next;
}
while(carry!=0){
    sum=carry;
    carry=sum/10;
    digit=sum%10;
    insertAtTail(tempHead,tempTail,digit);
}
return tempHead;
}
Node* reverse(Node*head){
    Node*curr=head,*prev=nullptr,*next1=nullptr;
    while(curr!=nullptr){
        next1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;
    }return prev;
}
Node*AddToList(Node*head1,Node*head2){Node*ans=0;
   head1= reverse(head1);head2=reverse(head2);
   ans=add(head1,head2);
   ans=reverse(ans);
   return ans;
   }

int main() {
    Node* first = new Node(1);
    first->next = new Node(7);
    first->next->next = new Node(7);
    first->next->next->next = new Node(4);
    Node*second=new Node(3);
    second->next = new Node(7);
   second->next->next = new Node(5);
    Node* head1= first;
    Node* head2=second;
    print(AddToList(head1,head2));
    
    
    return 0; 
}
