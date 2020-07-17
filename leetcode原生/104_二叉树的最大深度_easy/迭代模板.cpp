行用时为 0 ms 的范例
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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
          return 0;
        queue<TreeNode*>q;
        TreeNode *p,*r=root;
        q.push(root);
        int depth=0;
        while(!q.empty()){
             p=q.front();
             q.pop();
             if(p->left)
               q.push(p->left);
             if(p->right)
               q.push(p->right);
             if(p==r){
                 r=q.back();
                 depth++;
             }
        }
        return depth;
    }
};