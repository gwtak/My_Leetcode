/*给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
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
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);//两个root可以判断无内容情况[]，但会增加一倍的复杂度
    }
    bool ismirror(TreeNode* pleft,TreeNode* pright){
        if((pleft==NULL)&&(pright==NULL)) return true;
        if((pleft==NULL)||(pright==NULL)) return false;
        return (pleft->val==pright->val)&&ismirror(pleft->left,pright->right)&&ismirror(pright->left,pleft->right);
    }
    
};