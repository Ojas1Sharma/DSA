#include <iostream>
using namespace std;
// generally memoization which is top down deals with recursion
// and dp which is bottom up deals with bottom up

// min steps to 1
// n=7 ---> 1
// 1. decrement the number to 1 n-1
// 2. divide by 2 if n is divisible by 2
// 3. divide by 3 if n is divisible by 3



// int min_steps(int n){
//     if(n==1){
//         // cout<<"hi"<<endl;
//     return 0;
//     }
   
   
//     int a=100000;
//     int b=100000;

//     if(n%3==0){
//     cout<<"hit"<<endl;
//     a= min_steps(n/3)+1;}
//     if(n%2==0)
//     b= min_steps(n/2)+1;
//     int c= min_steps(n-1)+1;
//     cout<<"returning min from abc as "<<std::min(a,std::min(b,c))<<endl;
//     cout<<"int a is "<<a<<" for n= "<<n<<endl;
//     cout<<"int b is "<<b<<" for n= "<<n<<endl;
//     cout<<"int c is "<<c<<" for n= "<<n<<endl;
//     return std::min(a,std::min(b,c));

// }




int steps_helper(int n, int arr[]){
    // base
    if(n<=1){
    return 0;}
    // check if already present
    if(arr[n]!=-1){
        return arr[n];
    }
    // else calculate
    int a=10000000;
    if(n%3==0){
    a=steps_helper(n/3,arr);}
    int b=10000000;
    if(n%2==0){
    b=steps_helper(n/2,arr);}
    int c=steps_helper(n-1,arr);
    // append
    arr[n]=std::min(a,std::min(b,c))+1;
    
    // return
    return arr[n];


}


int min_steps(int n){
    int arr[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    int k = steps_helper(n,arr);
    return k;
}



int main(){
    int n=7;
    // cin>>n;
    cout<<min_steps(n)<<endl;
    return 0;
}