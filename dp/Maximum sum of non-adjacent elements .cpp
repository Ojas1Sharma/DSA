#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

int helper(vector<int> & nums, int index){
if(index==0){
    return nums[0];
}

if(index<0){
    return 0;
}

int take=nums[index]+helper(nums,index-2);
int nottake=0+helper(nums,index-1);

return max(take,nottake);


}




int maximumNonAdjacentSum(vector<int> &nums){
    // return maximum sum in such a way that no two adjacent elements are selected
    int answer=helper(nums, nums.size()-1);
    return answer;
}

// end of recursion code

// start of dp code

int helper(vector<int> & nums,vector<int> &dp, int index){
if(index==0){
    return dp[0]=nums[0];
}

if(index<0){
    return 0;
}

if(dp[index]!=-1){
    return dp[index];
}

int take=nums[index]+helper(nums,dp,index-2);
int nottake=0+helper(nums,dp,index-1);

return dp[index]=max(take,nottake);


}




int maximumNonAdjacentSum(vector<int> &nums){
    // return maximum sum in such a way that no two adjacent elements are selected
    
    vector<int> dp(nums.size(),-1);
    
    int answer=helper(nums,dp, nums.size()-1);
    
    return answer;
}





// start of tabulation way
#include <bits/stdc++.h> 


int helper(vector<int> & nums,vector<int> &dp, int index){
if(index==0){
    return dp[0]=nums[0];
}

if(index<0){
    return 0;
}

if(dp[index]!=-1){
    return dp[index];
}

int take=nums[index]+helper(nums,dp,index-2);
int nottake=0+helper(nums,dp,index-1);

return dp[index]=max(take,nottake);


}




int maximumNonAdjacentSum(vector<int> &nums){
    // return maximum sum in such a way that no two adjacent elements are selected
    
    vector<int> dp(nums.size(),-1);
    
    // int answer=helper(nums,dp, nums.size()-1);

    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        int take=0;
        if(i>1){
        take=nums[i]+dp[i-2];
        }
        else{
            take=nums[i];
        }
        int nottake=0+dp[i-1];
        dp[i]=max(take,nottake);
    }


    return dp[nums.size()-1];
}


// memory optimized
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int prev2=0;
    int prev1=nums[0];
    int curr;
    int take;
    for(int i=1;i<nums.size();i++){
       
        if(i>1){
        take=nums[i]+prev2;
        }
        else{
            take=nums[i];
        }
        int nottake=0+prev1;
        curr=max(take,nottake);
        prev2=prev1;
        prev1=curr;
    }


    return prev1;
}
