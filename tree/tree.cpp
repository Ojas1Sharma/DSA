#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Treenode{
public:
T data;
vector<Treenode<T>*> children;
Treenode( T data){
    this->data=data;

}
};


void printtree(Treenode<int> * root){
    // cout<<"Printing Tree "<<endl;
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printtree(root->children[i]);
    }

}

Treenode<int>* takeinputbasic(){
    int data;
    cin>>data;
Treenode<int>* root=new Treenode<int>(data);
cout<<"how many children of node (data)"<<data;
int a;
cin>>a;
if(a==0){
    return root;
}
for(int i=0;i<a;i++){
   
    Treenode<int> * child=    takeinputbasic();
    root->children.push_back(child);

}
return root;

}


int countnodes(Treenode<int>* root){
    if(root->children.size()==0){
        return 1;
    }
    int count=0;
    for(int i=0;i<root->children.size();i++){
        int temp=countnodes(root->children[i]);
        count=count+temp;
    }
    return count+1;
}



Treenode<int> * takeinputlevelwise(){
    int data;
    cin>>data;
    Treenode<int>* root=new Treenode<int>(data);
    
    queue<Treenode<int>*> q1;
    q1.push(root);
    while(q1.size()!=0){
        Treenode<int>* tempnode=q1.front();
    q1.pop();
    //  cout<<"enter number of child nodes: "<<endl;
    int no;
    cin>>no;
    for(int i=0;i<no;i++){
        int temp;
        cin>>temp;
        Treenode<int> * child=new Treenode<int>(temp);
        tempnode->children.push_back(child);
        q1.push(child);
    }
    }
    return root;

}
// height
int height(Treenode<int> * root){
    if(root->children.size()==0){
        return 1;
    }
    int max=1;
    for(int i=0;i<root->children.size();i++){
        int temp=height(root->children[i]);
        if(temp>max){
            max=temp;
        }
    }
    return max+1;


}

int calculatesum(Treenode<int> * root){
    cout<<"here "<<endl;
    int sum=0;
    cout<<"root data is: "<<root->data<<" and no of children are: "<<root->children.size()<<endl;
    if(root->children.size()==0){
          cout<<"base case "<<endl;
        return root->data;
    }
    for(int i=0;i<root->children.size();i++){
         cout<<"lmao"<<endl;
        int temp=calculatesum(root->children[i]);
        sum=sum+temp;
    }
    cout<<"current sum is: "<<sum<<endl;
    return sum+root->data;
}



// all elements at depth d
void depth(Treenode<int> * root, int d){
    if(d==0){
        cout<<root->data<<" ";
    }
for(int i=0;i<root->children.size();i++){
    depth(root->children[i],d-1);
}
}


void preorder(Treenode<int> * root){
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void postorder(Treenode<int> * root){
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}


void deletenodes(Treenode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deletenodes(root->children[i]);
    }
    delete root;
}


bool containsx(Treenode<int> * root, int x){
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
        bool temp=containsx(root->children[i],x);
        if(temp==true){
            cout<<"here for value of x: "<<root->children[i]->data<<endl;
            return true;

        }
    }
    return false;

}


// node with max sum
// vector<vector<int>> v1;
// void maxsum(Treenode<int> * root){
//     int sum=root->data;
//     for(int i=0;i<root->children.size();i++){
//         sum=sum+root->children[i]->data;


//     }
//     vector<int> v2;
//     v2.push_back(root->data);
//     v2.push_back(sum);
//     v1.push_back(v2);
//         for(int i=0;i<root->children.size();i++){

//             maxsum(root->children[i]);

//         }
//     // cout<<v1[0][0]<<" "<<v1[0][1]<<endl;


//     // return v1[0][0];
// }
int calculatechildsum(Treenode<int> * root){
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum=sum+root->children[i]->data;

    }
    return sum;

}
Treenode<int> * maxsum(Treenode<int>* root){

    Treenode<int> * ans=root;
    for(int i=0;i<root->children.size();i++){
        Treenode<int> * temp=maxsum(root->children[i]);
       if(calculatechildsum(temp)>calculatechildsum(ans)){
        ans=temp;
       }
    }
    return ans;
}
Treenode<int> * nextlarger(Treenode<int> * root,int n){
 
Treenode<int> * ans= root;
int diff;
if(root->data>n){
    diff=root->data-n;
}
else{
    diff=1000;
}
for(int i=0;i<root->children.size();i++){
    Treenode<int> * temp=nextlarger(root->children[i],n);
   
    if(temp->data>n&&temp->data-n<diff){
        ans=temp;
        diff=temp->data-n;
        
    }

}

return ans;


}



// int main(){
//     Treenode<int>* head=takeinputlevelwise();
//     cout<<endl;

//     printtree(head);
//     int e=countnodes(head);
//     cout<<endl<<e<<endl;
//     cout<<height(head)<<endl;
//     depth(head,3);
//     // cout<<endl<<"preorder: "<<endl;
//     // preorder(head);
//     cout<<endl;
//     //   cout<<endl<<"postorder: "<<endl;
//     // postorder(head);
//     // deletenodes(head);
//     // cout<<endl<<"sum is: "<<endl;
//     // cout<<calculatesum(head)<<endl;
//     int x=8;
//     cout<<"start"<<endl;
//     // cout<<maxsum(head)->data;
//     cout<<nextlarger(head,18)->data;
    
//     // for(int i=0;i<v1.size();i++){
//     // cout<<v1[i][0]<<" "<<v1[i][1]<<endl;
//     // }
    
//     // cin>>x;
//     // bool temp=containsx(head,x);
//     // cout<<temp;
//     return 0;
// }
// // int main(){
// //     Treenode<int>* head=new Treenode<int>(1);
// //     Treenode<int>* child1=new Treenode<int>(2);
// //     Treenode<int>* child2=new Treenode<int>(3);
// //     head->children.push_back(child1);
// //     head->children.push_back(child2);
// //     cout<<head->data;
// //     cout<<head->children[0]->data;
// //     cout<<head->children[1]->data;
// //     cout<<endl;
// //     printtree(head);
    
// //     return 0;
// // }