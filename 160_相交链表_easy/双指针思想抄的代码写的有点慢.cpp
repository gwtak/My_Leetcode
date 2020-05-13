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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa=headA;
        ListNode* pb=headB;
        int time=0;
        while(pa!=NULL&&pb!=NULL){
            if(pa==pb) return pa;
            pa=pa->next;
            pb=pb->next;
            if(pa==NULL&&time<2) pa=headB,time++;
            if(pb==NULL&&time<2) pb=headA,time++;
            if(pa==NULL||pb==NULL) return 0;
        }
        return 0;
    }
};
/*********算法思想*********
A+all+B==B+all+B时相交