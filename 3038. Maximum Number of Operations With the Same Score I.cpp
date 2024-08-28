/*
  
 Check the pairs with sum equal to nums[0]+nums[1]. If a pair doen't satisfy the condition return the sum.
 Time Complexity:O(n)
      

*/

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = nums[0] + nums[1];
        int score = 1;
        int i = 2;
        int j = 3;
        while (j < nums.size()) {
            if (nums[i] + nums[j] == ans) {
                score++;
            }
            else
            break;
            i += 2;
            j += 2;
        }
        return score;
    }
};
