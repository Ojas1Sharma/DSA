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


void removedup(Node * head){
    Node * h1=head;
    Node * h2=head->next;
    while(h2!=NULL){
        if(h1->data!=h2->data){
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data==h2->data){
            
            while(h1->data==h2->data){
            h2=h2->next;
            if (h2==NULL){
                break;
            }
            }
            h1->next=h2;
        }

    }
    h1->next=h2;

}





int main(){
    Node * head=takeinput();
    
    printll(head);
    removedup(head);
    printll(head);
    return 0;
}