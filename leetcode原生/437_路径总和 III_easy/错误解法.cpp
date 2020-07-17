/*给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
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
    //这种解法，会导致在一条支路上的解多次扫描
    int res=0;
    int real_sum=0;
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        sum=sum-root->val;
        if(!sum) res++;
        else{
            dfs(root->left,sum);
            dfs(root->right,sum);
        }
        dfs(root->left,real_sum);
        dfs(root->right,real_sum);
    }
    int pathSum(TreeNode* root, int sum) {
        real_sum=sum;
        dfs(root,sum);
        return res;
    }
};