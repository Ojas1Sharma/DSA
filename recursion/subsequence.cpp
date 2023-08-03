#include <iostream>
using namespace std;

int subseq(string s, string output[]){
    if(s.length()==0){
             cout<<"if"<<endl;
        output[0]="";
        return 1;
   
    }
    else{
        string p=s.substr(1);
        cout<<"else"<<endl;
        int smallsubseqlength=subseq(p, output);

        for(int i=0;i<smallsubseqlength;i++){
            output[smallsubseqlength+i]=s[0]+output[i];
        }
        return 2*smallsubseqlength;


    }
}



int main(){
    string s;
    cin>>s;
    string * output=new string[1000];
    // string output[1000]
    int n=subseq(s,output);
    for (int i =0;i<n;i++){
        cout<<output[i]<<endl;
    }
    
    return 0;
}