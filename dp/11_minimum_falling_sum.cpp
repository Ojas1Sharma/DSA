#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

// recursive solution 
class Solution {
public:


    int helper(vector<vector<int>> & matrix, int i , int j){
        if(i==matrix.size()-1) return matrix[i][j];

        int left=1e9,down=1e9, right=1e9;
        
        if(j-1>=0)left=helper(matrix,i+1,j-1);
        down=helper(matrix, i+1,j);
        if(j+1<=matrix[0].size()-1)right=helper(matrix,i+1,j+1);
        // cout<<max(left,max(down,right))+matrix[i][j]<<endl;
        return min(left,min(down,right))+matrix[i][j];

    }



    int minFallingPathSum(vector<vector<int>>& matrix) {
    int maxi=1e9;
    for(int i=0;i<matrix[0].size();i++){
        int temp=helper(matrix,0,i);
        if(temp<maxi) maxi=temp;
    }
    return maxi;


    }
};
// recursive solution ends

// dp solution starts here

class Solution {
public:


    int helper(vector<vector<int>> & matrix, int i , int j,vector<vector<int>>& dp){
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=1e9,down=1e9, right=1e9;
        
        if(j-1>=0)left=helper(matrix,i+1,j-1,dp);
        down=helper(matrix, i+1,j,dp);
        if(j+1<=matrix[0].size()-1)right=helper(matrix,i+1,j+1,dp);
     
        return dp[i][j]=min(left,min(down,right))+matrix[i][j];

    }



    int minFallingPathSum(vector<vector<int>>& matrix) {
    int maxi=1e9;
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    for(int i=0;i<matrix[0].size();i++){
        int temp=helper(matrix,0,i,dp);
        if(temp<maxi) maxi=temp;
    }
    return maxi;
    }
};


// dp solution ends here

// tabulation starts here
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    // tabulation starts here
    for(int j=0;j<n;j++){
        dp[n-1][j]=matrix[n-1][j];
    }
    // cout<<"base case resolved"<<endl;
    for(int i=n-2;i>=0;i--){

        for(int j=0;j<n;j++){

            int left=1e9,down=1e9,right=1e9;
            if(j-1>=0)left=dp[i+1][j-1];
            down=dp[i+1][j];
            if(j+1<=n-1)right=dp[i+1][j+1];

            dp[i][j]=min(left,min(down,right))+matrix[i][j];

        }



    }

    int mini=1e9;
    for(int j=0;j<n;j++){
        if(dp[0][j]<mini) mini=dp[0][j];

    }
return mini;

    }
};

// tabulation ends here

// space optimisation

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

    int n=matrix.size();

    vector<int> front(n,-1);
    for(int j=0;j<n;j++){
        front[j]=matrix[n-1][j];
    }
  
    for(int i=n-2;i>=0;i--){
            vector<int> curr(n,-1);
        for(int j=0;j<n;j++){

            int left=1e9,down=1e9,right=1e9;
            if(j-1>=0)left=front[j-1];
            down=front[j];
            if(j+1<=n-1)right=front[j+1];

            curr[j]=min(left,min(down,right))+matrix[i][j];

        }
        front=curr;



    }

    int mini=1e9;
    for(int j=0;j<n;j++){
        if(front[j]<mini) mini=front[j];

    }
return mini;

    }
};

// ends











int main(){
    
    return 0;
}