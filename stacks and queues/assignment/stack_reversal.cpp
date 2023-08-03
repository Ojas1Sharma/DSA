#include <iostream>
#include <stack>
using namespace std;



stack<int> reverse_stack(stack<int> s1){
    if(s1.size()==1){
        return s1;

    }
    
    int a=s1.top();
    s1.pop();
    stack<int> s2=reverse_stack(s1);
    while(s1.size()!=0){
        s1.pop();
    }
    while(s2.size()!=0){
        int temp=s2.top();
        s2.pop();
        s1.push(temp);
    }
    while(s2.size()!=0){
        s2.pop();
    }
    s2.push(a);
    while(s1.size()!=0){
        int temp =s1.top();
        s1.pop();
        s2.push(temp);
    }

    return s2;

}




int main(){
    stack<int> s1;
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        s1.push(temp);
    }    
    stack<int> s2=reverse_stack(s1);
    cout<<s2.top();
    s2.pop();
    cout<<s2.top();
    s2.pop();
    cout<<s2.top();
    s2.pop();
    cout<<s2.top();
    s2.pop();

    return 0;
}