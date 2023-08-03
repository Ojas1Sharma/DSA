#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int stringtoint(string s){
    if(s.length()==1){
        cout<<s[0]<<"  is   "<<int(s[0])-96<<endl;
        return int(s[0])-96;
    }
    else{
        int k=stringtoint(s.substr(1));
        cout<<"  k is  "<<k;
        // int j=(int(s[0])-96)*(pow(10,(s.length()-1)))+k;
         int j=(int(s[0])-96);
         int temp=(pow(10,(s.length()-1)));
         int temp2=j*temp+k;
         cout<<endl<<"  j is "<<j<<endl;
         cout<<"s.len is "<<s.length()<<endl;
         cout<<endl<<"  temp is "<<temp<<endl;
         cout<<endl<<"  temp2 is "<<temp2<<endl;
        return temp2;
    }
}


int main(){
    string s="abcd";
    int k=stringtoint(s);
    cout<<endl<<k;
    return 0;
}