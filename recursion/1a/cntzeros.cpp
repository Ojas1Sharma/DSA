#include <iostream>
using namespace std;

int cntzeros(int m){
    if(m/10==0){
    
        if(m==0){
            return 1;
        }
        else{
            return 1;
        }
    }
    else{
        int k=cntzeros(m/10);
        if(m%10==0){
            return k+1;
        }
        else{
            return k;
        }
    }

    
    
    }

int main(){
    int m=100101010;
    int k=cntzeros(m);
    cout<<k-1;
     return 0;
}