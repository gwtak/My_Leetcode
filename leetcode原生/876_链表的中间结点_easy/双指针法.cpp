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
    ListNode* middleNode(ListNode* head) {
        //快慢指针法
        ListNode* slowPoint = head;
        ListNode* fastPoint = head;
        while(fastPoint != NULL && fastPoint->next != NULL)
        {
            slowPoint = slowPoint->next;
            fastPoint = fastPoint->next->next;
        }
        return slowPoint;
    }
};