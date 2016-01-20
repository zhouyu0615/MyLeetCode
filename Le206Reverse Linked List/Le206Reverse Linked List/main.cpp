#include <iostream>


/** Definition for singly-linked list.*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode *restHead, *Pre, *Cur;
		Pre = head;
		Cur = head->next;
		restHead = head->next->next;
		Pre->next = NULL;

		while (restHead!=NULL)
		{
			Cur->next = Pre;
			Pre = Cur;
			Cur = restHead;
			restHead = restHead->next;
		}

		Cur->next = Pre;
		return Cur;
	}
};


class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		return reverse(head, NULL);
	}

private:
	ListNode *reverse(ListNode* head, ListNode* prev)
	{
		if (head == NULL)
		{
			return prev;
		}

		ListNode *rem = head->next;
		head->next = prev;
		
		return reverse(rem, head);
	}
};

