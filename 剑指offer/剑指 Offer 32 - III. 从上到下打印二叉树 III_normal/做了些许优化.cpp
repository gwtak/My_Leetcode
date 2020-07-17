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
            int length=tree.size();
            vector<int> nums;
            if(flag){
                for(int i=0;i<length;i++){
                    TreeNode* node=tree.front();
                    tree.pop_front();
                    nums.push_back(node->val);
                    if(node->left) tree.push_back(node->left);
                    if(node->right) tree.push_back(node->right);
                }
                flag=0;
            }
            else{
                for(int i=0;i<length;i++){
                    TreeNode* node=tree.back();
                    tree.pop_back();
                    nums.push_back(node->val);
                    if(node->right) tree.push_front(node->right);
                    if(node->left) tree.push_front(node->left);
                }
                flag=1;
            }
            res.push_back(nums);
        }
        return res;
    }
};