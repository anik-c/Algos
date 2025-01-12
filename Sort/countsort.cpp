#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> countSort(vector<int> &v)
{
    int maxi = *max_element(v.begin(), v.end());
    vector<int> freq(maxi + 1, 0);
    for (int &ele : v)
    {
        freq[ele]++;
    }
    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans[--freq[v[i]]] = v[i];
    }
    return ans;
}
int main()
{
    vector<int> v{7, 2, 1, 5, 3, 6, 7};
    vector<int> ans = countSort(v);
    for (int &ele : ans)
    {
        cout << ele << " ";
    }
}