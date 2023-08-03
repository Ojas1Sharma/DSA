#include <iostream>
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


int midpoint(Node * head){
    Node * temphead= head;
    Node * tempheadfirst= head;
    Node * tempheadsecond= head;
    
    while(tempheadsecond->next!=NULL){


        if(tempheadsecond->next->next==NULL){
            return tempheadfirst->data;
        }
        tempheadfirst=tempheadfirst->next;
        tempheadsecond=tempheadsecond->next->next;
        // cout<<tempheadfirst->data<<tempheadsecond->data<<endl;
    }
    return tempheadfirst->data;
    
}




// int main(){
//     // Node * head= new Node(10);
//     // cout<<head->data;
//     Node * head=inputll();
//     printll(head);
//     cout<<midpoint(head);
//     return 0;
// }