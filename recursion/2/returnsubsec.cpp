#include <iostream>
using namespace std;

int subsec(string input, string output[]){
    if(input.length()==0){
        output[0]="";
        return 1;

    }
    int small=subsec(input.substr(1),output);
    for(int i=0;i<small;i++){
        output[i+small]=input[0]+output[i];

    }
    return 2*small;
}




int main(){
    string s;
    cin>>s;
    string * output=new string[1000];
    int l=subsec(s,output);
    for(int i=0;i<l;i++){
        cout<<output[i]<<endl;

    }
    return 0;
}