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
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL) return head;
        ListNode* pre=NULL;
        ListNode* now=head;
        while(head)
        {
            now = head;
            head = head->next;
            now->next = pre;
            pre = now;
        }
        return now;
    }
};