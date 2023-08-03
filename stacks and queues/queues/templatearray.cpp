#include <iostream>
using namespace std;

template <typename T>
class queue{
T * data;
int nextindex;
int firstindex;
int size;
int capacity;
public:
queue(int a){
    capacity=a;
    data=new T[capacity];
    firstindex=-1;
    nextindex=0;
    size=0;
}
// enqueue
void enqueue(T a){
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
T dequeue(){
    if(size==0){
        cout<<"queue empty"<<endl;
        return -1;
    }
    T temp=data[firstindex];
    firstindex=(firstindex+1)%capacity;
    size--;
    return temp;

}

int getsize(){
    return size;
}
T top(){
 if(size==0){
        cout<<"queue empty"<<endl;
        return 0;
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
    queue<char> q1(4);
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