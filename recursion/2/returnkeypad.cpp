#include <iostream>
using namespace std;

string * keys= new string[10];

void printputput(string s[]){
    cout<<"starts here"<<endl;
    for(int i=0;i<3;i++){
        cout<<s[i]<<endl;
    }
    cout<<"ends here"<<endl;
}



int returnkeypad(string s, string p[]){
    if(s.length()==1){
        char ll=s[0];
        int kp=int(ll)-48;
     
            p[0]=keys[kp].substr(0,1);
            p[1]=keys[kp].substr(1,1);
            p[2]=keys[kp].substr(2,1);
   if(keys[kp].length()==4){
    p[3]=keys[3].substr(3,1);
    return 4;
   }
//    printputput(p);
   return 3;
     
    }
    else{
        int k=returnkeypad(s.substr(1),p);
        char c=s[0];
        int qq=int(c)-48;
        if(keys[qq].length()==3){
            // cout<<"k is "<<k<<endl;
            // cout<<"start pi"<<endl;
            string pp[1000];
            for(int i=0;i<k;i++){
                pp[i]=p[i];
            }

        
            for(int i=0;i<k*3;i++){
                p[i]=keys[qq].substr(i/k,1)+pp[i%k];
                // cout<<p[i]<<endl;
            }
            // cout<<"end pi";
            return k*3;
        }
        if(keys[qq].length()==4){
            string pp[1000];
            for(int i=0;i<k;i++){
                pp[i]=p[i];
            }
            for(int i=0;i<k*4;i++){
                p[i]=keys[qq].substr(i/k,1)+pp[i%k];
            }
            return k*4;
        }

    }

}





int main(){
    string s;
    cin>>s;

keys[0]=" ";
keys[1]=" ";
keys[2]="abc";
keys[3]="def";
keys[4]="ghi";
keys[5]="jkl";
keys[6]="mno";
keys[7]="pqrs";
keys[8]="tuv";
keys[9]="wxyz";


    string* p = new string[1000];
    int n= returnkeypad(s,p);
    for(int i=0;i<n;i++){
        cout<<p[i]<<endl;
    }
    return 0;
}