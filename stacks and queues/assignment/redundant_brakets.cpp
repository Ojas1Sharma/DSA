#include <iostream>
#include <stack>
#include <string.h>
using namespace std;



int check_redundant(string s){
stack<char> s1;
int nextindex=0;
while(nextindex!=s.length()){
char i=s[nextindex];

while(i!=')'){
s1.push(i);
nextindex++;
i=s[nextindex];
}
cout<<"here size is "<<s1.size()<<endl;

if(i==')'){
    cout<<"hi"<<endl;
    int count=0;
    while(s1.top()!='('){
        s1.pop();
        count++;
        
    }
    cout<<count<<endl;
    if(count==0){

        return -1;
    }
        cout<<"top element is "<<s1.top()<<endl;
    s1.pop();
    nextindex++;
    // cout<<"top element is "<<s1.top()<<endl;
    cout<<"size is "<<s1.size()<<endl;
}
cout<<"nextindex is "<<nextindex<<endl;
}
return 0;


}





int main(){
    string s;
    cin>>s;
    cout<<check_redundant(s);
    return 0;
}