#include <iostream>

using namespace std;

/*Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head==NULL)
		{
			return NULL;
		}
		ListNode* fake = new ListNode(0);
		fake->next = head;
		ListNode *pre, *pCur,*pTemp;

		pCur = head->next;
		pre = fake;
		pre->next->next = NULL;

		while (pCur!=NULL)
		{
			pre = fake;
			while (pre->next!=NULL&&pCur->val > pre->next->val)
			{
				pre = pre->next;
			}

			pTemp = pCur;
			pCur = pCur->next;

			pTemp->next = pre->next;
			pre->next = pTemp;			
		}

		return fake->next;
	}
};