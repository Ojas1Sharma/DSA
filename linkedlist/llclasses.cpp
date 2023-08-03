#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


void printll(Node * head){
    Node * temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


Node * takeinput(){
int a;
cin>>a;
Node * head=new Node(-1);
Node * tail=head;
if (a!=-1){
    head->data=a;
    
}
else{
    return head;
}

cin>>a;
while(a!=-1){
    Node * temp=new Node(a);
    tail->next=temp;
    tail=temp;
    cin>>a;

}
return head;



}

