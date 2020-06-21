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
        ListNode* last=NULL;
        ListNode* now=head;
        while(now){
            ListNode* tmp=now->next;
            now->next=last;
            last=now;
            now=tmp;
        }
        return last;
    }
};