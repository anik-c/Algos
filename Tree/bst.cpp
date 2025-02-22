#include<iostream>
#include<queue>
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
Node* insert(Node* &root, int data){
    if(!root){
        root=new Node(data);
        return root;
    }
    if(data<root->val){
        root->left=insert(root->left,data);
    }
    else root->right=insert(root->right,data);
    return root;
}
void input(Node* &root){
    int n;
    cin>>n;
    while(n!=-1){
        insert(root,n);
        cin>>n;
    }
}
void levelorder(Node* &root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cout<<endl;
    }
}
int main(){
    Node* root=NULL;
    input(root);
    levelorder(root);
}