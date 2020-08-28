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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>(NULL);
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                if(i==len-1) res.push_back(tmp->val);
            }
        }
        return res;
    }
};