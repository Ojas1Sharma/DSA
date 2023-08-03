
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int helper(int index, int k , vector<int> &heights){

if(index==1){
    return 0;
}

int min_value = INT_MAX;
for(int j=1;j<=k;j++){
          int temp_ans=INT_MAX;
            if(index-j>=1){
            temp_ans=helper(index-j,k,heights)+abs(heights[index]-heights[index-j]);
            }
            min_value=min(min_value,temp_ans);


        }

return min_value;



}




int minimizeCost(int n, int k, vector<int> &height){
    vector<int> newvec(n+1,-1);
    vector<int> answer_vec(n+1,-1);
    for(int i=0;i<n;i++){
        newvec[i+1]=height[i];
    }

    int answer=helper(n,k,newvec);
    return answer;
    // vector<int> k_vec(k,INT_MAX);
  

}

int main(){
    
    return 0;
}