#include <iostream>
#include "merge2ll.cpp"
using namespace std;


Node* middle(Node * head){
    Node * slow=head;
    Node * fast=head->next;
cout<<slow->data<<fast->data<<endl;
    while(fast->next!=NULL&&fast!=NULL){
        
   
        slow=slow->next;
    
        fast=fast->next->next;


        if(fast==NULL){
            break;
        }
        
    }
return slow;
}


// int main(){
//     Node * head=inputll();
//     printll(head);
//     Node * midelem=middle(head);
    

//     cout<<endl<<midelem->data;
//     return 0;
// }