/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> arr;
    int site=0;
    BSTIterator(TreeNode* root) {
        dfs(root);
        //sort(arr.begin(),arr.end());
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        return arr[site++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return site<arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */