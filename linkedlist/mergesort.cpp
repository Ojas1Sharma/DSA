#include <iostream>
#include "merge2ll.cpp"
using namespace std;




int lllenngth(Node * head){
    cout<<"here"<<endl;
    printll(head);

Node *temp =head;
int c=0;
while(temp->next!=NULL){
c++;
temp=temp->next;

}
cout<<"length of the above ll is "<<c+1;

return c+1;
}

Node * partition(Node * head, int start, int end){
if(start==end){
    return head;

}
int mid=(start+end)/2;
Node * temp=head;
for(int i =0; i<mid;i++){
    temp=temp->next;
}

Node * firstpart=head;
Node * lastpart=temp;
Node * templist1=partition(firstpart,start,mid);
Node * templist2=partition(lastpart,mid+1,end);
Node * finallist=merge2sortedll(templist1,templist2);
printll(finallist);
return finallist;
}

void mergesort(Node * head){
int k= lllenngth(head);
Node * final=partition(head,0, k);
head=final;

}








int main(){
    Node * head=inputll();
    // Node * head=new Node(1);
    // Node * temp1=new Node(3);
    // head->next=temp1;
    // Node * temp2=new Node(5);
    // temp1->next=temp2;
    // Node * temp3=new Node(2);
    // temp2->next=temp3;
    // Node * temp4=new Node(4);
    // temp3->next=temp4;
    // Node * temp5=new Node(6);
    // temp4->next=temp5;

    printll(head);
    cout<<"hey"<<endl;
    mergesort(head);
    printll(head);
    return 0;
}