/* 
    1.First we iterate for the indices and get their set bits.
    2.countSetBit() counts you the number of set bits in your present indices.
    3.We check if the number of set bits are equal to the "K" or not, if check true the element at that indices get added to ans.
    4.Check for all the indices and return the ans;

    Time complexity:
        For iterating over each indices O(n).
        For counting the setBits O(logn).
        Overall O(n*log(n)).
*/
class Solution {
public:
    int countSetBit(int i){
        int count=0;
        while(i){
            if(i&1){ // check the current bit is set or not
                count++;
            }
            i=i>>1; // right shift the bit by 1.
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(countSetBit(i)==k){
                ans+=nums[i];
            }
        }
        return ans;
    }
};
