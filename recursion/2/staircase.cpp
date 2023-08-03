#include <iostream>
using namespace std;

int countsteps(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    int q=countsteps(n-1);
    int r=countsteps(n-2);
    int e=countsteps(n-3);
    return(q+r+e);

}



int main(){
    int n;
    cin>>n;
    int k=countsteps(n);
    cout<<k;
    return 0;
}