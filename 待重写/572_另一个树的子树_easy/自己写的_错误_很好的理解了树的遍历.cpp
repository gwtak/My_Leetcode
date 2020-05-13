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
    void first_trav(vector<int>& trav,TreeNode* root){//先序
        if(!root) return;
        else{
            trav.push_back(root->val);//放在最前面就是先序遍历，放在中间就是中序遍历，放在后面就是后序遍历
            first_trav(trav,root->left);
            first_trav(trav,root->right);
        }
    }
    void mid_trav(vector<int>& trav,TreeNode* root){//中序
        if(!root) return;
        else{
            mid_trav(trav,root->left);
            trav.push_back(root->val);//放在最前面就是先序遍历，放在中间就是中序遍历，放在后面就是后序遍历
            mid_trav(trav,root->right);
        }
    }
    void last_trav(vector<int>& trav,TreeNode* root){//后序
        if(!root) return;
        else{
            last_trav(trav,root->left);
            last_trav(trav,root->right);
            trav.push_back(root->val);//放在最前面就是先序遍历，放在中间就是中序遍历，放在后面就是后序遍历
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<int> first_trav_s;
        vector<int> first_trav_t;
        first_trav(first_trav_s,s);
        first_trav(first_trav_t,t);
        int flag_first=0;
        for(int i=0;i<=first_trav_s.size()-first_trav_t.size();i++){
            if(first_trav_s[i]==first_trav_t[0]){
                for(int j=0;j<first_trav_t.size();j++){
                    if(first_trav_s[i+j]!=first_trav_t[j]) break;
                    if(j==first_trav_t.size()-1) flag_first=1;
                }
            }
        }
        vector<int> mid_trav_s;
        vector<int> mid_trav_t;
        mid_trav(mid_trav_s,s);
        mid_trav(mid_trav_t,t);
        int flag_mid=0;
        for(int i=0;i<=mid_trav_s.size()-mid_trav_t.size();i++){
            if(mid_trav_s[i]==mid_trav_t[0]){
                for(int j=0;j<mid_trav_t.size();j++){
                    if(mid_trav_s[i+j]!=mid_trav_t[j]) break;
                    if(j==mid_trav_t.size()-1) flag_mid=1;
                }
            }
        }
        vector<int> last_trav_s;
        vector<int> last_trav_t;
        last_trav(last_trav_s,s);
        last_trav(last_trav_t,t);
        int flag_last=0;
        for(int i=0;i<=last_trav_s.size()-last_trav_t.size();i++){
            if(last_trav_s[i]==last_trav_t[0]){
                for(int j=0;j<last_trav_t.size();j++){
                    if(last_trav_s[i+j]!=last_trav_t[j]) break;
                    if(j==last_trav_t.size()-1) flag_last=1;
                }
            }
        }
        return (flag_first&&flag_mid&&flag_last);
    }
};