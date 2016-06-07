#include <iostream>


/* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {

		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode* oddListHead = new ListNode(0);
		ListNode* evenListHead = new ListNode(0);

		ListNode* pOddTail = oddListHead;
		ListNode* pEvenTail = evenListHead;

		ListNode* pNode = head;

		int pos = 1;
		while (pNode!=NULL)
		{
			ListNode* temp = pNode->next;
			if (pos%2!=0)
			{
				pOddTail->next = pNode;
				pOddTail = pOddTail->next;
				pOddTail->next = NULL;
			}
			else
			{
				pEvenTail->next = pNode;
				pEvenTail = pEvenTail->next;
				pEvenTail->next = NULL;
			}
			pNode = temp;
			pos++;
		}

		pOddTail->next = evenListHead->next;
		return oddListHead->next;		
	}
};


int main()
{
	Solution testCase;
	ListNode* head = new ListNode(4);
	head->next = new ListNode(4);

	testCase.oddEvenList(head);


	getchar();
	return 0;
}