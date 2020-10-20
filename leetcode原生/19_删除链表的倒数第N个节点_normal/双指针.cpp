/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res=new ListNode();
        res->next=head;
        ListNode* low=res;
        ListNode* fast=res;
        n++;
        while(fast&&n--) fast=fast->next;
        while(fast){
            low=low->next;
            fast=fast=fast->next;
        }
        low->next=low->next->next;
        return res->next;
    }
};