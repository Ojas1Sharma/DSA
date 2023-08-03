#include <iostream>
using namespace std;




int mult(int m, int n){
    if(n==1){
        return m;
    }
    else{
        int kk=mult(m,n-1);
        int ll=kk+m;
        return ll;
    }
}

int main(){
    int m=5,n=3;
    int l=mult(m,n);
    cout<<l;    
    return 0;
}