
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;





int helper(int index, int k , vector<int> &heights,vector<int> & answer_vec){

if(index==1){
    answer_vec[1]=0;
    return 0;
}

int min_value = INT_MAX;
for(int j=1;j<=k;j++){
          int temp_ans=INT_MAX;
            if(index-j>=1){

                if(answer_vec[index-j]!=-1){
                    temp_ans=answer_vec[index-j]+abs(heights[index]-heights[index-j]);
                }
                else{
                    temp_ans=helper(index-j,k,heights,answer_vec)+abs(heights[index]-heights[index-j]);
                }



            
            }
            min_value=min(min_value,temp_ans);


        }
answer_vec[index]=min_value;
return min_value;



}




int minimizeCost(int n, int k, vector<int> &height){
    vector<int> newvec(n+1,-1);
    vector<int> answer_vec(n+1,-1);
    for(int i=0;i<n;i++){
        newvec[i+1]=height[i];
    }

    int answer=helper(n,k,newvec,answer_vec);
    return answer;
    // vector<int> k_vec(k,INT_MAX);
  
    



}







int main(){
    
    return 0;
}