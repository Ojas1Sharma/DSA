#include <iostream>
using namespace std;


class queue{
int * data;
int nextindex;
int firstindex;
int size;
int capacity;
public:
queue(int a){
    capacity=a;
    data=new int[capacity];
    firstindex=-1;
    nextindex=0;
    size=0;
}
// enqueue
void enqueue(int a){
    if(size<capacity){
    if(size==0){
        data[nextindex]=a;
        nextindex++;
        firstindex++;
        size++;
        return;
    }
    data[nextindex]=a;
    size++;
    nextindex=(nextindex+1)%capacity;
    }
    else{
        cout<<"capacity full"<<endl;
    }
}
int dequeue(){
    if(size==0){
        cout<<"queue empty"<<endl;
        return -1;
    }
    int temp=data[firstindex];
    firstindex=(firstindex+1)%capacity;
    size--;
    return temp;

}

int getsize(){
    return size;
}
int top(){
 if(size==0){
        cout<<"queue empty"<<endl;
        return -1;
    }
    else{
        return data[firstindex];
    }
}
bool isEmpty(){
    return size==0;
}

// dequeue
// size
// isempty
// top
// head


};




int main(){
    queue q1(4);
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