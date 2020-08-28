/*给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
    vector<string> res;
    void tracer(TreeNode* root,string path){
        path+="->"+to_string(root->val);
        if(!root->left&&!root->right){
            res.push_back(path);
            return;
        }
        if(root->left) tracer(root->left,path);
        if(root->right) tracer(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        string tmp;
        tmp+=to_string(root->val);
        if(!root->left&&!root->right) res.push_back(tmp);
        if(root->left) tracer(root->left,tmp);
        if(root->right) tracer(root->right,tmp);
        return res;
    }
};