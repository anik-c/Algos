#include<iostream>
using namespace std;
class Tree{
    public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void flatten(Tree* &root){
    if(!root) return;

    flatten(root->left);
    flatten(root->right);

    Tree *tempRight=root->right;
    root->right=root->left;
    Tree *curr=root;
    while(curr->right){
        curr=curr->right;
    }
    curr->right=tempRight;
}
int main(){
    Tree *t=new Tree(1);
    t->left=new Tree(2);
    t->right=new Tree(3);
    t->left->left=new Tree(4);
    t->left->right=new Tree(5);
    t->right->left=new Tree(6);
    t->right->right=new Tree(7);
    flatten(t);
    while(t->right){
        cout<<t->data<<" ";
        t=t->right;
    }
//                  1
//                 / \
//                2   3
//               /\   /\
//              4  5 6  7
}