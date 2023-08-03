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
queue(){
    int a=4;
    cout<<"default capacity is 4"<<endl;
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
    int temp=(nextindex+1)%capacity;
    if(temp!=firstindex){
        nextindex=temp;
    }
    }
    else{
        cout<<"capacity full reinitialising new array"<<endl;
        int newcapacity=2*capacity;
        cout<<"new capacity is"<<newcapacity<<endl;
        T * temp= new T[newcapacity]; 
        cout<<"temp initialised"<<endl;
        int i=0;
        int q=firstindex;
        while(firstindex!=nextindex){
            cout<<"inside while working on index"<<i<<endl;
            T a=data[firstindex];
            cout<<"copying "<<a<<"to index "<<i<<endl; 
            temp[i]=a;
            i++;
            firstindex=(firstindex+1)%capacity;

        }
        cout<<"putting last data of "<<data[nextindex]<<" into index "<<i<<endl;
        temp[i]=data[nextindex];
        temp[i+1]=a;
        cout<<"lalal "<<data[0]<<" adasfa "<<temp[0]<<endl;
        // delete[] data;
            cout<<"lalal "<<data[0]<<" adasfa "<<temp[0]<<endl;
        cout<<"competed and firstindex initialised to 0 and nextindex to "<<i+2<<endl;
        data=temp;
            cout<<"lalal "<<data[0]<<data[1]<<data[2]<<data[3]<<data[4]<<" " <<data[5]<<endl;
        size=capacity+1;
        capacity=newcapacity;
        firstindex=0;
        nextindex=i+2;
        cout<<"first index is "<<firstindex<<endl;
        cout<<"next index is "<<nextindex<<endl;
        // delete temp;
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
    queue<char> q1;
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