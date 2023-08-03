#include <iostream>
using namespace std;


void tower(int n, int start, int aux, int end){
    if(n==1){
        cout<<start<<"-> "<<end<<endl;
    }
    else{
        tower(n-1,start,end,aux);
        cout<<start<<"-> "<<end<<endl;
        tower(n-1,aux,start,end);
    }
}






int main(){
    int n=3;
    tower(n,0,1,2);   
    return 0;
}