/*给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return (vector<vector<int>>)NULL;
        vector<vector<int>> reverse;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int QueueSize=q.size();
            vector<int> reverse_tmp;
            for(int i=0;i<QueueSize;i++){
                TreeNode* tmp=q.front();
                q.pop();
                reverse_tmp.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            reverse.push_back(reverse_tmp);
        }
        vector<vector<int>> res;
        for(int i=reverse.size()-1;i>=0;i--){
            res.push_back(reverse[i]);
        }
        return res;
    }
};