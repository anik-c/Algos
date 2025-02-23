#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void selectionSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int miniIdx=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[miniIdx]){
                miniIdx=j;
            }
        }
        swap(v[i],v[miniIdx]);
    }
}
int main(){
    vector<int> v{15,17,10,25,33,41,3,37};
    selectionSort(v);
    for(int &ele:v){
        cout<<ele<<" ";
    }
}