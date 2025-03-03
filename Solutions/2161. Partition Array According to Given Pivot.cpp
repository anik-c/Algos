class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            /* 1st Approach
           vector<int> less;
           vector<int>equal;
           vector<int> greater;
           for(int &ele:nums){
            if(ele>pivot){
                greater.push_back(ele);
            }
            else if(ele<pivot){
                less.push_back(ele);
            }
            else{
                equal.push_back(ele);
            }
           }
           for(int &ele:equal){
            less.push_back(ele);
           }
           for(int &ele:greater){
            less.push_back(ele);
           }
           return less;
           */
    
        /* 2nd Approach
        int lessCount=0;
        int equalCount=0;
        for(int &ele:nums){
            if(ele<pivot) lessCount++;
            if(ele==pivot) equalCount++;
        }
        equalCount+=lessCount;
        int j=nums.size();
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<pivot && lessCount>=0){
                ans[--lessCount]=nums[i];
            }
            else if(nums[i]==pivot){
                ans[--equalCount]=nums[i];
            }
            else
            ans[--j]=nums[i];
        }
        return ans;
        */
        /* 3rd Approach
        vector<int> ans(nums.size());
        int i=0;
        int j=nums.size()-1;
        int left=0;
        int right=nums.size()-1;
        while(i<nums.size() &&j>=0){
            if(nums[i]<pivot){
                ans[left++]=nums[i];
            }
            if(nums[j]>pivot){
                ans[right--]=nums[j];
            }
            i++;
            j--;
        }
        while(left<=right){
            ans[left++]=pivot;
        }
        return ans;
        */
        }
    
    };