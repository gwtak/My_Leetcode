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
    vector<vector<int>> res;
    void dfs(TreeNode* root,int sum,vector<int>& path){
        sum-=root->val;
        path.push_back(root->val);
        if(sum==0&&!root->left&&!root->right) res.push_back(path);
        if(root->left){
            dfs(root->left,sum,path);
            path.pop_back();
        }
        if(root->right){
            dfs(root->right,sum,path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if(!root) return res;
        dfs(root,sum,path);
        return res;
    }
};