#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}


// recursion solution
class Solution {
public:

    int helper(vector<vector<int>>& triangle, int i, int j){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        int d=helper(triangle,i+1,j);
        int dr=helper(triangle,i+1,j+1);
        cout<<min(d,dr)+triangle[i][j]<<endl;
        return min(d,dr)+triangle[i][j];

    }



    int minimumTotal(vector<vector<int>>& triangle) {
    int ans=helper(triangle,0,0); 
    return ans;   
    }
};
// recursion solution ends here

// dp starts here
class Solution {
public:

    int helper(vector<vector<int>>& triangle, int i, int j,vector<vector<int>> & dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int d=helper(triangle,i+1,j,dp);
        int dr=helper(triangle,i+1,j+1,dp);
        
        return dp[i][j]=min(d,dr)+triangle[i][j];

    }



    int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()+1,-1));
    int ans=helper(triangle,0,0,dp); 
    return ans;   
    }
};

// dp ends 

// tabulation starts 
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()+1,-1));

    int n=triangle.size();
    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
        int d=dp[i+1][j];
        int dr=dp[i+1][j+1];
        dp[i][j]=min(d,dr)+triangle[i][j];
    
        }

    }

    return dp[0][0];   
    }
};

// tabulation ends here


// space optimized
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
    vector<int> front(n,-1);
    for(int i=0;i<n;i++){
        front[i]=triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int> curr(n,-1);
        for(int j=i;j>=0;j--){
        int d=front[j];
        int dr=front[j+1];
       curr[j]=min(d,dr)+triangle[i][j];
    
        }
        front=curr;
    }

    return front[0];   
    }
};

// space optimization ends here