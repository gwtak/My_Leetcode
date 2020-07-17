/*给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
//low和high部分有所参考
//针对[10,5,15,null,null,6,20]类似情况
class Solution {
public:
    bool helper(TreeNode* root,long long low,long long high){
        if(!root) return true;
        if(root->left){
            if(root->left->val<root->val&&root->left->val>low&&root->left->val<high){
                bool tmp=helper(root->left,low,root->val);
                if(!tmp) return false;
            }
            else return false;
        }
        if(root->right){
            if(root->right->val>root->val&&root->right->val>low&&root->right->val<high){
                bool tmp=helper(root->right,root->val,high);
                if(!tmp) return false;
            }
            else return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};