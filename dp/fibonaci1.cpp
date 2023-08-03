#include <iostream>
using namespace std;

// int fibo(int n){
//     if(n<=1){
//         return n;
//     }
//     int a=fibo(n-1);
//     int b=fibo(n-2);
//     return a+b;
    
//     }

// int main(){
//     int n;
//     cin>>n;
//     cout<<fibo(n)<<endl;

//     return 0;
// }





int fibo(int n , int arr[]){
    if(n<=1){
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int o=fibo(n-1,arr);
    int p=fibo(n-2,arr);
    arr[n]=o+p;
    return arr[n];


}


int fibo_helper(int n){
    int arr[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    int k=fibo(n,arr);
    return k;

}


int main(){
int n;
cin>>n;
cout<<fibo_helper(n)<<endl;

return 0;
}

