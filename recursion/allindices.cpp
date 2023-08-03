#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printv(vector<int> vec){
     cout<<"vector is"<<endl;
    for (int i=0;i<vec.size();i++){
       
        cout<<vec[i]<<endl;
     
    }
       cout<<"vector ends"<<endl;
}
int ka=0;
vector<int> allindices(vector <int> vec, int m){
    printv(vec);
    ka++;
if(vec.size()==0){
    vector <int> temp;
    temp.push_back(-10000);
    // cout<<"if condition"<<endl;
    return temp;

}
else{
    
    vector<int> k;
    // printv(k);
    k=vec;
    k.erase(k.begin());    
    // cout<<"else condition"<<endl;

    vector<int> t;
    t=allindices(k,m);
     for(int i=0;i<t.size();i++){
            t[i]==t[i]+1;
            // cout<<"for loop"<<endl;
        }
    
    if(vec[0]==m){
        t.push_back(ka-2);
        // cout<<"lol"<<endl;
        sort(t.begin(),t.end());
        printv(t);
    }
        return t;
    // }

    }
}






int main(){
  
    int arr[]={2,3,4,1,2,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector <int> vec (arr,arr+n);
    int m=1;
    vector<int> aa=allindices(vec,m);
    for(int i=0;i<aa.size();i++){
        cout<<aa[i]<<endl;
    }
    return 0;
}