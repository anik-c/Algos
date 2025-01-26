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
int main(){
    Tree *t=new Tree(1);
    t->left=new Tree(2);
    t->right=new Tree(3);
    cout<<t->val<<" "<<t->left->val<<" "<<t->right->val;

}