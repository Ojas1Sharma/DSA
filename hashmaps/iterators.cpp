#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// code for removing duplicates using hashmaps
// vector<int> remove_duplicates(vector<int> vec){
//     vector<int> ans;
//     unordered_map<int,bool> mymap;
//     for(int i=0;i<vec.size();i++){
//         if(mymap.count(vec[i])<1){
//             mymap[vec[i]]=true;
//             ans.push_back(vec[i]);
//         }
//     }
//     return ans;
// }



// int main(){
//     vector<int> q={1,2,2,5,5,5,3,8};
//     vector<int> ans=remove_duplicates(q);
//     cout<<"ans vector is: "<<endl;
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<endl;
//     }
//     return 0;
// }









// ITERATORS
// Iterators in vectors



vector<int> remove_element(vector<int> initial, int index){
    vector<int> :: iterator it=initial.begin();
    it++;
    
    initial.erase(it);
    return initial;

}

int main(){
      vector<int> q={1,2,2,5,5,5,3,8};
       vector<int> ans=remove_element(q,2);
    cout<<"ans vector is: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    for(auto j : ans) {
        cout << j << endl;
            }
    return 0;
}