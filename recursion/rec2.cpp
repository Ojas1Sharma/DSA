#include <iostream>
using namespace std;


void printn(int a){
    if(a==0){
        cout<<"0"<<endl;
        
    }
    else{
        cout<<a<<endl;
        printn(a-1);
        
    }
}

int main(){
    int n;
    cin>>n;
    printn(n);
    return 0;
}