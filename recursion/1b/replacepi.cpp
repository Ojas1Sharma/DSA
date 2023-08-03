#include <iostream>
using namespace std;


string replacepi(string s){
    if(s.length()==2){
        if(s[0]=='p'&&s[1]=='i'){
            cout<<"this happened"<<endl;
        string qq="3.14";
        return qq;
        }
        else{
            return s;
        }
    }
    else{
        string t=replacepi(s.substr(1));
        if(s[0]=='p'&&t[0]=='i'){
            string pp="3.14";
            for(int i=1;i<t.length();i++){
                pp=pp+t[i];
            }
            return pp;

        }
        else{
            string ll=s[0]+t;
            cout<<"ll is    "<<ll<<endl;
            return ll;
        }


    }
}



int main(){
    string s="qwenjpikdjpi";

    string q=replacepi(s);
    cout<<q;

    return 0;
}