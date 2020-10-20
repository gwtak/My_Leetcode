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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* p=head;
        int flag=0;
        while(l1&&l2){
            int sum=l1->val+l2->val+flag;
            p->next=new ListNode();
            p->next->val=sum%10;
            if(sum>=10) flag=1;
            else flag=0;
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+flag;
            p->next=new ListNode();
            p->next->val=sum%10;
            if(sum>=10) flag=1;
            else flag=0;
            l1=l1->next;
            p=p->next;
        }
        while(l2){
            int sum=l2->val+flag;
            p->next=new ListNode(); 
            p->next->val=sum%10;
            if(sum>=10) flag=1;
            else flag=0;
            l2=l2->next;
            p=p->next;
        }
        while(flag){
            p->next=new ListNode();
            p->next->val=1;
            flag=0;
        }
        return head->next;
    }
};