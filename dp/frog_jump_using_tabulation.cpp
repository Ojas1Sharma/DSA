#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;




int frogJump(int n, vector<int> &heights)
{
    vector<int> newvec(n+1,-1);
    vector<int> answer_vec(n+1,-1);
    for(int i=0;i<n;i++){
        newvec[i+1]=heights[i];
    }
    // we have an newvec where the heights are stored
    answer_vec[1]=0;
    int first=INT_MAX;
    int second=INT_MAX;

    for(int i=2;i<n+1;i++){
      if (i > 2) {
        answer_vec[i] = min(answer_vec[i - 1] + abs(newvec[i] - newvec[i - 1]),
                            answer_vec[i - 2] + abs(newvec[i] - newvec[i - 2]));
      }
      else{
          answer_vec[i]=answer_vec[i - 1] + abs(newvec[i] - newvec[i - 1]);
      }
    }
   return answer_vec[n];

}

int main(){
    
    return 0;
}