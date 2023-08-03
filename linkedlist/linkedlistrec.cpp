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


Node * insertatindexa(Node * head, int data, int a){
    Node * temp=head;
    int ll=1;
    while(ll!=a){
        temp=temp->next;
        ll++;
    }
    Node * nn=new Node(data);
    nn->next=temp->next;

    temp->next=nn;
    return head;
}

// 1->2->3->4
// 1->2->3->5->4

void deletefromindexa(Node *head, int a){
    Node *temp=head;
    int pp=1;
    while(pp!=a){
        temp=temp->next;
        pp++;
    }
    Node *dell=temp->next;
    temp->next=temp->next->next;
    delete dell;
}

void insertrec(Node *head,int data,int a){
    if(a==1){
        Node * temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
        
    }
    else{
        insertrec(head->next,data,a-1);
    }
}

void deleterec(Node * head, int a){
    if(a==1){
        Node * temp=head->next;
        head->next=head->next->next;
        delete temp;
    }
    else{
        deleterec(head->next,a-1);
    }




}
int main(){
    Node * head=takeinput();
    
    printll(head);
    // Node * head2=insertatindexa(head,5,3);
    // printll(head);
    // deletefromindexa(head,2);
    // printll(head);

    // insertrec(head,10,3);
    deleterec(head,3);
    printll(head);
    return 0;
}