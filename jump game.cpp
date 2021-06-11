//problem link:https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res--;
            if(res<0)
                return false;
            if(nums[i]>res)
                res=nums[i];
        }
       return true; 
    }
    
   
};

