#include <iostream>
#include <vector>
#include "llclasses.cpp"

using namespace std;

int count(Node * head){
    int C=0;
    while(head!=NULL){
        head=head->next;
        C++;
    }
    cout<<"count is"<<C<<endl;
    return C;
}



  Node *  revrec(Node* head){
    
        if(head->next->next==NULL){
    
            head->next->next=head;
            Node * tt=head->next;
            head->next=NULL;
            return tt;
        }
        else{
            Node * temp=revrec(head->next);
            Node * temp2 =temp;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=head;
            head->next=NULL;
            return temp2;

        }
    }


int chkpal(Node * head){
    int cnt=count(head);
    int mid =cnt/2;
    cout<<"mid is "<<mid<<endl;
    // mid->cnt-1 indices should be reversed for even
    Node * temp2=head;
    Node * temp33=head;
    for(int i=0;i<mid;i++){
        temp33=temp2;
        temp2=temp2->next;
    }
    temp33->next=NULL;
    Node * temp=revrec(temp2);
    printll(temp);
    printll(head);
    int tt=1;
    while(head!=NULL && temp!=NULL){
        // cout<<"KMA"<<endl;
        if (head->data!=temp->data)
        {
            tt=0;
            cout<<"afjkjes"<<head->data<<"   "<<temp->data<<endl;
            break;
        }
    head=head->next;
    temp=temp->next;    
    }
    if(tt==0){
        return 0;
    }
    else{
        return 1;
    }



}



int main(){
    Node * head=takeinput();
    printll(head);
    cout<<"lol"<<endl;
    int k=chkpal(head);  
    cout<<endl<<endl<<k;
    // Node * n2=revrec(head);
    // printll(n2);
    return 0;
}