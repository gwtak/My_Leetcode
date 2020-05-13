/*******************算法思想***********************
计算两个链表的差距，然后根据差，定点开始循环
比如：A[1,2,3,4,5,6,7,8],长度为8
	  B[    3,4,5,6,7,8],长度为6
两组差值为2，所以A从A[2],B从B[0]开始循环判断相交地址
*****************************************************/



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int headA_len = 0;
    	int headB_len = 0;
    	ListNode* tempA = headA;
    	ListNode* tempB = headB;
    	while(tempA)//得到A的长度headA_len
    	{
    		headA_len++;
    		tempA = tempA->next;
    	}
    	while(tempB)//得到B的长度headB_len
    	{
    		headB_len++;
    		tempB = tempB->next;
    	}
    	int dis;//差距
    	if (headB_len > headA_len)
    	{
    		dis = headB_len - headA_len;
    		while(dis)
    		{
    			headB = headB->next;
    			dis--;
    		}
    	}
    	else
    	{
    		dis = headA_len - headB_len;
    		while(dis)
    		{
    			headA = headA->next;
    			dis--;
    		}
    	}
    	while(headA && headB)
    	{
    		if (headA == headB)
    		{
    			return headA;
    		}
    		headA = headA->next;
    		headB = headB->next;
    	}
    	return NULL;
    }
};