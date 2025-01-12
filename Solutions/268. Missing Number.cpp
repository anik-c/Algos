/*
      Approach is just only one number is not present in the range we can get the sum of n numbers and total sum of the vector elements.
      Answer will be the sum of n number minus total sum of the vector elements.
      Time Complexity : O(n)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumofNnumbers=(nums.size()*(nums.size()+1))/2;
        int sumofele=0;
        for(int ele:nums){
            sumofele+=ele;
        }
        return (sumofNnumbers-sumofele);
    }
};
