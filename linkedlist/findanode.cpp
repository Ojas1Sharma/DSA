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

int m;
int findanode(Node * head, int d){
if(head->data==d){
    return m;
}
else{
    m++;
    findanode(head->next,d);
}
}



int findcount(Node * head){
    int C=0;
    while(head!=NULL){
        C++;
        head=head->next;
    }
    return C;
}

Node* appendltof(Node *head, int n){
int count=findcount(head);
int r=count-n;
Node * h2=head;
for(int i=0;i<r-1;i++){
    h2=h2->next;
}
Node * temp=h2;
h2=h2->next;
temp->next=NULL;

Node * temp2= h2;
for(int i=0;i<n-1;i++){
temp2=temp2->next;
}
temp2->next=head;
return h2;
}

int main(){
    Node * head=takeinput();
    
    printll(head);
    // int index=findanode(head,3);
    // cout<<index;
    Node * h3=appendltof(head,3);
    printll(h3);

    return 0;
}