#include<iostream>
#include<vector>
using namespace std;
int find(int x,vector<int>&parent){
    if(x==parent[x]) return x;
    return find(parent[x],parent);
}
void Union(int a,int b,vector<int>&parent){
    int a_parent=find(a,parent);
    int b_parent=find(b,parent);
    if(a_parent!=b_parent){
        parent[b_parent]=a_parent;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    Union(0,1,parent);
    Union(3,4,parent);
    Union(0,3,parent);
    for(int &ele:parent){
        cout<<ele<<" ";
    }
}