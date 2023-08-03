#include <iostream>
using namespace std;


class Stack{
int totalsize;
int * data;
int nextpointer=0;
public:
Stack(int size){
    this->totalsize=size;
    
    this->data=new int[totalsize];
}
void push(int a){
    if(nextpointer==totalsize){
        cout<<"Stack full"<<endl;
        return;
    }
    data[nextpointer]=a;
    nextpointer++;
}
int pop(){
    if(nextpointer==0){
        cout<<"stack empty"<<endl;
        return -1;
    }

    nextpointer--;
    return data[nextpointer];
}
int head(){
    if(nextpointer==0){
        cout<<"stack empty"<<endl;
        return -1;
    }
    return data[nextpointer-1];
}
int size(){
    return nextpointer;
}

};


int main(){
    Stack s1(3);
    s1.push(1);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<"here"<<endl;
    cout<<s1.pop()<<endl;
    s1.push(4);
    cout<<s1.head()<<endl;
    cout<<s1.size()<<endl;

    return 0;
}