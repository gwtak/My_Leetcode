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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* i=head;
        ListNode* j=head;
        while(j){
            if(!k){
                i=i->next;
                j=j->next;
            }
            else{
                j=j->next;
                k--;
            }
        }
        return i;
    }
};