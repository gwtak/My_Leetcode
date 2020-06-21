/*我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> path;
        int pos = 0;
        while (pos < S.size()) {
            int level = 0;
            while (S[pos] == '-') {
                ++level;
                ++pos;
            }
            int value = 0;
            while (pos < S.size() && isdigit(S[pos])) {
                value = value * 10 + (S[pos] - '0');
                ++pos;
            }
            TreeNode* node = new TreeNode(value);
            if (level == path.size()) {
                if (!path.empty()) {
                    path.top()->left = node;
                }
            }
            else {
                while (level != path.size()) {
                    path.pop();
                }
                path.top()->right = node;
            }
            path.push(node);
        }
        while (path.size() > 1) {
            path.pop();
        }
        return path.top();
    }
};
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/solution/cong-xian-xu-bian-li-huan-yuan-er-cha-shu-by-leetc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/