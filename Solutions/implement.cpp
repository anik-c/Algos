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
Node* insert(Node *root){
    cout<<"Enter Value: ";
    int n;
    cin>>n;
    if(n==-1) return NULL;
    root=new Node(n);
    cout<<"Enter the value for left child of "<<n<<endl;
    root->left=insert(root->left);
    cout<<"Enter the value for right child of "<<n<<endl;
    root->right=insert(root->right);
    return root;
}
Node* inserttoBST(Node* &root,int data){
    if(!root){
      root=new Node(data);
      return root;   
    }
    if(data<root->val){
        root->left=inserttoBST(root->left,data);
    }
    else{
        root->right=inserttoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        inserttoBST(root,data);
        cin>>data;
    }
}
void morrispreorder(Node* root){
    Node*curr=root;
    while(curr){
        if(!curr->left){
            cout<<curr->val;
            curr=curr->right;
        }
        else{
            cout<<curr->val;
            Node* leftchild=curr->left;
            while(leftchild->right){
                leftchild=leftchild->right;
            }
            leftchild->right=curr->right;
            Node*temp=curr;
            curr=curr->left;
            temp->left=NULL;
        }
    }
}
bool searchNode(Node*root,int data){
    Node*temp=root;
    while(temp){
        if(temp->val==data) return true;
        else if(data>temp->val) temp=temp->right;
        else temp=temp->left;
    }
    return false;
}
void maxNode(Node*root){
    Node*temp=root;
    while(temp->right){
        temp=temp->right;
    }
    cout<<temp->val;
}
int main(){
    Node* root=NULL;
    // root=insert(root);
    takeInput(root);
    // morrispreorder(root);
    // cout<<searchNode(root,3);
        
}