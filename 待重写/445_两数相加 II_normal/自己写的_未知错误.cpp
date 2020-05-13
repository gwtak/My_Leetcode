/*给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add_1=0;
        int add_2=0;
        int sum=0;
        while(l1){
            add_1=add_1*10+l1->val;
            l1=l1->next;
        }
        while(l2){
            add_2=add_2*10+l2->val;
            l2=l2->next;
        }
        sum=add_1+add_2;
        
        vector<int> tmp;
        while(sum){
            tmp.push_back(sum%10);
            sum/=10;
        }
        ListNode* pLast=NULL;
        for(int i=0;i<tmp.size();i++){
            ListNode* pNew=(ListNode*)malloc(sizeof(ListNode));
            pNew->next=pLast;
            pNew->val=tmp[i];
            pLast=pNew;
        }
        return pLast;
    }
};