/*给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1=l1;
	struct ListNode* p2=l2;
	int len1=1;
	int len2=1;
	int flag=0;
	while(l1->next){
		len1++;
		l1=l1->next;
	}
	while(l2->next){
		len2++;
		l2=l2->next;
	}
	if(len1!=len2){
            while(len1<len2){
			struct ListNode* t=(struct ListNode*)malloc(sizeof(struct ListNode));
			t->val=0;
            t->next=NULL;
			l1->next=t;
			l1=l1->next;
			len1++;
		}
		while(len1>len2){
			struct ListNode* t=(struct ListNode*)malloc(sizeof(struct ListNode));
			t->val=0;
            t->next=NULL;
			l2->next=t;
			l2=l2->next;;
			len2++;
		}
	}
    struct ListNode* l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* res=l3;
	while(p1){
		struct ListNode* p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next=NULL;
		p->val=p1->val+p2->val;
		if(flag){
			p->val++;
			flag=0;
		}
		if(p->val>=10){
			p->val=p->val%10;
			flag=1;
		}
		p1=p1->next;
		p2=p2->next;
        l3->next=p;
        l3=l3->next;
	}
    if(flag==1){
        struct ListNode* p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->val=1;
        p->next=NULL;
        l3->next=p;
    }
	return res->next;
}