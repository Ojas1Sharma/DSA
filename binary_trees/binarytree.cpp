#include <iostream>
#include <queue>
using namespace std;



template <typename T>
class Binarynode{
public:
T data;
Binarynode<T>* left;
Binarynode<T>* right;
Binarynode(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
~Binarynode(){
    delete left;
    delete right;
}

};



Binarynode<int> * takeinput(){
    int a;
    cin>>a;
    if(a==-1){
        return NULL;
    }
    Binarynode<int> * root=new Binarynode<int>(a);
    Binarynode<int> * left=takeinput();
    Binarynode<int> * right=takeinput();
    root->left=left;
    root->right=right;
    return root;


}

void printbinarytree(Binarynode<int>* root){
if(root==NULL){
    return;
}
cout<<root->data<<": ";
if(root->left!=NULL){
    cout<<"L"<<root->left->data;
}
if(root->right!=NULL){
    cout<<"R"<<root->right->data;

}
cout<<endl;
printbinarytree(root->left);
printbinarytree(root->right);


}
Binarynode<int> * takeinputlevelwise(){
    int a;
    cin>>a;
    if(a==-1){
        return NULL;
    }

}


Binarynode<int> * takesamelevelinput(){
    int a;
    cout<<"enter the root node: ";
    cin>>a;
    Binarynode<int> * root=new Binarynode<int>(a);
    queue<Binarynode<int>*> q1;
    q1.push(root);
    cout<<endl;

    while(q1.size()!=0){
        Binarynode<int> * temp=q1.front();
        q1.pop();
        cout<<"enter the left node for: "<<temp->data<<endl;
        int templeft;
        cin>>templeft;
        if(templeft!=-1){
            Binarynode<int> * left=new Binarynode<int>(templeft);
            temp->left=left;
            q1.push(left);


        }
        cout<<"enter the right node for: "<<temp->data<<endl;
        int tempright;
        cin>>tempright;
        if(tempright!=-1){
            Binarynode<int> * right=new Binarynode<int>(tempright);
            temp->right=right;
            q1.push(right);


        }




    }
    return root;
    
}






int countnodes(Binarynode<int> * root){
    if(root->left==NULL &&root->right==NULL){
        return 1;
    }
    int l=countnodes(root->left);
    int r=countnodes(root->right);
    return l+r+1;


}





void inorder(Binarynode<int> * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);



}
void preorder(Binarynode<int> * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Binarynode<int> * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



// construct a tree from inorder and preorder

Binarynode<int> * constructtree(vector<int> preorder, vector<int> inorder, int prestart, int preend,int instart, int inend){
    
    // if(preend-prestart==0||inend-instart==0){
    //     Binarynode<int> * root=new Binarynode<int>(preorder[prestart]);
    //     return root;

    // }
    if(prestart>preend){
        return NULL;

    }
    Binarynode<int> * root=new Binarynode<int>(preorder[prestart]);
    int rootindex=0;
    while(inorder[rootindex]!=root->data){
        rootindex++;
    }


    int leftprestart=prestart+1;
    int leftinstart=instart;
    int leftinend=rootindex-1;
    int rightpreend=preend;
    int rightinstart=rootindex+1;
    int rightinend=inend;

    int leftpreend=rootindex-instart+prestart;
    int rightprestart=leftpreend+1;

    



    Binarynode<int> * left=constructtree(preorder,inorder,leftprestart,leftpreend,leftinstart,leftinend);
    Binarynode<int> * right=constructtree(preorder,inorder,rightprestart,rightpreend,rightinstart,rightinend);
    
    root->left=left;
    root->right=right;
    return root;






}


// 5 6 2 3 9 10 
// 2 6 3 9 5 10

Binarynode<int> * constructfrompost(vector<int> postorder, vector<int> inorder,int poststart,int postend, int instart, int inend){
    if(poststart>postend||instart>inend){
        return NULL;
    }
    Binarynode<int> * root=new Binarynode<int>(postorder[postend]);

    int rootindex=0;
    while(inorder[rootindex]!=postorder[postend]){
        rootindex++;
    }
    cout<<endl<<"root index is: "<<rootindex<<endl;


    int leftpoststart=poststart;
    int leftpostend=rootindex-instart-1+poststart;
    int leftinstart=instart;
    int leftinend=rootindex-1;
    
    
    int rightpoststart=leftpostend+1;
    int rightpostend=postend-1;
    int rightinstart=rootindex+1;
    int rightinend=inend;

    Binarynode<int> * leftnode=constructfrompost(postorder,inorder,leftpoststart,leftpostend,leftinstart,leftinend);
    Binarynode<int> * rightnode=constructfrompost(postorder,inorder,rightpoststart,rightpostend,rightinstart,rightinend);
    root->left=leftnode;
    root->right=rightnode;
    return root;




}

struct struc{
public:
int a;
int b;
struc(int a, int b){
    this->a=a;
    this->b=b;
}
};

struc * maxdiameter(Binarynode<int> * root){
    struc * s1=new struc(1,1);
    if(root->left==NULL&&root->right==NULL){
        return s1;
    }
struc * leftside=new struc(0,0);
struc * rightside=new struc(0,0);

    if(root->left!=NULL){
    leftside=maxdiameter(root->left);
    }
    if(root->right!=NULL){
    rightside=maxdiameter(root->right);
    }
    int sum=leftside->a+rightside->b+1;
    s1->a=sum;

    if(leftside->b>rightside->b){
s1->b=leftside->b;
    }
    else{
        s1->b=rightside->b;
    }

return s1;
 

    


}


struct mm{
  public:
    int min;
    int max;
    mm(int a,int b){
        min=a;
        max=b;
    }
};


mm * minmax(Binarynode<int> * root){
if(root==NULL){
    mm * temp = new mm(-1,-1);
    return temp;
}
mm * s1=new mm(root->data,root->data);
mm * left=minmax(root->left);
if(left->min==-1){
    left=s1;
}

mm * right=minmax(root->right);
// cout<<"right received is: "<<right->min<<" "<<right->max<<endl;
if(right->min==-1){
    right=s1;
}
int finalmin=min(left->min,min(s1->min,right->min));
int finalmax=max(left->max,max(right->max,s1->max));
// cout<<"calculating max between"<<left->max<<" "<<right->max<<" "<<s1->max<<" and found it to be "<<finalmax<<endl;
s1->max=finalmax;
s1->min=finalmin;
// cout<<"finalmax: "<<finalmax<<" finalmin: "<<finalmin<<endl;
return s1;



}


int main(){
    // Binarynode<int> * root=takesamelevelinput();    
    cout<<"here"<<endl;
    vector<int> post{6,5,4,9,8,7,2,3,1};
    vector<int> in{6,5,4,2,9,8,7,1,3};
    // vector<int> pre{1,2,4,5,3,6,8,9,7 };
    // vector<int> in{ 4,2,5,1,8,6,9,3,7};
Binarynode<int> * root=constructfrompost(post,in,0,8,0,8);


    printbinarytree(root);

    struc * ss=maxdiameter(root);
    if(ss->a>ss->b){
        cout<<"ans is: "<<ss->a;
    }
    else{
        cout<<"here you go: "<<ss->b;
    }
    
    cout<<endl;
    mm * ans=minmax(root);
    cout<<"the minimum element is: "<<ans->min<<" and the max element is: "<<ans->max<<endl;
    
    // cout<<endl<<"The no of nodes are: "<< countnodes(root)<<endl;
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);



    return 0;
}
