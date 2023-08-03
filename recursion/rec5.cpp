#include <iostream>
using namespace std;


bool chknum(int arr[],int n,int m){
    if(n==0){
        return 0;
    }
    else{
        if(arr[0]==m){
            return 1;
        
        }
        else{
            return chknum(arr+1,n-1,m);
        }

    }

}


int main(){
        int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=7;
    cout<<chknum(arr,n,m);

    return 0;
}