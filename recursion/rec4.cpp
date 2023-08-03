#include <iostream>
using namespace std;

int sumarr(int arr[], int n){
    if(n==0){
        return 0;
    }
    else{
        int k=sumarr(arr+1,n-1);
        return(arr[0]+k);

    }
}



int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sumarr(arr,n);
    return 0;
}