#include <iostream>
#include "middlelement.cpp"
using namespace std;



// reverse linked list recursively and iteratively

Node * reversellrec(Node * head){
    if(head->next==NULL){
        return head;
    }
    Node * smallans=reversellrec(head->next);
    Node * temp=smallans;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node * temphead=head;
    temphead->next=NULL;
    temp->next=head;
    return smallans;
}


// lets do the same thing iteratively
Node * reverseiter(Node * head){
    Node * prev=head;
    
    Node * curr=head->next;
    Node * nextt=head->next->next;
    prev->next=NULL;
    // Node * temp=nextt->next;
    while(nextt!=NULL){
        Node * temp=nextt->next;
        curr->next=prev;
        nextt->next=curr;
        cout<<"prev is: "<<prev->data<<"  curr is: "<<curr->data<<"  next is: "<<nextt->data<<endl;
        prev=curr;
        curr=nextt;
        nextt=temp;


    }
    return curr;

}



// int main(){
//     Node * head=inputll();
//     printll(head);
//     // Node * ans=reversellrec(head);
// cout<<"ans is"<<endl;
// Node * ans=reverseiter(head);
// printll(ans);
    
//     return 0;
// }