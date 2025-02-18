#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
Node*  reversell(Node* &head){
    if(!head || !head->next) return head;
    Node* last=reversell(head->next);
    head->next->next=head;
    head->next=NULL;
    return last;
}
int main(){
    Node *head= new Node(12);
    head->next=new Node(13);
    head->next->next=new Node(14);
    head->next->next->next=new Node(15);
    head->next->next->next->next=new Node(16);
    head->next->next->next->next->next=new Node(17);
    Node *temp=reversell(head);
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}