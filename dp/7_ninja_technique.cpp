// remember you do not have the skip problem in this 
// i.e. you dont need to worry about not performing any task on a particular day 
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;


// recursion solution


int helper(int day,int task,vector<vector<int>> &points ){

    if( day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i==task) continue;
            maxi=max(maxi,points[0][i]);

        }
        return maxi;
    }

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i==task) continue;
        maxi=max(maxi,points[day][i]+helper(day-1,i,points));

    }
    return maxi;



}




int ninjaTraining(int n, vector<vector<int>> &points)
{
    int answer=helper(n-1,3,points);
}


// recursion solution ends

// using dp


int helper(int day,int task,vector<vector<int>> &points, vector<vector<int>>&dp ){

 

    if( day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=task)
             maxi=max(maxi,points[0][i]);

        }
        return dp[day][task]=maxi;
    }

       if(dp[day][task]!=-1) return dp[day][task];

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=task){
        maxi=max(maxi,points[day][i]+helper(day-1,i,points,dp));     
        }
    }
    
    return dp[day][task]=maxi;

}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int answer=helper(n-1,3,points,dp);
    return answer;
}

// dp ends

// tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));

    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);

    for(int i=1;i<n;i++){
        // int max=0;
        for(int j=0;j<3;j++){
           int maxi=0;
           for(int k=0;k<3;k++){
               if(j!=k){

                   maxi=max(maxi,dp[i-1][k]+points[i][k]);
               }
           }
           dp[i][j]=maxi;
        }
    }
    return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

}
// tabulation ends


// space optimization


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,-1);
    vector<int> curr(4,-1);

    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);

    for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
           int maxi=0;
           for(int k=0;k<3;k++){
               if(j!=k){

                   maxi=max(maxi,prev[k]+points[i][k]);
               }
           }
           curr[j]=maxi;
        }
        prev=curr;
    }
    return max(max(prev[0],prev[1]),prev[2]);

}

// space optimization ends



















int main(){
    
    
    return 0;
}