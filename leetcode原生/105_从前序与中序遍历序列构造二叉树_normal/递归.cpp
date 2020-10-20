/*根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* _buildTree(vector<int>& preorder,int& cnt,vector<int>& inorder,int left,int right){
        if(left>right||cnt<0){
            cnt--;
            return NULL;
        }
        int tmp=-1;
        for(int i=left;i<=right;i++){
            if(preorder[cnt]==inorder[i]){
                tmp=i;
                break;
            }
        }
        TreeNode* p=new TreeNode();
        p->val=inorder[tmp];
        p->left=_buildTree(preorder,++cnt,inorder,left,tmp-1);
        p->right=_buildTree(preorder,++cnt,inorder,tmp+1,right);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cnt=0;
        return _buildTree(preorder,cnt,inorder,0,inorder.size()-1);
    }
};