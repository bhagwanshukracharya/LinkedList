#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*nxt;
};
void print(Node*header){Node*temp=header;
while(temp!=NULL){cout<<temp->data<<"  ";temp=temp->nxt;}cout<<endl;}

void valueAtheader(Node*&header,int data){
    Node*temp=new Node;
   temp->data=data;
    temp->nxt=header;
    header=temp;
}
int main(){Node*node1=new Node;
    node1->data=10;
    node1->nxt=NULL;
   // cout<<node1->data<<endl<< node1->nxt;
    Node*header=node1;
    print(header);
    valueAtheader(header,100);
     print(header);
    valueAtheader(header,1000);
    print(header);
    delete node1;

}