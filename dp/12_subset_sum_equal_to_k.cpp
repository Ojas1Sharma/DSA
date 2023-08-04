#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

// recursive solution

#include <bits/stdc++.h> 


bool helper(int i,int k, vector<int> & arr){
    if(k==0) return true;
    if(i==0)return arr[0]==k;

    bool nottake=helper(i-1,k,arr);
    bool take=false;
    if(arr[i]<=k) take =helper(i-1,k-arr[i],arr);

    return take || nottake;


}



bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(n,k,arr);
}


// recursive solution ends here

// dp solution starts here
#include <bits/stdc++.h> 


bool helper(int i,int k, vector<int> & arr,vector<vector<int>> & dp){
    if(k==0) return true;
    if(i==0)return arr[0]==k;
    if(dp[i][k]!=-1) return dp[i][k];

    bool nottake=helper(i-1,k,arr,dp);
    bool take=false;
    if(arr[i]<=k) take =helper(i-1,k-arr[i],arr,dp);

    return dp[i][k]= take || nottake;


}



bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    
    return helper(n,k,arr,dp);
}

// dp solution ends here
// tabulation starts here
#include <bits/stdc++.h> 



bool subsetSumToK(int n, int k, vector<int> &arr) {
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


// tabulation ends here


