/*给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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
    vector<int> res;/***************************************************************************************************************
						注意变量位置
						第一次定义vector<int> res，使得函数递归时，每次声明成为局部变量，只返回第一位
						第二次定义static vector<int> res，使得容器在函数第二次调用时无法重置为空，出现在第一次末尾添加第二次的数
                    ****************************************************************************************************************/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tmp;
        if(root==NULL) return tmp;
        if(root->left==NULL) res.push_back(root->val);
        else{
            inorderTraversal(root->left);
            res.push_back(root->val);
        }
        if(root->right!=NULL) inorderTraversal(root->right);
        return res;
    }
};