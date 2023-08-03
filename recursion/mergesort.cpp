#include <iostream>
using namespace std;

void printarr(int arr[], int n){
    cout<<"printing array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}


void merge(int arr[], int l, int mid, int r){
    cout<<"function entered with values l, mid and r as"<<l<<mid<<r;
    int arr1[mid-l+1];    

    // 4
    int arr2[r-mid];
    // 4
    for(int i=0;i<mid+1;i++){
        arr1[i]=arr[i];
    }
    int ll=0;
    for(int i=mid+1;i<r+2;i++){
    arr2[ll]=arr[i];
    ll++;
    }
    printarr(arr,r+1);
    printarr(arr1,mid-l+1);
    printarr(arr2,r-mid);
    int i=0;
    int j=0;
    int k=0;
    while(i!=mid-l+1||j!=r-mid){
        cout<<"here";
        if(arr1[i]<arr2[j]){
            cout<<"1st"<<endl;
            arr[k]=arr1[i];
            k++;
            i++;
        }
        else if(arr1[i]>arr2[j]){
            cout<<"second"<<endl;
            arr[k]=arr2[j];
            k++;
            j++;

        }
    }
    printarr(arr,l-r);
    if(i==mid-l+1){
        while(j!=r-mid){
            arr[k]=arr[j];
            k++;
            j++;
        }
    }
    if(j=r-mid){
        while(i!=mid-l+1){
            arr[k]=arr[i];
            i++;
            k++;
        }
    }
    printarr(arr,r-l+1);

}




void mergesort(int arr[], int start, int end){
    if(start>=end){
        return;
        cout<<"if statement"<<endl;
    }
    else{
        cout<<"else statement"<<endl;

        
        int mid=(start+end)/2;
        cout<<"mid is"<<mid;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);

    }




}


int main(){
    int arr[]={1,3,2,4,8,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}