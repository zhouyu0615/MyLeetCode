#include <iostream>


using namespace std;


/* Definition for singly-linked list.*/
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode*	phead = NULL;
		ListNode*   ptail = NULL;
		ListNode*   p1 = NULL;
	

		if (l1==NULL)
		{
			return l2;
		}
		if (l2==NULL)
		{
			return l1;
		}

		while (true)
		{				
			int val = l1->val + l2->val;
	
			p1 = new ListNode(val);
			p1->next = NULL;

			if (phead==NULL)
			{
				phead = p1;
				ptail = phead;
				phead->next = NULL;
			}
			else
			{
				ptail->next = p1;
				ptail = p1;
			}	

			l1 = l1->next;
			l2 = l2->next;

			if (l1 == NULL) //L1已经到达末尾
			{
				ptail->next = l2;
				break;
			}

			if (l2==NULL)
			{
				ptail->next = l1;
				break;
			}

		}

		p1 = phead;
		while (p1!=NULL) //处理进位//
		{
			if (p1->val >= 10)
			{
				p1->val = p1->val % 10;
				if (p1->next==NULL)
				{
					p1->next = new ListNode(1);
					break;
				}
				else
				{
					p1->next->val += 1;
				}
			}
			p1 = p1->next;

		}

		return phead;
	}
	
};





class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode*	phead = new ListNode(0);
		ListNode*   ptail = phead;
		ListNode*   p1 = NULL;
		int val1 = 0, val2 = 0;
		int val = 0;

		while ((l1 != NULL) || (l2 != NULL) || (val != 0))
		{
			val1 = (l1 == NULL ? 0 : l1->val);
			val2 = (l2 == NULL ? 0 : l2->val);

			val += (val1 + val2);
			ptail->next = new ListNode(val % 10);
			val = val / 10;

			ptail = ptail->next;
			if (l1 != NULL)
			{
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				l2 = l2->next;
			}
		}
		return phead->next;
	}

};





int main()
{





	return 0;
}


