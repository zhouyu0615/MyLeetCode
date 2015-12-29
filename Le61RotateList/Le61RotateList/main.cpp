#include <iostream>

using namespace std;



// Definition for singly-linked list//
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* pFake = new ListNode(0);
		pFake->next = head;

		if (head==NULL||head->next==NULL||k==0)
		{
			return head;
		}

		ListNode* p1 = pFake;
		ListNode* pEnd = head;

		int length = 0;
		while (pEnd!=NULL)
		{
			pEnd = pEnd->next;
			length++;
		}

		if ((k%length)!=0)
		{
			k = k % length;
		}
		pEnd = head;
		int countStep = 0;
		while (pEnd->next != NULL)
		{
			pEnd = pEnd->next;
			countStep++;
			if (countStep>=k)
			{
				p1 = p1->next;
			}
		}


		pFake->next = p1->next;	
		if (p1!=pFake)
		{
			p1->next = NULL;
			pEnd->next = head;
		}	
		

		return pFake->next;
	}
};


int main()
{


	getchar();
	return 0;
}