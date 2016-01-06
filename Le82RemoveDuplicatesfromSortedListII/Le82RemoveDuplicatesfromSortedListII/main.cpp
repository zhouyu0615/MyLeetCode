#include <iostream>


/* Definition for singly-linked list.*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* fake = new ListNode(0);

		fake->next = head;

		ListNode *p1, *p2,*tail;
		p1 = head;
		tail = fake;

		if (head==NULL)
		{
			return head;
		}
		p2 = head->next;

		while (p2!=NULL)
		{
			if (p1->val==p2->val)
			{
				while (p1->val == p2->val)
				{
					p2 = p2->next;
					if (p2==NULL)
					{
						tail->next = NULL;
						return fake->next;
					}
				}
				p1 = p2;
				p2 = p2->next;

			}
			else
			{
				tail->next = p1;
				tail = p1;
				p1 = p2;
				p2 = p2->next;
			}
		
		}

		tail->next = p1;
		return fake->next;
	}
};