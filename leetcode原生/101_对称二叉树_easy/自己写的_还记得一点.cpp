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
    bool dfs(TreeNode* left,TreeNode* right){
        if(!left&&!right) return 1;
        if((left&&right&&left->val!=right->val)||(left&&!right)||(!left&&right)) return 0;
        return dfs(left->right,right->left)&&dfs(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return dfs(root->left,root->right);
    }
};