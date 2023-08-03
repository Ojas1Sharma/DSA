#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}



// recursion solution starts here
class Solution {
public:


    int helper(int m , int n){
        if(m==0&&n==0){
            return 1;
        }
        if(m<0||n<0){
            return 0;
        }
        int up=helper(m-1,n);
        int left=helper(m,n-1);

        return up+left;

    }




    int uniquePaths(int m, int n) {
    int ans=helper(m-1,n-1);
    return ans;       
    }
};
// recursion ends here

// dp solution starts here

class Solution {
public:


    int helper(int m , int n, vector<vector<int>> &dp){
        if(m==0&&n==0){
            return dp[0][0]=1;
        }
         if(m<0||n<0){
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];
       
        int up=helper(m-1,n,dp);
        int left=helper(m,n-1,dp);

        return dp[m][n]=up+left;

    }


    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    int ans=helper(m-1,n-1 ,dp);
    return ans;       
    }
};



// dp solution ends here

// tabulation starts here


    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                continue;
            } 
               int left=0,up=0;
               if(i>=1) up=dp[i-1][j];
               if(j>=1) left=dp[i][j-1];
                dp[i][j]=up+left;
        }
    }
    
    
    return dp[m-1][n-1];       
    }
};

// end of tabulation


// space optimized version
class Solution {
public:


    int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    vector<int> curr(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                curr[0]=1;
                continue;
            } 
               int left=0,up=0;
               if(i>=1) up=prev[j];
               if(j>=1) left=curr[j-1];
                curr[j]=up+left;

        }
        prev=curr;
    }    
    return prev[n-1];       
    }
};