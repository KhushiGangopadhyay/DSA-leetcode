//problem link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
       for(int i=0;i<n-1;i++)
       {
             if(prices[i]<prices[i+1])
             {
                 maxprofit+=(prices[i+1]-prices[i]);
             }
       }
        return maxprofit;
    }
};
