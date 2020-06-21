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
        if(l1==NULL&&l2==NULL) return res;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1&&l2){
            if(l1->val<l2->val){
                if(!last){
                    res=l1;
                    last=l1;
                }
                else{
                    last->next=l1;
                    last=l1;
                }
                l1=l1->next;
            }
            else{
                if(!last){
                    res=l2;
                    last=l2;
                }
                else{
                    last->next=l2;
                    last=l2;
                }
                l2=l2->next;
            }
        }
        if(l1) last->next=l1;
        else last->next=l2;
        return res;
    }
};