/*
1、证明快慢指针一定能追上，快指针不会跳过慢指针
	(1)、运动和静止是相对的：设慢指针为参照物，则快指针每轮前进1步，则必定追赶上且不会跳跃
	(2)、快指针在环内永远是在追赶慢指针，每轮追赶的距离为1(2-1)，则必定追赶上且不会跳跃
	(3)、举例：
		距离		追赶次数
		1			1
		2			2
		3			3

2、证明快慢指针的距离公式
	(1)、设快指针走过的距离为fast，慢指针的距离为slow，得到fast=2*slow
	(2)、设非环的长度为a，环的长度为b，当慢指针刚入环，则快指针距离慢指针为b-a,需要经过b-a轮才能追赶上
	(3)、当两者重叠得到2*(b-a)-(b-a)=n*b，2*(b-a):快指针所经过的距离,(b-a):慢指针所经过的距离,n*b:两者重叠fast-slow必定是环的倍数
	(4)、得到slow=n*b,fast=2*n*b
	
3、计算入口节点的位置
	(1)、当距离为a+n*b时，指针必定指向入口节点，则当slow与fast相遇再前进a，就是入口节点
	(2)、当slow与fast相遇，fast从head启动，slow和fast都前进1步，当两者重叠就是入口节点
*/
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&slow!=fast){
            slow=slow->next;
            if(fast->next) fast=fast->next->next;
            else fast=NULL;
        }
        if(!fast) return NULL;
        fast=head;
        slow=slow->next;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};