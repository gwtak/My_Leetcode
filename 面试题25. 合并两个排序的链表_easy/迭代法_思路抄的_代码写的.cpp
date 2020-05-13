/*输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000

注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* pre;
        if(l1==NULL&&l2==NULL) return head;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val) head=l1,l1=l1->next;
        else head=l2,l2=l2->next;
        pre=head;
        while(l1&&l2){
            if(l1->val<=l2->val){
                pre->next=l1;
                pre=l1;
                l1=l1->next;
            }
            else{
                pre->next=l2;
                pre=l2;
                l2=l2->next;
            }
        }
        if(l1==NULL) pre->next=l2;
        else pre->next=l1;
        return head;
    }
};