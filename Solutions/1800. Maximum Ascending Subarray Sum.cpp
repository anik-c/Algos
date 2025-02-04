class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=nums[0];
        int ans=maxi;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                ans+=nums[i];
            }
            else{
                maxi=max(ans,maxi);
                ans=nums[i];
            }
        }
        return max(maxi,ans);
    }
};