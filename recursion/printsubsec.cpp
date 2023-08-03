#include <iostream>
using namespace std;

void printsubsec(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
    }
    else{

        printsubsec(input.substr(1),output);
        printsubsec(input.substr(1),output+input[0]);

    }
}



int main(){
    string input;
    string output;
    cin>>input;
    output="";
    printsubsec(input,output);
    return 0;
}