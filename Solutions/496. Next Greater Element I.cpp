/*
      Approach: Question ask to get the next greater element right after that element of nums1 in nums2.
                We check this for every element of nums1.
                Checking from the last element to the present element if any of the element is greater than the present element we need to push it to the stack.
                And the top element is the next greater element right after the present element of nums1.

                Time Complexity:To iterate in the nums1 it is O(n) and to iterated in nums2 at worst case it is also O(n). So overall time complexity is O(n^2)
*/




class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < nums1.size(); i++) {
            int j = nums2.size() - 1;
            if (!s.empty()) {
                s.push(-1);
            }
            while (nums2[j] != nums1[i]) {
                if (nums2[j] > nums1[i]) {
                    s.pop();  // poping the top element if the element of nums2 is greater than present element.
                    s.push(nums2[j]); // pushing that element of the nums2
                }
                j--;
            }
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
