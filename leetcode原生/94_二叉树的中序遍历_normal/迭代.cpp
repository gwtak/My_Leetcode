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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root){
            st.push(root);
            root=root->left;
        }
        while(!st.empty()){
            TreeNode* p=st.top();
            st.pop();
            res.push_back(p->val);
            p=p->right;
            while(p){
                st.push(p);
                p=p->left;
            }
        }
        return res;
    }
};