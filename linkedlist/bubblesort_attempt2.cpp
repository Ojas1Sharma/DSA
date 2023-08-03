#include <iostream>
#include "middlelement.cpp"


using namespace std;

Node * bubblesort(Node * head){
Node * prev=head;
Node * curr=head;
Node * nextt=head->next;

int c=0;
while(c!=1){
    c=1;
while(nextt!=NULL){
    cout<<"prev is "<<prev->data<<"current is "<<curr->data<<"next is  "<<nextt->data<<endl;

if(curr->data>nextt->data){
    if(nextt->next==NULL){
curr->next=NULL;
prev->next=nextt;
nextt->next=curr;
prev=nextt;
nextt=NULL;

    }
    else{


    cout <<"current is greater than nextt"<<endl;
    prev->next=nextt;
    Node * temp=nextt->next;
    nextt->next=curr;
    curr->next=temp;
    prev=nextt;
    nextt=temp;
    c=0;
    cout <<"updated values are "<<prev->data<<" "<<curr->data<<" "<<nextt->data<<endl<<endl; 
    }
}
else{
    cout<<"entering else condition "<<endl;
    prev=curr;
    curr=nextt;
    nextt=nextt->next;
cout <<"updated values are "<<prev->data<<" "<<curr->data<<" "<<nextt->data<<endl<<endl; 
}


}
printll(head);
}


}



int main(){
    Node * head=inputll();
    printll(head);    
    Node * ans=bubblesort(head);
    printll(ans);
    return 0;
}