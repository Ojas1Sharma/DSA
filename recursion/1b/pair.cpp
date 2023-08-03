#include <iostream>
using namespace std;


string pairp(string s){
    if(s.length()==2){
        if(s[0]==s[1]){
            string temp(3,'x');
            cout<<" temp is "<< temp<<endl;
            temp[0]=s[0];
            temp[1]='*';
            temp[2]=s[1];
            cout<<" new temp is  "<<temp<<endl;
            return temp;

        }
        else{
            cout<< " s is "<<s<<endl;
            return s;

        }
    }
    else{
        string pp=pairp(s.substr(1));
        cout<<"here"<<endl;
        if(pp[0]==s[0]){
            cout<<"h"<<endl;
            string e(pp.length()+2,'x');
            e[0]=pp[0];
            e[1]='*';
            for(int i=0;i<pp.length();i++){
                e[i+2]=pp[i];

            }
            cout<<"new e is "<<e<<endl;
            return e;
        }
        else{
            cout<<"Lol"<<endl;
            string q(s.length()+1,'x');
            q[0]=s[0];
            for(int i=0;i<pp.length();i++){
                q[i+1]=pp[i];

            }
            cout<< " new q is "<<q<<endl;
            return q;
        }
    }
}  



int main(){
    string s ="ojassharma";
    string k=pairp(s);
    cout<<k;
    return 0;
}