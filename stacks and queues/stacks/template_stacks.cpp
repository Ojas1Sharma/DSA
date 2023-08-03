#include <iostream>
#include <climits>
using namespace std;
template <typename T>


class Stack{
int nextpointer=0;
T * data;
int totalsize;
public:
Stack(){
    int a=4;
    data = new T[a];
    totalsize=a;
}
void push(int a){
    if(nextpointer==totalsize){
        // cout<<"Stack full"<<endl;
        // return;
        int newsize=totalsize*2;
        T *temp=new T[newsize];
        for(int i=0;i<nextpointer;i++){
            temp[i]=data[i];
        }
        data=temp;

    }
    data[nextpointer]=a;
    nextpointer++;
}
T pop(){
    if(nextpointer==0){
        cout<<"stack empty"<<endl;
        return -1;
    }

    nextpointer--;
    return data[nextpointer];
}
T head(){
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
    Stack<char> s1;
    s1.push(1);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(3);
    s1.push(3);
    s1.push(3);
    s1.push(1);
    s1.push(5);
    cout<<"here"<<endl;
    cout<<s1.pop()<<endl;
    s1.push(4);
    cout<<s1.head()<<endl;
    cout<<s1.size()<<endl;

    return 0;
}