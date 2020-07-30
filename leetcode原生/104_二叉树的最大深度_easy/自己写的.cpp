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
    int res=0;
    void dfs(TreeNode* root,int depth){
        if(!root) res=max(depth,res);
        else{
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
        }
    }
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};