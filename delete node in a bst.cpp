//problem link:https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        
        if (root->val == key){
            if(root->left == NULL)  return root->right;
            if(root->right == NULL) return root->left;
            if(root->right!=NULL && root->left!=NULL){
                TreeNode *temp = root->right;
                while(temp->left!=NULL) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right,root->val);
                
            }
        }
        else{
            if (root->val>key)  root->left = deleteNode(root->left,key);
            else    root->right = deleteNode(root->right,key);
        }
        return root;
    }
};
