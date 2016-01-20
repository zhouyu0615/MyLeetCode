#include <iostream>

/* Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {

		return mergeSort(head);
	}

private:
	ListNode* mergeSort(ListNode* head)
	{
		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode  *pFast, *pSlow;
		pFast = head->next->next;
		pSlow = head;

		while (pFast!=NULL&&pFast->next!=NULL)
		{
			pFast = pFast->next->next;
			pSlow = pSlow->next;
		}

		ListNode* right = mergeSort(pSlow->next);
		pSlow->next = NULL;
		ListNode* left = mergeSort(head);

		return merge(left, right);
	}

	ListNode* merge(ListNode *left, ListNode * right)
	{
		ListNode* fake = new ListNode(0);
		ListNode* ptail = fake;

		while (left!=NULL&&right!=NULL)
		{
			if (left->val<=right->val)
			{
				ptail->next = left;
				left = left->next;
			}
			else
			{
				ptail->next = right;
				right = right->next;
			}
			ptail = ptail->next;
		}

		if (left==NULL)
		{
			ptail->next = right;
		}
		else
		{
			ptail->next = left;
		}
		
		return fake->next;
	}

};

