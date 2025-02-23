#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int current=v[i];
        int j=i-1;
        while(j>=0 && v[j]>current){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current;
    }
}
int main(){
    vector<int> v{15,17,10,25,33,41,3,37};
    insertionSort(v);
    for(int &ele:v){
        cout<<ele<<" ";
    }
}