#include <iostream>
#include <string.h>
using namespace std;

int printi(int i, string s[]){
    int l;
int k;
if(i<2){
    s[0]="hi";

    k=1;
    return k;
}
else{
    s[0]="hello";
    // cout<<"s[0] is"<<s[0]<<endl;
    k=2;
    l=printi(i-1,s);
    return k;
}
}


int main(){
    int i=2;
    string *ptrtoarray= new string[1000];
    cout<<printi(i,ptrtoarray); 
    // cout<<ptrtoarray[0];
    return 0;
}