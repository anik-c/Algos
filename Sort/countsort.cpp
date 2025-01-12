#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> countSort(vector<int> &arr)
{
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> freq(maxi + 1, 0);
    for (int &ele : arr)
    {
        freq[ele]++;
    }
    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[--freq[arr[i]]] = arr[i];
    }
    return ans;
}
int main()
{
    vector<int> arr{7, 2, 1, 5, 3, 6, 7};
    vector<int> ans = countSort(arr);
    for (int &ele : ans)
    {
        cout << ele << " ";
    }
}