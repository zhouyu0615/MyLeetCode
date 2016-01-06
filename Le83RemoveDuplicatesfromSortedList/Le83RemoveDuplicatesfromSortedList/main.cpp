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

		ListNode *p1, *p2;

		p1 =head;
		if (head==NULL)
		{
			return head;
		}
		p2 = head->next;

		while (p2!=NULL)
		{
			if (p1->val==p2->val)
			{
				p1->next = p2->next;
				ListNode* temp = p2;
				p2 = p2->next;
				free(temp);
			}
			else
			{
				p1 = p2;
				p2 = p2->next;
			}
		}
		return head;
	}
};
