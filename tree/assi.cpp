#include <iostream>
#include "tree.cpp"
#include <algorithm>


using namespace std;

Treenode<int> * takeinput(int a){

 Treenode<int> * root=new Treenode<int>(a);
    cout<<"how many children?"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Treenode<int> * tempnode=new Treenode<int>(temp);
        root->children.push_back(tempnode);

    }
    for(int i=0;i<root->children.size();i++){
        root->children[i]=takeinput(root->children[i]->data);
    }
    return root;


}
Treenode<int> * callerfunction(){
    int a;
    cin>>a;
    Treenode<int> * root=new Treenode<int>(a);
    root=takeinput(a);
}




















struct object{
Treenode<int> * max=NULL;
Treenode<int> * secmax=NULL;
};
bool comparebysize(const Treenode<int> * a, const Treenode<int> * b){
    return a->data< b->data;
}















object * second(Treenode<int> * root){
    cout<<endl<<"called at  "<<root->data<< endl;
if(root->children.size()==0){
object* t1=new object();
t1->max=root;
Treenode<int> * temp=new Treenode<int>(-1);
t1->secmax=temp;
return t1;
}






vector<Treenode<int> *> v1;
for(int i=0;i<root->children.size();i++){
    object * temp=second(root->children[i]);
    v1.push_back(temp->max);
    v1.push_back(temp->secmax);
    v1.push_back(root);
}
cout<<endl<<"before sorting: "<<endl;
for(int i=0;i<v1.size();i++){
    cout<<v1[i]->data<<"  ";
}
cout<<endl;
std:sort(v1.begin(),v1.end(),comparebysize);
cout<<"after sorting: "<<endl;
for(int i=0;i<v1.size();i++){
    cout<<v1[i]->data<<"  ";
}
cout<<endl<<"now sending "<<v1[v1.size()-1]->data<<"  and  "<<v1[v1.size()-2]->data<<"  back"<<endl;
object* t2=new object();
t2->max=v1[v1.size()-1];
t2->secmax=v1[v1.size()-2];
return t2;




}

int helperfunction(Treenode<int> * root){
    Treenode<int> * ans=second(root)->secmax;
    return ans->data;
    

}


Treenode<int> * levelwisechange(Treenode<int> * root, int c){

    for(int i=0;i<root->children.size();i++){


        levelwisechange(root->children[i],c+1);
    }
    root->data=c;
    return root;
    
}



int main(){
    Treenode<int> * head=callerfunction();
    printtree(head);    
    cout<<endl;
    Treenode<int> * ans=levelwisechange(head,0);
    printtree(ans);
    cout<<endl<<ans->data;
    // cout<<helperfunction(head);
    return 0;
}