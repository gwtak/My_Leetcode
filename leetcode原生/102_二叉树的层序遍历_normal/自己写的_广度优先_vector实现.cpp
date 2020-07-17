/*给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
//push_back()之后，内存的重新分配导致迭代器失效
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> q;
        q.push_back(root);
        int i=0;
        int j=1;
        while(i!=j){
            vector<int> tmp;
            while(i!=j){
                tmp.push_back(q[i]->val);
                if(q[i]->left) q.push_back(q[i]->left);
                if(q[i]->right) q.push_back(q[i]->right);
                i++;
            }
            res.push_back(tmp);
            j=q.size();
        }
        return res;
    }
};