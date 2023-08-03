#include <iostream>
using namespace std;
// int i=6;

int* helper(int n){
 
    if(n==0){
        // int * i=new int(2);
        int k=2;
    int * i =&k;
    k=6;
        cout<<i<<endl;
        
        return i;
    }
    int* ans=helper(n-1);
    return ans;
}

int main(){
    int* a=helper(5);
    cout<<*a;
    return 0;
}