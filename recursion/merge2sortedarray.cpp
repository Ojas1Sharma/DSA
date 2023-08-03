// l->mid, mid+1->r

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



int main(){
    int arr[]={1,2,5,7,3,4,6};
    int mid=3;
    int l=0;
    int r=6;
    merge(arr,l,mid,r);
    // for(int o=0;o<8;o++){
    //     cout<<arr[o];
    // }
    return 0;
}