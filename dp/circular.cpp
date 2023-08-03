#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

 long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int prev2=0;
    long long int prev1=nums[0];
    long long int curr;
    long long int take;
    for(int i=1;i<nums.size();i++){
       
        if(i>1){
        take=nums[i]+prev2;
        }
        else{
            take=nums[i];
        }
        long long int nottake=0+prev1;
        curr=max(take,nottake);
        prev2=prev1;
        prev1=curr;
    }


    return prev1;
}



long long int houseRobber(vector<int>& valueInHouse)
{
    if (valueInHouse.size()==1) return valueInHouse[0];
    vector<int> temp1;
    vector<int> temp2;
    int n=valueInHouse.size();
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    cout<<"here"<<endl;
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));

}


int main(){
    vector<int> q={1,2,3,1,3};
    long long int temp=houseRobber(q);
    cout<<temp<<endl;
    return 0;
}