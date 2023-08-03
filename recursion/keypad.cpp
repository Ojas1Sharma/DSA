#include <iostream>
using namespace std;
 string *arr=new string[30];


int rec(int no[], int n, string output[]){
    // here no is the array of input containing different digits
    // n is the length of array
    // output is output and it returns the length of output array of stings

if(n<=0){
    output[0]="";
    return 1;
}
else{
    int smalloutputlength=rec(no,n-1,output);
    int lastdigit=no[n-1];
    string pp=arr[lastdigit];
   
    int copiestobemade=pp.length()-1;
    int j=1;
    while(j<pp.length()){
        for(int i=0;i<smalloutputlength;i++){
            output[i+(smalloutputlength*j)]=output[i]+pp[j];
        }
        j++;
    }

   
    for(int i=0;i<smalloutputlength;i++){
        output[i]=output[i]+pp[0];
    }
   
    return smalloutputlength*(pp.length());

}
}






void printsubsec(int no[],int n,string o ){
if(n<=0){
    cout<<o<<endl;
}
else{
    int ll=no[n-1];
    
    // printsubsec(no,n-1,o+((arr[ll])[0]));
    // printsubsec(no,n-1,o+((arr[ll])[1]));
    // printsubsec(no,n-1,o+((arr[ll])[2]));
     printsubsec(no,n-1,((arr[ll])[0])+o);
    printsubsec(no,n-1,((arr[ll])[1])+o);
    printsubsec(no,n-1,((arr[ll])[2])+o);
    if(arr[ll].length()==4){
        //    printsubsec(no,n-1,o+((arr[ll])[3]));
           printsubsec(no,n-1,((arr[ll])[3])+o);
 
    }

}


}














int main(){
   string *output=new string[1000];
    arr[0]="";
    arr[1]="";
    arr[2]="abc";
    arr[3]="def";
    arr[4]="ghi";
    arr[5]="jkl";
    arr[6]="mno";
    arr[7]="pqrs";
    arr[8]="tuv";
    arr[9]="wxyz";
    int *no=new int[10];
    int temp;
    int i=0;
    for(;;i++){
        cin>>temp;
        if(temp==-1){
            break;
        }
        else{
            no[i]=temp;
            // cout<<no[i];
        }
    }

cout<<i<<endl;

// int length=rec(no,i,output);

// for(int i=0;i<length;i++){
    // cout<<output[i]<<endl;
// }

string ooo;
ooo="";
printsubsec(no,i,ooo);




    return 0;
}