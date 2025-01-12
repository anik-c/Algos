/* Approach is iterating through each element and check absolute difference with every element of array if checks true increment the count by 1 and after checking all the element in the array return the count.
  Time Complexity:O(n^2) */



class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])==k) count++;
            }
        }
        return count;
    }
};
