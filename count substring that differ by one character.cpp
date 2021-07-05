//problem link:https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

class Solution {
public:
    int countSubstrings(string s, string t) {
       int ans = 0;
        int m = s.size(), n = t.size();
		
        vector<vector<int>> f(m + 1, vector<int>(n + 1));  
	
        auto g = f;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
			
                if (s[i-1] == t[j-1]) {
                    g[i][j] = g[i-1][j-1] + 1; 
                    f[i][j] += f[i-1][j-1]; 
                }
                else {
                    f[i][j] += g[i-1][j-1] + 1; 
                    
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};
