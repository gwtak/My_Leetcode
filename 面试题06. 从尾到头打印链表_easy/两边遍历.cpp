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
    vector<int> reversePrint(ListNode* head) {
        ListNode* p=head;
        int count=0;
        while(p){
            p=p->next;
            count++;
        }
        vector<int> res(count,0);
        p=head;
        for(int i=res.size()-1;i>=0;i--){
            res[i]=p->val;
            p=p->next;
        }
        return res;
    }
};