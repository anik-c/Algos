#include<iostream>
using namespace std;
class Tree{
    public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void inorder(Tree* &t){
    if(!t) return;
    inorder(t->left);
    cout<<t->val<<" ";
    inorder(t->right);
}
int main(){
    Tree *t=new Tree(1);
    t->left=new Tree(2);
    t->right=new Tree(3);
    t->left->left=new Tree(4);
    t->left->right=new Tree(5);
    t->right->left=new Tree(6);
    t->right->right=new Tree(7);
    inorder(t);
//                  1
//                 / \
//                2   3
//               /\   /\
//              4  5 6  7
}