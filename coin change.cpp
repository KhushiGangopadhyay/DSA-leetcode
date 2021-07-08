//problem link:https://leetcode.com/problems/coin-change/

class Solution {
public:
    //bottom up approach
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        
        for(auto c : coins)
        {
            for(int i=c;i<amount+1;i++)
            {
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
       return dp[amount]<=amount? dp[amount]:-1 ;
    }
};
