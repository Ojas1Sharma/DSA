#include <iostream>
using namespace std;

int last(int arr[], int n, int m){
    if(n==0){
        return -1;
    }
    else{
        int ans=last(arr+1,n-1,m);
        if(ans==-1){
            if(arr[0]==m){
                return 0;
            }
            else{
                return -1;
            }
        }
        else{
            return ans+1;
        }


    }
}



int main(){
    int arr[]={10,1,2,3,2,4,5,2,2,6,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=10;
    cout<<last(arr,n,m);

    return 0;
}