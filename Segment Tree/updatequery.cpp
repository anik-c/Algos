#include<iostream>
#include<vector>
using namespace std;
void build(vector<int> &v,vector<int> &segmentTree,int i,int l,int r){
    if(l==r){
        segmentTree[i]=v[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(v,segmentTree,2*i+1,l,mid);  
    build(v,segmentTree,2*i+2,mid+1,r); 
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2]; 
}
void update(vector<int>&segmentTree,vector<int> &v,int idx,int i,int l,int r,int val){
    if(l==r){
        segmentTree[i]=val;
        v[idx]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(idx<=mid) update(segmentTree,v,idx,2*i+1,l,mid,val);
    else update(segmentTree,v,idx,2*i+2,mid+1,r,val);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
int main(){
    vector<int> v{3,1,2,7};
    vector<int> segmentTree(2*v.size());
    build(v,segmentTree,0,0,v.size()-1);
    update(segmentTree,v,1,0,0,v.size()-1,2);
    for(int &ele:segmentTree){
        cout<<ele<<" ";
    }
}