#include <iostream>
using namespace std;
string * keys= new string[10];



void printkeypad(string input, string output){
if(input.length()==0){
    cout<<output<<endl;
}
else{
    char c=input[0];
    int kk=int(c)-48;
    if(keys[kk].length()==3){
for(int i =0;i<3;i++){

printkeypad(input.substr(1),output+keys[kk].substr(i,1));
}}
else if(keys[kk].length()==4){
    for(int i =0;i<4;i++){

printkeypad(input.substr(1),output+keys[kk].substr(i,1));
}
}


}
}





int main(){
    string s;
    cin>>s;

keys[0]=" ";
keys[1]=" ";
keys[2]="abc";
keys[3]="def";
keys[4]="ghi";
keys[5]="jkl";
keys[6]="mno";
keys[7]="pqrs";
keys[8]="tuv";
keys[9]="wxyz";

printkeypad(s,"");



    return 0;
}