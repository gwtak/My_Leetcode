/*给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
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
    int max=0;
	//搜索最深深度
    int maxdeep(TreeNode* root){
        int tmp1=0;
        int tmp2=0;
        if(!root) return 0;
        if(root->left) tmp1=maxdeep(root->left);
        if(root->right) tmp2=maxdeep(root->right);
        return tmp1>tmp2?tmp1+1:tmp2+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int tmp1=0;
        int tmp2=0;
        if(root){
            if(root->left){
                tmp1=maxdeep(root->left);
                diameterOfBinaryTree(root->left);
            }
            if(root->right){
                tmp2=maxdeep(root->right);
                diameterOfBinaryTree(root->right);
            }
        }
        max=max>(tmp1+tmp2)?max:(tmp1+tmp2);
        return max;
    }
};