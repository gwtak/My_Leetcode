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
    vector<int> tree;
    void in_order(TreeNode* root){
        if(!root) return;
        in_order(root->left);
        tree.push_back(root->val);
        in_order(root->right);
    }
    bool isValidBST(TreeNode* root) {
        in_order(root);
        for(int i=1;i<tree.size();i++){
            if(tree[i]<=tree[i-1]) return 0;
        }
        return 1;
    }
};