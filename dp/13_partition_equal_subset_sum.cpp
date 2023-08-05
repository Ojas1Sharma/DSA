#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

class Solution {
public:



    bool canPartition(vector<int>& arr) {
        if(arr.size()==1) return false;
        if(arr.size()==2) return arr[0]==arr[1];
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        int k=sum/2;
        int n=arr.size();



   vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    
    // return helper(n,k,arr,dp);
    
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){

        for(int target=1;target<k+1;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(arr[i]<=target) take =dp[i-1][target-arr[i]];

                dp[i][target]= take || nottake;
            

        }


    }
    return dp[n-1][k];



    }



};