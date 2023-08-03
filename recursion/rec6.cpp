// #include <iostream>
// using namespace std;
// int i=0;
// int fstindex(int arr[], int n, int m){
//     i++;
//     if(n==0){
//         return -1;
//     }
//     else{
//         if(arr[0]==m){
//             return i; 
//         }
//         else{
//             return(fstindex(arr+1,n-1,m));
//         }
//     }
// }


// int main(){
//            int arr[]={1,2,3,4,2,2,2,2,5,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int find=2;
//     cout<<fstindex(arr,n,find)-1;
//     return 0;
// }




#include <iostream>
using namespace std;
int fstindex(int arr[], int n, int m){
    
    if(n==0){
        return -1;
    }
    else{
        if(arr[0]==m){
            return  0;
        }
        else{
            int l=fstindex(arr+1,n-1,m);
            if(l==-1){
                return -1;
            }
            else{
                return (l+1);
            }

        }
    }
}


int main(){
           int arr[]={1,2,3,4,2,2,2,2,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int find=6;
    cout<<fstindex(arr,n,find);
    return 0;
}