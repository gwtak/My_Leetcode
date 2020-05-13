/*合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> tmp;
        for(int i=0;i<lists.size();i++){
            ListNode* root=lists[i];
            while(root){
                tmp.push_back(root->val);
                root=root->next;
            }
        }
        sort(tmp.begin(),tmp.end());
        ListNode* last=NULL;
        for(int i=tmp.size()-1;i>=0;i--){
            ListNode* now=new ListNode;
            now->val=tmp[i];
            now->next=last;
            last=now;
        }
        return last;
    }
};