#include<iostream>
#include<vector>
using namespace std;
int binaryS(vector<int> &v,int target){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(v[mid]==target) return mid;
        else if(target<v[mid]){
            h=mid-1;
        }
        else mid+1;
    }
    return -1;
}
int main(){
    vector<int> v{3, 5, 7, 11, 12, 15, 16};
    int target=11;
    cout<<binaryS(v,target);
}