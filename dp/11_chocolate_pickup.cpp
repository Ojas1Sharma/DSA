#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}


// recursive solution
#include <bits/stdc++.h> 



int helper( int r, int c, vector<vector<int>> & grid, int i, int j1, int j2){

if(i==r-1){
    if(j1==j2) return grid[i][j1];
    return grid[i][j1]+grid[i][j2];
}

if(j1<0||j2<0||j1>=c||j2>=c){
    return -1e8;
}

vector<int> p={-1,0,1};
int value=0;
if(j1==j2) value=grid[i][j1];
if(j1!=j2) value=grid[i][j1]+grid[i][j2];
int max=-1e9;
for(auto x1 : p){
    for(auto x2: p){
        int temp=helper(r,c,grid,i+1,j1+x1,j2+x2);
        if(temp>max) max=temp;


    }
}
value +=max;

return value;


}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int ans=helper(r,c,grid,0,0,c-1);
    return ans;
}

// recursive solution ends here

// dp solution starts here
#include <bits/stdc++.h> 



int helper( int r, int c, vector<vector<int>> & grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp){

if(i==r-1){
    if(j1==j2) return grid[i][j1];
    return grid[i][j1]+grid[i][j2];
}

if(j1<0||j2<0||j1>=c||j2>=c){
    return -1e8;
}
if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

vector<int> p={-1,0,1};
int value=0;
if(j1==j2) value=grid[i][j1];
if(j1!=j2) value=grid[i][j1]+grid[i][j2];
int max=-1e9;
for(auto x1 : p){
    for(auto x2: p){
        int temp=helper(r,c,grid,i+1,j1+x1,j2+x2,dp);
        if(temp>max) max=temp;


    }
}
value +=max;

return dp[i][j1][j2]=value;


}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    
    int ans=helper(r,c,grid,0,0,c-1,dp);
    return ans;
}


// dp ends

// tabulation starts here
#include <bits/stdc++.h> 




int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

    for(int x1=0;x1<c;x1++){
        for(int x2=0;x2<c;x2++){
            if(x1==x2){
                 dp[r-1][x1][x2]= grid[r-1][x1];
                 }
            else{
                 dp[r-1][x1][x2]=grid[r-1][x1]+grid[r-1][x2];
                 }

        }
        
    }
    // cout<<"base case resolved"<<endl;
    for(int i=r-2;i>=0;i--){
        for(int x1=0;x1<c;x1++){
            for(int x2=0;x2<c;x2++){
                int max = -1e9;
                vector<int> p={-1,0,1};
                int left=-1e9,right=-1e9,down=-1e9;
                int value;
                if(x1==x2) value=grid[i][x1];
                if(x1!=x2) value =grid[i][x1]+grid[i][x2];
                // int max=-1e9;
                for(auto a:p){
                    for(auto b: p){
                        int temp=-1e9;
                        if(x1+a<0||x2+b<0||x1+a>=c||x2+b>=c){
                            temp=-1e9;
                        }
                        else{
                        temp=dp[i+1][x1+a][x2+b];
                        if(temp>max){
                            max=temp;
                        }

                        }


                    }

                }
                value+=max;
           
                dp[i][x1][x2]=value;
                
            }

        }

    }
    return dp[0][0][c-1];
}

// tabulation ends here