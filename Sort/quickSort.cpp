#include<iostream>
#include<vector>
using namespace std;
int part(vector<int> &v,int first,int last){
    int pivot=v[last];
    int i=first-1;
    for(int j=first;j<last;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[++i],v[last]);
    return i;
}
void quickSort(vector<int> &v,int first,int last){
    if(first>=last) return;
    int par=part(v,first,last);
    quickSort(v,first,par-1);
    quickSort(v,par+1,last);
}
int main(){
    vector<int> v{15,17,10,25,33,41,3,37};
    quickSort(v,0,v.size()-1);
    for(int &ele:v){
        cout<<ele<<" ";
    }
}