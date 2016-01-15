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
	ListNode* partition(ListNode* head, int x) {
		if (head==NULL)
		{
			return head;
		}
		
		ListNode* pLowHead, *pLowTail;
		ListNode *pHighHead, *pHighTail;

		pLowHead = new ListNode(0);
		pLowTail = pLowHead;

		pHighHead = new ListNode(0);
		pHighTail = pHighHead;


		ListNode* p1;
		p1 = head;
		while (p1!=NULL)
		{
			if (p1->val<x)
			{
				pLowTail->next = p1;
				pLowTail = p1;
			}
			else
			{
				pHighTail->next = p1;
				pHighTail = p1;
			}
			p1 = p1->next;
		}

		pLowTail->next = pHighHead->next;
		pHighTail->next = NULL;
		return pLowHead->next;
	}
};


int main()
{




	getchar();
	return 0;
}
