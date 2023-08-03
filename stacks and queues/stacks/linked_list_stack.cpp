#include <iostream>
using namespace std;
// template <typename T>

class Node{
    public:
    int data;
    Node * next;
    public:
    Node(int x){
        this->data=x;
        next=NULL;
    }
};


class Stack{
int size=0;
Node * head;
public:
Stack(){
    Node * head=NULL;
    // head=temp;
    
}
// push
void push(int x){
    Node * temp=new Node(x);
    temp->next=head;
    head=temp;
    size++;
}

// pop 
int pop(){
    int k= head->data;
    head=head->next;
    size--;
    return k;
}
// top
int top(){
    return head->data;
}
// size
int sizes(){
    return size;

}


};




int main(){
    Stack s1;
    s1.push(1);
   
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout<<s1.sizes()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;

    return 0;
}