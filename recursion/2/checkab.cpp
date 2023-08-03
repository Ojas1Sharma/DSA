#include <iostream>
using namespace std;
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'




int checkab(string s){
    if(s.length()==0){
        return 0;
    }
    else{
        int k=checkab(s.substr(1));
        if(k==-1){
            return -1;
        }
        else{
            if(s[0]=='a'){
                if(s[1]=='a'||s.length()==1||(s[1]=='b'&&s[2]=='b')){
                    return 0;
                }
                else{
                    return -1;
                }
            }
            if(s[0]=='b'&&s[1]=='b'){
            if(s[2]=='a'||s.length()==2){
                return 0;
            }
            else{
                return -1;
            }
            }
            return 0;
        }


    }



}



int main(){
    string s;
    cin>>s;
    if(s[0]=='b'){
        cout<<-1;
        return 0;
    }
    int k=checkab(s);
    cout<<k;
    return 0;
}