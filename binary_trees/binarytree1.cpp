#include <iostream>
using namespace std;


template <typename T>
class binary_tree_node{
public:
T data;
binary_tree_node *left;
binary_tree_node *right;
binary_tree_node(T data){
    this->data=data;
    left=NULL;
    right=NULL;
}
~binary_tree_node(){
    delete left;
    delete right;

}


};


int main(){
    binary_tree_node<int> * root=new binary_tree_node<int>(1);

    binary_tree_node<int> * left=new binary_tree_node<int>(2);
    binary_tree_node<int> * right=new binary_tree_node<int>(3);
    root->left=left;
    root->right=right;
    cout<<root->left->data;
    return 0;
}