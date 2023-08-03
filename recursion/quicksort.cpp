#include <iostream>
using namespace std;

void printarr(int arr[], int n){
    cout<<"printing array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int partition(int arr[], int startindex, int endindex){
int pivot=arr[startindex];
int pivotindex=startindex;
for(int i=startindex+1;i<=endindex;i++){
    if(arr[i]<=pivot){
        pivotindex++;
    }
}
// int temp=arr[pivotindex];
// arr[pivotindex]=arr[startindex];
// arr[startindex]=temp;
swap(arr[pivotindex], arr[startindex]);
cout<<"pivot, startindex and endinedex and pivotindex is"<<pivot<<startindex<<endindex<<pivotindex;

int i=startindex;
int j=endindex;
while(i<pivotindex&&j>pivotindex){
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<pivotindex&&j>pivotindex){
     swap(arr[i++],arr[j--]);
    }
}
return pivotindex;

}


void qs(int arr[], int startindex, int endindex){
    if(startindex>=endindex){
        return;
    }
    // printarr(arr,endindex-startindex+1);
    int pivotindex=partition(arr,startindex,endindex);
    // cout<<pivotindex;
    qs(arr,startindex,pivotindex-1);
    qs(arr,pivotindex+1,endindex);
}




int main(){
    int arr[]={4,2,6,9,3,1,10,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    qs(arr,0,n-1);
    // printarr(arr,n);
    
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

    return 0;
}