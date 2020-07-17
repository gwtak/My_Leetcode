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
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        sum-=root->val;
        if(!sum) res++;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return res;
    }
};