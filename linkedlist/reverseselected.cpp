#include <iostream>
#include "reversell.cpp"
using namespace std;



Node * reverseselected(Node * head, int start, int end){
    Node * temp= head;
    Node * temp2= head;
    // int c=0;
    for(int i=0;i<start-2;i++){
        temp=temp->next;
    }
    for(int i=0;i<end-1;i++){
        temp2=temp2->next;
    }
    Node * restpart=temp2->next;
    temp2->next=NULL;

    Node * reversedpart=reversellrec(temp->next);
    temp->next=reversedpart;
    Node * temp4=reversedpart;
    while(temp4->next!=NULL){
        temp4=temp4->next;
    }
    temp4->next=restpart;
    return head;
}




int main(){
    Node * head=inputll();
    printll(head);

    Node * ans=reverseselected(head,4,8);
    printll(ans);
    return 0;
}