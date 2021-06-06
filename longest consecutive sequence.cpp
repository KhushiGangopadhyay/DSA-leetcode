//problem link:https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res=0, count=1;
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                continue;
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                res = max(res, count);
                count=1;
            }
        }
        return max(res,count);
    }
};
