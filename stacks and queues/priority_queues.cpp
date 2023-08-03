#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
       priority_queue<int> pq;
        for(int i=0;i<k;i++){
            for(int j=0;j<arr[0].size();j++){
                pq.push(arr[i][j]);
            }

        }
        vector<int> vec;
        while(pq.empty()==0){
            // cout<<pq.top();
            vec.push_back(pq.top());
            pq.pop();
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};


int main(){
    Solution s1;
    int K = 3;

    vector<vector<int>> v1={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=s1.mergeKArrays(v1,K);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}