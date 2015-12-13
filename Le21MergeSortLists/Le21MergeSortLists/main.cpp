#include <iostream>





/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode *p1, *p2,*tail;

		ListNode *fake=new ListNode(0);
		fake->next = NULL;
		tail = fake;
		
		p1 = l1;
		p2 = l2;
		
		while (true)
		{
			if (p1==NULL)
			{
				tail->next = p2;
				tail = p2;
				break; 
			}

			if (p2==NULL)
			{
				tail->next = p1;
				tail = p1;
				break;
			}

			if (p1->val <= p2->val)
			{
				tail->next = p1;
				tail = p1;
				p1 = p1->next;
			}
			else
			{
				tail->next = p2;
				tail = p2;
				p2 = p2->next;
			}
		}

		return fake->next;
	}
};






int main()
{

}


