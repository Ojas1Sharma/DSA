#include <iostream>
// #include "midpoint.cpp"
using namespace std;


struct Node{
    int data;
    Node * next;
    Node(int a){
        this->data=a;
        this->next=NULL;

    }
};


Node * inputll(){
    int a;
    cin>>a;
    
    if(a!=-1){
        Node * head= new Node(a);
        Node * temphead=head;
    
  
    cin>>a;
    while(a!=-1){
        Node * temp = new Node(a);
        temphead->next=temp;
        temphead=temp;
        cin>>a;
        
    }
return head;
}
return NULL;
}

void printll(Node * head){
    Node * temphead=head;
    while(temphead->next!=NULL){
        cout<<temphead->data<<"->";
        temphead=temphead->next;
    }
    cout<<temphead->data;
    cout<<endl;
}





















Node * merge2sortedll(Node * head1, Node *head2){
Node * temp1=head1;
Node * temp2=head2;
Node * temp3=new Node(1);
Node *head3 =temp3;

while(temp1!=NULL && temp2!=NULL){
// printll(temp1);
// printll(temp2);
// printll(temp3);

    if(temp1->data<temp2->data){
    Node * temp=new Node(temp1->data);
    temp3->next=temp;

    temp3=temp;
    temp1=temp1->next;
    

    }
    else{
        Node * temp=new Node(temp2->data);

        temp3->next=temp;
        temp3=temp;
        temp2=temp2->next;
 }

}
// cout<<"while loop exited";
if(temp1==NULL){
    // cout<<"lmao";
    temp3->next=temp2;

}
else{
    // cout<<"nice";
    
    temp3->next=temp1;
}
return head3->next;

}


// int main(){
//     Node * head1=inputll();
//     Node * head2=inputll();
//     printll(head1);
//     printll(head2);

//     Node * head3=merge2sortedll(head1, head2);
//     // printll(head1);
//     // cout<<head3->data<<head3->next->data;
//     printll(head3);
//     return 0;
// }