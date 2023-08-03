#include <iostream>
using namespace std;

void removex(char arr[], char x){
    if(arr[0]=='\0'){
        return;
    }
    else{
        if(arr[0]!='x'){
            removex(arr+1, x);
        }
        else{
            int i=1;
            for(;arr[i]!='\0';i++){
                arr[i-1]=arr[i];
            }
            arr[i-1]=arr[i];
            removex(arr,x);
        }



    }
}




int lengthstr(char arr[]){
    if(arr[0]=='\0'){
        return 0;
    }
    else{
        return lengthstr(arr+1)+1;
    }
}



int main(){
    char arr[100];
    cin>>arr;
    // int l=lengthstr(arr);
    // cout<<l;
    removex(arr,'x');
    cout<<arr<<endl;
    return 0;
}