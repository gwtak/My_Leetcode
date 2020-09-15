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
    vector<string> res;
    void dfs(TreeNode* root,string path){
        if(!root->left&&!root->right){
            res.push_back(path);
            return;
        }
        if(root->left){
            string tmp=path;
            path=path+"->"+to_string(root->left->val);
            dfs(root->left,path);
            path=tmp;
        }
        if(root->right){
            string tmp=path;
            path=path+"->"+to_string(root->right->val);
            dfs(root->right,path);
            path=tmp;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        string path{to_string(root->val)};
        dfs(root,path);
        return res;
    }
};