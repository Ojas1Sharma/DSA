#include <iostream>
#include "llclasses.cpp"
using namespace std;


void printrevll(Node * head){
    if(head->next==NULL){
        cout<<head->data<<" ";
    }
    else{
        printrevll(head->next);
        cout<<head->data<<" ";
    }
}



int main(){
    Node * head=takeinput();
    printll(head);
    printrevll(head);
    return 0;
}