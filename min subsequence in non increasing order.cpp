//problem link:https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        {
        
        sort(nums.begin(),nums.end());
        int total=0,sum=0;
        
        
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        
        
        vector<int>ans;
        
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            ans.push_back(nums[i]);
            if(sum>total-sum)
            {
                break;
            }
        }
        return ans;
    }
    }
};
