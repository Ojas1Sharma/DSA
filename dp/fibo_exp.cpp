#include <vector>
#include <iostream>
using namespace std;

// remember &vec is very important in the function parameters

int fibo(int n,vector<int> &vec){
        if(n<=2){
                vec[n] = 1;
                return 1;
                
        }
        else {
                if (vec[n] != -1){ 
                    cout<<"found"<<endl;
                    return vec[n];}
                int temp = fibo(n - 1,vec) + fibo(n - 2,vec);
                vec[n] = temp;
                return temp;
                
        }
}


int main()
{
        int n=10;
        // cin >> n;
        vector < int > vec(n+1,-1);

        int ans=fibo(n,vec);
        // cout<<vec[n];
        cout<<ans;
}