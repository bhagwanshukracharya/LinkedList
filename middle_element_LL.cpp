#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
Node* getmid(Node*head){
    if(head==nullptr||head->next==nullptr)return head;
    if(head->next->next==nullptr)return head->next;
    Node*temp=head;int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    int mid=count/2;
    temp=head;count=0;
    while(count<mid){
        temp=temp->next;
        count++;
    }return temp;
}

// Function to print the linked list
void print(Node* head){
    if(head == nullptr){
        cout << "No nodes exist!!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    // Creating a linked list: 3 -> 5 -> 7 -> 9
    Node* first = new Node(3);
    first->next = new Node(5);
    first->next->next = new Node(7);
    first->next->next->next = new Node(9);
    /* first->next->next->next->next = new Node(11);
    first->next->next->next->next->next = new Node(13); */
    

    Node* head = first;
    print(head);
    Node*NH =getmid(head);
    cout<<"middle element is:- "<<NH->data<<endl;
    

}
