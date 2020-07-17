/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//push_back()之后，内存的重新分配导致迭代器失效
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> q;
        q.push_back(root);
        vector<TreeNode*>::iterator i=q.begin();
        vector<TreeNode*>::iterator j=q.end();
        while(i!=j){
            vector<int> tmp;
            while(i!=j){
                cout<<(*i)->val<<endl;
                tmp.push_back((*i)->val);
                cout<<(*i)->val<<endl;
                if((*i)->left) q.push_back((*i)->left);
                cout<<(*i)->val<<endl;
                if((*i)->right) q.push_back((*i)->right);
                cout<<4<<endl;
                i++;
            }
            res.push_back(tmp);
            j=q.end();
        }
        return res;
    }
};