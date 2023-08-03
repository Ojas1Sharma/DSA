#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;


// helper here denotes the amount of energy required to reach upto that level
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;


// helper here denotes the amount of energy required to reach upto that level
int helper(int n, vector<int> &heights, vector<int> & answer_vec){
    if(n==1){
        answer_vec[n]=0;
        return 0;
    }
    int first=INT_MAX, second=INT_MAX;
    if(answer_vec[n-1]!=-1){
         first=answer_vec[n-1]+abs(heights[n]-heights[n-1]);
    } else {
       first = helper(n - 1, heights, answer_vec) + abs(heights[n] - heights[n - 1]);
    }

    if(answer_vec[n-2]!=-1){
    second=answer_vec[n-2]+abs(heights[n]-heights[n-2]);

    }
    else{
     second=INT_MAX;
    if (n > 2) {
      second = helper(n - 2, heights, answer_vec) + abs(heights[n] - heights[n - 2]);
    }
    }
    // cout<<"returing: "<<min(first,second)<<endl;
    answer_vec[n]=min(first,second);
    return answer_vec[n];


}


int frogJump(int n, vector<int> &heights)
{
    vector<int> newvec(n+1,-1);
    vector<int> answer_vec(n+1,-1);
    for(int i=0;i<n;i++){
        newvec[i+1]=heights[i];
    }
   return helper(n,newvec,answer_vec);

}

int main(){
    vector<int> heights={10,20,30,10};
    cout<<"answer is: "<<frogJump(4,heights);
return 0;

}