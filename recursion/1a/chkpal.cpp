#include <iostream>
#include <string>
using namespace std;



int chkpal(string s){
    if(s.length()==1||s.length()==2){
        if(s.length()==1){
            return 1;

        }
        else{
            if(s[0]==s[1]){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    else{
        string temp=s;
        s.erase(s.begin());
        s.erase(s.end()-1);
        int op=chkpal(s);
        if(op==0){
            return 0;
        }
        if(op==1){

            if(temp[0]==temp[temp.length()-1]){
                return 1;
            }
            else{
                return 0;
            }

        }

    }




}






int main(){
    string s;
    cin>>s;
    int k=chkpal(s);
    cout<<k;
    return 0;
}