//problem link:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    unordered_map<int, int> umap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0, i=0, j=inorder.size()-1;
        for(int i=0;i<inorder.size();++i)
        {
            umap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, preIndex, i, j);
    }
    
    TreeNode* buildTreeHelper(vector<int>& pre, vector<int>& in, int& preIndex, int i, int j) {
        TreeNode *node;
        
        if(i<=j && preIndex < pre.size())
        {
            node = new TreeNode(pre[preIndex++]);
            int rootIndex;
            rootIndex = findRootIndexInInorder(node->val);
            
            if(i<rootIndex)
            {
                node->left = buildTreeHelper(pre, in, preIndex, i, rootIndex-1);
            }
            if(j>rootIndex)
            {
                node->right = buildTreeHelper(pre, in, preIndex, rootIndex+1, j);
            }
        }
        return node;
    }
    
    int findRootIndexInInorder(int val)
    {
        return umap.find(val)->second;
    }
};
