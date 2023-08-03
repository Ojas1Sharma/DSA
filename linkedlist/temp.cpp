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

int main(){
//    Node n1(1);
//    Node * head=&n1;
//    cout<<head->data<<endl;
//    Node n2(10);
//    n1.next=&n2;

//    Node * n3= new Node(20);
//     Node * head= n3;
//     Node * n4 =new Node(30);
//     n3->next=n4;
//     cout<<n3->data<<endl<<n4->data;
int i=5;
while(i>0){
    int a=3;
    Node * temp=new Node(a+i);
    cout<<temp->data;
    i--;
}

    return 0;
}