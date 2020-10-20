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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode();
        res->next=head;
        ListNode* last=res;
        while(head&&head->next){
            ListNode* tmp=head->next->next;
            last->next=head->next;
            head->next->next=head;
            head->next=tmp;
            last=head;
            head=tmp;
        }
        return res->next;
    }
};