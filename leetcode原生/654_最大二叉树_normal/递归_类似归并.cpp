/*给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 

提示：

给定的数组的大小在 [1, 1000] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
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
    TreeNode* dfs(vector<int>& nums,int left,int right){
        if(left>right) return NULL;
        int max_num=INT_MIN;
        int max_cnt=0;
        for(int i=left;i<=right;i++){
            if(nums[i]>max_num){
                max_num=nums[i];
                max_cnt=i;
            }
        }
        TreeNode* p=new TreeNode();
        p->val=max_num;
        p->left=dfs(nums,left,max_cnt-1);
        p->right=dfs(nums,max_cnt+1,right);
        return p;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};