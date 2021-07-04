//problem link:https://leetcode.com/problems/all-possible-full-binary-trees/

class Solution {
public:
    unordered_map<int,vector<TreeNode *>>dp;
    vector<TreeNode *> helper(int n){
        vector<TreeNode *>res;
        if(n==0){
            TreeNode *temp = NULL;
            res.push_back(temp);
            return res;
        }
        if(n==1){
            res.push_back(new TreeNode(0));
        }
        if(dp.find(n)!=dp.end()) return dp[n];
        for(int i = 1;i<n-1;i+=2){
            auto left = helper(i);
            auto right = helper(n-i-1);
            for(auto &l : left){
                for(auto &r : right){
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            } 
        }
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};
