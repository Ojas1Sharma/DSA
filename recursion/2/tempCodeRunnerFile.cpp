#include <iostream>

using namespace std;



void printsubsec(string input, string output){
    if(input.length()==0){
        cout<<"herer"<<endl;
        cout<<output<<endl;
    }
    cout<<"asdas"<<endl;
    printsubsec(input.substr(1),output);
    printsubsec(input.substr(1),output+input[0]);
}


int main(){
    string s;
    cin>>s;
    string output="";
    printsubsec(s,output);

    return 0;
}