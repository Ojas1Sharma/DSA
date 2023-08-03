#include <iostream>
#include "llclasses.cpp"
using namespace std;


void rec(Node * head){
    if(head==NULL){
        return;
    }
    Node * temp=head;
    temp->data=2;
    rec(head->next);

}


void func(){
    // int q=2;
    int * llll=new int(2);
    cout<<"kad"<<*llll;
}
int main(){
    // Node * head=takeinput();
    // printll(head);
    // rec(head);
    // printll(head);
    func();
    int * llll=new int(3);
    cout<<*llll;
    return 0;
}