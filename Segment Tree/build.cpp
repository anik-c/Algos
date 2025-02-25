#include<iostream>
#include<vector>
using namespace std;
void buildTree(vector<int>&v,int i,int l,int r,vector<int>&segmentTree){
    if(l==r){
        segmentTree[i]=v[l];
        return;
    }
    int mid=l+(r-l)/2;
    buildTree(v,2*i+1,l,mid,segmentTree);
    buildTree(v,2*i+2,mid+1,r,segmentTree);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
int main(){
    vector<int> v{3,1,2,7,1};
    vector<int> segmentTree(v.size()*2,0);
    buildTree(v,0,0,v.size()-1,segmentTree);
    for(int &ele:segmentTree){
        cout<<ele<<" ";
    }
} 