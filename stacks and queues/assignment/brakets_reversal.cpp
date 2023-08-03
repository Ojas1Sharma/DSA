#include <iostream>
#include <string>
#include <stack>


using namespace std;



int count(string s,stack<char> s1){
int index=0;
if(s.length()%2!=0){
    return -1;
}
int count=0;
while (index!=s.length())
{
    if(s[index]=='{'){
        if(s1.size()==0){
            s1.push(s[index]);
            index++;
        }
        else{
            s1.push(s[index]);
            index++;
        }
    }
    else if(s[index]='}'){
        //  cout<<"here i am with size: "<<s1.size()<<endl;
        if(s1.size()==0){
            count++;
            s1.push('{');
            cout<<"here i am with count "<<count<<endl;
            index++;
        }
        else{
            if(s1.top()=='{'){
                s1.pop();
                index++;
                cout<<"kind of balanced"<<endl<<"index going to "<<index<<endl;
            }
        }

    }
}

if(s1.size()==0){
    return count;
}

while(s1.size()!=0){
    char a=s1.top();

    s1.pop();
    char b=s1.top();
    s1.pop();
    if(a==b){
        count++;
    }
    }

return count;


}



int main(){
    stack<char> s1;
    string s;
    cin>>s;
    int c= count(s,s1);
    cout<<c<<endl;
    
    return 0;
}