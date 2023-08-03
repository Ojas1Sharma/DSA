#include <iostream>
#include "middlelement.cpp"
using namespace std;


Node * merging(Node * firsthalf, Node * secondhalf){

}

Node * mergesort(Node * head){
// Node * temp=head;
// Node * mid =middle(temp);
// Node * secondhalf=mid->next;
// mid->next=NULL;
// printll(temp);
// cout<<endl;
// printll(secondhalf);
// Node * ans=merging(temp,secondhalf);
if(head==NULL){
    return NULL;
}
if(head->next==NULL){
    return head;
}
Node * mid=middle(head);
Node * firsthalf=head;
Node * secondhalf=mid->next;
mid->next=NULL;
Node * firstsort=mergesort(firsthalf);
Node * secondsort=mergesort(secondhalf);
Node * ans =merge2sortedll(firstsort,secondsort);
return ans;

}






int main(){
    Node * head= inputll();
    printll(head);
    Node * answer=mergesort(head);    
    printll(answer);
    // printll(ans);
    return 0;
}