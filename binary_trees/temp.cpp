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



int main(){
    Treenode<int> * root=takeinputbasic();
    printtree(root);



    return 0;
}