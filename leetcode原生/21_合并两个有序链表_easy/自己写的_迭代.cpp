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
        ListNode* res=NULL;
        ListNode* last=NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            res=l1;
            last=l1;
            l1=l1->next;
        }
        else{
            res=l2;
            last=l2;
            l2=l2->next;
        }
        while(l1&&l2){
            if(l1->val<=l2->val){
                last->next=l1;
                last=l1;
                l1=l1->next;
            }
            else{
                last->next=l2;
                last=l2;
                l2=l2->next;
            }
        }
        last->next=(l1)?l1:l2;
        return res;
    }
};