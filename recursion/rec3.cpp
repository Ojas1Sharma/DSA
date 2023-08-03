#include <iostream>
using namespace std;


int coutn(int n){
    if(n/10==0){
        return 1;
    }
    else{
        int k = coutn(n/10);
        return(k+1);
    }
}


int main(){
    int n;
    cin>>n;
    cout<<coutn(n);
    return 0;
}