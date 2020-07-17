/*给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
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
    vector<int> depth;
    void helper(TreeNode* root,int tmp){
        if((!root->left)&&(!root->right)) depth.push_back(tmp+root->val);
        if(root->left) helper(root->left,tmp+root->val);
        if(root->right) helper(root->right,tmp+root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        helper(root,0);
        for(int i=0;i<depth.size();i++){
            cout<<depth[i]<<endl;
            if(depth[i]==sum) return 1;
        }
        return 0;
    }
};