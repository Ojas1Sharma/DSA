#include <iostream>
using namespace std;


template <typename T>
class Node{
    public:
    T data;
    Node<T> * next;
    public:
    Node(T x){
        this->data=x;
        next=NULL;
    }
};

template <typename T>
class Stack{
int size=0;
Node<T> * head;
public:
Stack(){
    Node<T> * head=NULL;
    // head=temp;
    
}
// push
void push(T x){
    Node<T> * temp=new Node<T>(x);
    temp->next=head;
    head=temp;
    size++;
}

// pop 
T pop(){
    T k= head->data;
    head=head->next;
    size--;
    return k;
}
// top
T top(){
    return head->data;
}
// size
int sizes(){
    return size;

}


};




int main(){
    Stack<char> s1;
    s1.push(1);
   
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout<<s1.sizes()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;

    return 0;
}