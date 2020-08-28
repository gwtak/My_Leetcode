/*在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
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
 //错误：[2,1,3,null,4]，输出：6，正确输出：7
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        //F[n]=max(F[n-1],F[n-2]+a[n])
        int last_last=0;//F[n-2]
        int last=0;//F[n-1]
        queue<TreeNode*> floor;
        floor.push(root);
        while(!floor.empty()){
            int length=floor.size();
            int now=0;
            for(int i=0;i<length;i++){
                TreeNode* tmp=floor.front();
                floor.pop();
                now+=tmp->val;
                if(tmp->left) floor.push(tmp->left);
                if(tmp->right) floor.push(tmp->right);
            }
            now=max(last,last_last+now);
            last_last=last;
            last=now;
        }
        return max(last_last,last);
    }
};