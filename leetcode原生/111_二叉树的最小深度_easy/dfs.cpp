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
    int res=INT_MAX;
    void dfs(TreeNode* root,int level){
        level++;
        if(!root->left&&!root->right){
            res=min(res,level);
            return;
        }
        if(root->left) dfs(root->left,level);
        if(root->right) dfs(root->right,level);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        return res;
    }
};