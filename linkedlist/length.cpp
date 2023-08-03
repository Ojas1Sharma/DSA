#include <iostream>
#include "midpoint.cpp"
using namespace std;


int lllenngth(Node * head){
    cout<<"here"<<endl;
    printll(head);

Node *temp =head;
int c=0;
while(temp->next!=NULL){
c++;
temp=temp->next;

}
cout<<"length of the above ll is "<<c+1;

return c+1;
}



int main(){
    int c;
    cin>>c;
    int arr[c];
    for(int i=0;i<c;i++){
        Node * temp =inputll();
        arr[i]=lllenngth(temp);
    }
    for(int i=0;i<c;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}