#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

// recursion approach
class Solution {
public:

    int helper(int i, int j, vector<vector<int>> &grid){
        if(i==0&&j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        int up =grid[i][j];
        int left =grid[i][j];
         up+=helper(i-1,j,grid);
         left+=helper(i,j-1,grid);
        
        return(min(up,left));


    }





    int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    return helper(n-1,m-1,grid);        
    }
};

// dp

class Solution {
public:

    int helper(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0&&j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up =grid[i][j];
        int left =grid[i][j];
         up+=helper(i-1,j,grid,dp);
         left+=helper(i,j-1,grid,dp);
        
        return(dp[i][j]=min(up,left));


    }


    int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,grid,dp);        
    }
};


// dp solution ends here

// tabulation starts here

class Solution {
public:

    int helper(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0&&j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up =grid[i][j];
        int left =grid[i][j];
         up+=helper(i-1,j,grid,dp);
         left+=helper(i,j-1,grid,dp);
        
        return(dp[i][j]=min(up,left));


    }


    int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    // return helper(n-1,m-1,grid,dp);  
    for(int i=0;i<n;i++){


        for(int j=0;j<m;j++){
            if(i==0&&j==0){
                dp[i][j]=grid[i][j];
                continue;
            }
             int up =grid[i][j];
        int left =grid[i][j];
        if(i>0){ up+=dp[i-1][j];}
        else{
            up+=1e9;
        }

        if(j>0){
             left+=dp[i][j-1];}
        else{
            left+=1e9;
        }

        dp[i][j]=min(up,left);

        }
    }
    return dp[n-1][m-1];




    }
};


// tabulation ends here

// space optimization starts here

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,-1);
    

    for(int i=0;i<n;i++){
        vector<int> curr(m,0);

        for(int j=0;j<m;j++){
            if(i==0&&j==0){
                curr[j]=grid[i][j];
                continue;
            }
        int up =grid[i][j];
        int left =grid[i][j];
        if(i>0){ up+=prev[j];}
        else{
            up+=1e9;
        }

        if(j>0){
             left+=curr[j-1];}
        else{
            left+=1e9;
        }

        curr[j]=min(up,left);

        }
        prev=curr;
    }
    return prev[m-1];




    }
};


// space optimization ends here