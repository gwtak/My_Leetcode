/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3;l3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=l1,*q=l2,*r=l3;
	int flag=0;
	while(p!=NULL&&q!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));//分配一块struct ListNode内存，强制转换得到其地址，赋值给t，指针t指向struct ListNode
		t->next=NULL;
		int sum=p->val+q->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		p=p->next;q=q->next;r=r->next;
	}
	while(p!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=p->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		p=p->next;r=r->next;
	}
	while(q!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=q->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		q=q->next;r=r->next;
	}
	if(flag==1){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=flag;
		t->val=sum;
		r->next=t;
	}
	return l3->next;
}



作者：world-16
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/jia-fa-jin-wei-mo-ni-ji-suan-ji-ying-jian-de-jia-f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。