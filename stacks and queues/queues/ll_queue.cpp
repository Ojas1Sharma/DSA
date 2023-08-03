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
class Queue{
int * data;
Node * firstnode=NULL;
Node * lastnode=NULL;
int size=0;
public:

// enqueue
void enqueue(int a){
    if(size==0){
        firstnode=new Node(a);
        lastnode=firstnode;
        size++;
        return;
        }
    Node * temp=new Node(a);
    lastnode->next=temp;
    lastnode=temp;
    size++;

}
// dequeue
int dequeue(){
    if(size==0){
        cout<<"queue empty"<<endl;
        return -1;
    }
    int temp1=firstnode->data;
    Node * temp2=firstnode->next;
    delete firstnode;
    firstnode=temp2;
    size--;
    return temp1;


}

// top
int top(){
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
    Queue q1;
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


    
    return 0;
}