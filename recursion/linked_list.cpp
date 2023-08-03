#include <iostream>
using namespace std;


class Node{
public:
int data;
Node * next;
Node(int a){
this->data=a;
this->next=NULL;
}


};






// int main(){
//    Node n1(1);
//    Node * head=&n1;
//    cout<<head->data<<endl;
//    Node n2(10);
//    n1.next=&n2;

//    Node *n3= new Node(20);
//     Node *head= n3;
//     Node *n4 =new Node(30);
//     n3->next=n4;

//     return 0;
// }
// void printl(Node * head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;


//     }
// }
// int main(){
//    Node n1(1);
//    Node n2(2);  
//    Node n3(3);  
//    Node n4(4);  
//    Node n5(5);
//    Node * head= &n1;
//    n1.next=&n2;
//    n2.next=&n3;
//    n3.next=&n4;
//    n4.next=&n5;
//    printl(head);  
//     return 0;
// }




void printll(Node *head){
    Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}

}


Node * takeinput(){
    int a;
    cin>>a;
    
    if(a==-1){
        return NULL;
    }
    else{
    Node * head =new Node(a);
    Node * tail=head;
    cin>>a;
    while(a!=-1){
        
        
        Node * temp = new Node(a);
        tail->next=temp;
        tail=temp;
        cin>>a;

    }
    
    
    return head;
    
    
    
    
    }
}



Node* insertAtIndex(Node *head,int k, int i){
int l=0;
cout<<head->data<<endl;
Node * temp= head;
while(l!=i-1){
   temp=temp->next;
   l++;
}
cout<<temp->data<<endl;
Node * temp2= new Node(k);
Node * temp3= temp;
temp->next=temp2;
temp2->next=temp3->next;

return head;
}



Node * deleteNode(Node * head, int index ){
    int q=0;
    Node * temp=head;

    while(q!=index-1){
        temp=temp->next;
        q++;

    }
    // Node * temp2=temp->next;
    Node * tempdel=temp->next;
    temp->next=temp->next->next;
    delete[] tempdel;
    return head;
}


int main(){
Node * n1 = new Node(1);
Node * n2 = new Node(2);
Node * n3 = new Node(3);
Node * n4 = new Node(4);
Node * n5 = new Node(5);
Node * head1=n1;
n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=n5;
// printll(head1);
Node * head= takeinput();
printll(head);
// Node * head2=deleteNode(head,2);
Node * head2=insertAtIndex(head,20,3);

cout<<endl;
printll(head2);
}


























