#include <iostream>
#include <stack>

using namespace std;

int sendtorec(stack<int> s1){
    if(s1.size()==1){
        return 1;
    }
    int temp=s1.top();
    cout<<temp<<endl;
    s1.pop();
    int count=1;
    cout<<"initial count "<<count<<endl;
    while(s1.size()!=0){
        if(s1.top()<temp){
            count++;
            s1.pop();
        }
        else{
            break;
        }
    }
    return count;


  


}


void printsomething(stack<int> s1){
int size=s1.size();
cout<<"size of s1 is "<<s1.size()<<endl;
stack<int> s2;
while(s1.size()!=0){
    cout<<"caclculating"<<endl;
    int temp=sendtorec(s1);
    cout<<"received this "<<temp<<endl;
    s2.push(temp);
    s1.pop();
    
}
cout<<"size of s2 is "<<s2.size()<<endl;
while(s2.size()!=0){
    cout<<s2.top()<<" ";
    s2.pop();
}
// sendtorec(s1);

}


int main(){
    int n;
    cin>>n;
    stack<int> s1;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        
        s1.push(temp);

    }
    cout<<"here we are"<<endl;
    printsomething(s1);

    return 0;
}