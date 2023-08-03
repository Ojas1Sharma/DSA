#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string s="abcdefgh";
    cout<<s<<endl;
    s.erase (s.begin());
    s.erase (s.end()-1);

    cout<<s;
    
    return 0;
}