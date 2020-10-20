/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int left=0;
        int right=0;
        if(!root) return 0;
        if(root->left){
            left=sumOfLeftLeaves(root->left);
            if(!root->left->left&&!root->left->right) left+=root->left->val;
        }
        if(root->right){
            right=sumOfLeftLeaves(root->right);
        }
        return left+right;
    }
};