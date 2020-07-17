/*请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>(NULL);
        vector<vector<int>> res;
        deque<TreeNode*> tree;
        tree.push_back(root);
        int flag=1;
        while(!tree.empty()){
            deque<TreeNode*> tmp;
            vector<int> nums;
            if(flag){
                while(!tree.empty()){
                    TreeNode* node=tree.front();
                    tree.pop_front();
                    if(node){
                        nums.push_back(node->val);
                        if(node->left) tmp.push_back(node->left);
                        if(node->right) tmp.push_back(node->right);
                    }
                }
                while(!tmp.empty()){
                    TreeNode* node=tmp.front();
                    tmp.pop_front();
                    tree.push_back(node);
                }
                flag=0;
            }
            else{
                while(!tree.empty()){
                    TreeNode* node=tree.back();
                    tree.pop_back();
                    if(node){
                        nums.push_back(node->val);
                        if(node->right) tmp.push_back(node->right);
                        if(node->left) tmp.push_back(node->left);
                    }
                }
                while(!tmp.empty()){
                    TreeNode* node=tmp.back();
                    tmp.pop_back();
                    tree.push_back(node);
                }
                flag=1;
            }
            res.push_back(nums);
        }
        return res;
    }
};