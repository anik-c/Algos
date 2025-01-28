#include<iostream>
#include<queue>
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
void levelorder(Tree* &t){
    queue<Tree*>q;
    q.push(t);
    while(!q.empty()){
        Tree* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main(){
    Tree *t=new Tree(1);
    t->left=new Tree(2);
    t->right=new Tree(3);
    t->left->left=new Tree(4);
    t->left->right=new Tree(5);
    t->right->left=new Tree(6);
    t->right->right=new Tree(7);
    levelorder(t);
//                  1
//                 / \
//                2   3
//               /\   /\
//              4  5 6  7
}