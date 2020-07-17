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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* i=head;
        ListNode* j=head;
        int count=0;
        while(j){
            if(count>=n+1) i=i->next;
            count++;
            j=j->next;
        }
        if(count<=n){
            if(head->next) return head->next;
            else return NULL;
        }
        i->next=i->next->next;
        return head;
    }
};