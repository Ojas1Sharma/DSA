#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node * next;

    Node(T a){
        this->data=a;
        this->next=NULL;
    }

};
template <typename T>
class Queue{

Node<T> * firstnode=NULL;
Node<T> * lastnode=NULL;
int size=0;
public:

// enqueue
void enqueue(T a){
    if(size==0){
        firstnode=new Node<T>(a);
        lastnode=firstnode;
        size++;
        return;
        }
    Node<T> * temp=new Node<T>(a);
    lastnode->next=temp;
    lastnode=temp;
    size++;

}
// dequeue
T dequeue(){
    if(size==0){
        cout<<"queue empty"<<endl;
        return 0;
    }
    T temp1=firstnode->data;
    Node<T> * temp2=firstnode->next;
    delete firstnode;
    firstnode=temp2;
    size--;
    return temp1;


}

// top
T top(){
    return firstnode->data;
}

// isempty
bool isempty(){
    return size==0;
}
// size 
int getsize(){
    return size;
}



};



int main(){
    Queue<char> q1;
    cout<<q1.getsize()<<endl;
    q1.enqueue(1);    
    q1.enqueue(2) ;   
    q1.enqueue(3)  ;  
    q1.enqueue(4)   ; 
    q1.enqueue(5)    ;
    cout<<q1.top()<<endl;
    // 0-->4
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    // 4-->3-->4-->3
        q1.enqueue(5)   ; 
    q1.enqueue(6);
    cout<<q1.getsize()<<endl;  
    cout<<q1.top()<<endl;
    return 0;


}