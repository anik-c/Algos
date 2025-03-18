#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    } 
};
void insert(Node* &root, int data){
    if(!root){
        root=new Node(data);
        return ;
    }
    if(data<root->val){
        insert(root->left,data);
    }
    else{
        insert(root->right,data);
    }
}
void takeinput(Node* &root){
    int n;
    cin>>n;
    while(n!=-1){
        insert(root,n);
        cin>>n;
    }
}
void preorder(Node* &root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root=NULL;
    takeinput(root);
    preorder(root);
}