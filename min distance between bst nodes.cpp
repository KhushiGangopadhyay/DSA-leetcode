//problem link:https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
public:
    vector<int> v;
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
         solve(root);
        int res=INT_MAX;
        for(int i=0;i<v.size()-1;++i)
            res=min(res,abs(v[i]-v[i+1]));
        return res;
        
    }
};
