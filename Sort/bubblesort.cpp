#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main(){
    vector<int> v{15,17,10,25,33,41,3,37};
    bubbleSort(v);
    for(int &ele: v){
        cout<<ele<<" ";
    }
}