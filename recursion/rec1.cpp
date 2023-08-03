#include <iostream>
using namespace std;



int rec(int x, int n){
    if(n==0){
        return 1;
    }
    else{
        
        return(x*rec(x,n-1));
    }
}

int main(){
    int x,n;
    cin>>x;
    cin>>n;
    cout<<rec(x,n);
    return 0;
}