#include <iostream>
#include "middlelement.cpp"
using namespace std;

Node * bubblesort(Node * head){
    Node * temp1 =head;
    Node * temp2=head->next;
    int c=0;
    Node * prev=head;
    while(c!=1){
           c=1;
    while(temp2!=NULL){
     
        if(temp1->data>temp2->data){
            temp1->next=temp2->next;
            temp2->next=temp1;
            prev->next=temp2;
            prev=temp2;
            temp2=temp1->next;
        c=0;
            
        }
        else{
            prev=temp1;
            temp1=temp2;
            temp2=temp2->next;
        }
    }
 
    }
    return head;
}





int main(){
    Node * head= inputll();
    printll(head);
    Node * ans=bubblesort(head);    
    printll(ans);
    return 0;
}