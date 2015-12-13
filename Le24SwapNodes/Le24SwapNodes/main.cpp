#include <iostream>


using namespace std;



/*
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p , *p1, *p2;

		ListNode* fake = new ListNode(0);

		fake->next = head;
		p = fake;
		p1 = head;
		if (head==NULL)
		{
			return head;
		}
		p2 = head->next;
		while (p2!=NULL)
		{
			p1->next = p2->next;
			p2->next = p1;
			p->next = p2;

			p = p1;
			p1 = p1->next;
			if (p1==NULL)
			{
				break;
			}
			p2 = p1->next;		
		}
		return fake->next;
	}
};



int main()
{


	return 0;
}