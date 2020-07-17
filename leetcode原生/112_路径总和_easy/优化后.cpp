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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        sum-=root->val;
        if(!root->left&&!root->right){
            if(!sum) return 1;
            else return 0;
        }
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    }
};