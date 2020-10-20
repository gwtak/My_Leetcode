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
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        ListNode* low=head;
        ListNode* high=head->next;
        while(low!=high&&high){
            low=low->next;
            if(high->next) high=high->next->next;
            else high=high->next;
        }
        return low==high;
    }
};