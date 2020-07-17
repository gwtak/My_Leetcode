/*迭代法*/
struct TreeNode* searchBST(struct TreeNode* root, int val)
{
	struct TreeNode *cur=root;
	while(cur)
	{
		if(cur->val==val) return cur;
		else if(val>cur->val) cur=cur->right;
		else cur=cur->left;
	}
	return NULL;
 }
