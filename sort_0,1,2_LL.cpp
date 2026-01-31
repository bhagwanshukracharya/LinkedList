#include<iostream>
#include<map>
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
void sort(Node*head){int zero_count=0,one_count=0,two_count=0;
    Node*temp=head;
    while(temp!=nullptr){
        if(temp->data==0)zero_count++;
       else if(temp->data==1)one_count++;
       else{two_count++;}
       temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(zero_count!=0){
            temp->data=0;
            zero_count--;
        }
        else if(one_count!=0){
            temp->data=1;
            one_count--;
        }
        else{
            temp->data=2;
            two_count--;
        }
        temp=temp->next;
    }
    
}


int main() {
    Node* first = new Node(2);
    first->next = new Node(1);
    first->next->next = new Node(1);
    first->next->next->next = new Node(1);
    first->next->next->next->next = new Node(2);
    first->next->next->next->next->next = new Node(0);
    first->next->next->next->next->next->next = new Node(0);
    Node* head = first;
    cout << "Original List: ";
    print(head);
    sort(head);
    cout << "Sorted List : ";
    print(head);

    return 0;
}
