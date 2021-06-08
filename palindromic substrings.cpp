//problem link:https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
         int n = s.length();
        int ans=0;
        bool dp[n][n];
         memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)  {
            dp[i][i] = 1; 
            ans++;
        }
        for(int i=0;i<n-1;i++) 
            if(s[i]==s[i+1]) {
                dp[i][i+1] = 1; 
                ans++;
            }
        for(int len=3;len<=n;len++) {  
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])  {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
