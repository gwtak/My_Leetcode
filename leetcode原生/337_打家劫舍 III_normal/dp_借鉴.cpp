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
    int rob(TreeNode* root) {
        if(!root) return 0;
        int rob_left=0;
        int rob_right=0;
        int rob_left_left=0;
        int rob_left_right=0;
        int rob_right_left=0;
        int rob_right_right=0;
        if(root->left){
            if(root->left->left) rob_left_left=rob(root->left->left);//0
            if(root->left->right) rob_left_right=rob(root->left->right);//4
            rob_left=rob(root->left);
        }
        if(root->right){
            if(root->right->left) rob_right_left=rob(root->right->left);
            if(root->right->right) rob_right_right=rob(root->right->right);
            rob_right=rob(root->right);
        }
        return max(rob_left+rob_right,root->val+rob_left_left+rob_left_right+rob_right_left+rob_right_right);
    }
};