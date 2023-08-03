#include <iostream>
#include<vector>
using namespace std;


int bins(vector<int> arr,int l,int r, int k){
    int mid=(l+r)/2;
if(arr[mid]==k){
    return mid;
}
else if(arr[mid]<k){
int m=bins(arr,mid,r,k);
return m;
}
else{
    int n=bins(arr,l,mid,k);
    return n;
}


}



int main(){
    // int arr[]={1,2,3,4,5,6,7,8,9};
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int k=bins(arr,0,arr.size(),4);
    cout<<k;
    return 0;

}