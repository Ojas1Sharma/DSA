#include <iostream>
#include <string>
#include <stack>
using namespace std;


int fuck(stack<char> s, string s1){
    for(int i=0;i<s1.length();i++){
        cout<<"s1 length is "<<s1.length()<<endl;
        cout<<"normal loop iteration "<<endl;
        if(s1[i]=='['||s1[i]=='{'||s1[i]=='('){
            cout<<"pushing "<<s1[i]<<" into the stack"<<endl;
            s.push(s1[i]);
        }
        if(s1[i]==']'||s1[i]=='}'||s1[i]==')'){
            char c= s.top();
            cout<<"got "<<s1[i]<<" from the input"<<endl;
            if(s1[i]==')'){
                if(c=='('){
                    cout<<"balanced"<<endl;
                    s.pop();
                }
                else{
                    return -1;
                }
            }
            else if(s1[i]==']'){
                if(c=='['){
                    cout<<"balanced"<<endl;
                    s.pop();
                }
                else{
                    return -1;
                }
            }
            else if(s1[i]=='}'){
                if(c=='{'){
                    cout<<"balanced"<<endl;
                    s.pop();
                }
                else{
                    return -1;
                }
            }
            
        }
        cout<<"here"<<endl;
    }
   


 return 0;
}





int main(){
    stack<char> s;    
    string s1;
    cin>>s1;
    // cout<<s1.length();
    int k=fuck(s,s1);
    cout<<k<<endl;
    return 0;
}