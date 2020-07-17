/*计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        int count=0;
        if(root==NULL)return 0;
        if(root->left!=NULL){
            if(root->left->left==NULL&&root->left->right==NULL){//终止条件，返回和
                count+=root->left->val;
            }
            if(root->left->left!=NULL||root->left->right!=NULL){//递归条件
                count+=sumOfLeftLeaves(root->left);
            }
        }
        if(root->right!=NULL){
            if(root->right->left!=NULL||root->right->right!=NULL){//递归条件，root->right->left==NULL&&root->right->right==NULL不需要任何操作
                count+=sumOfLeftLeaves(root->right);
            }
        }
        return count;
    }
};