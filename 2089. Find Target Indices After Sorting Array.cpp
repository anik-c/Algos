/* 
 Simple Approach first sort the array and check the indices of the element and push it in the vector and return the vector.
 Time Complexity:O(nlogn)
*/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
