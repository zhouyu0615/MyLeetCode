#include <iostream>
#include <vector>


using namespace std;

/* Definition for singly-linked list.*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *phead = head;
	    
		if (head==NULL||head->next==NULL)
		{
			return;
		}
		ListNode *pSlow, *pFast;
		pSlow = pFast = phead;

		while (pFast->next!=NULL)
		{
			pFast = pFast->next;
			if (pFast->next!=NULL)
			{
				pFast = pFast->next;
			}else
				break;
			pSlow = pSlow->next;
		}
		
		ListNode *head1, *head2;
		head1 = head;
		head2 = pSlow->next;
		pSlow->next = NULL;

		ListNode *prv, *cur,*post;
		prv = head2;
		cur = head2->next;
		prv->next = NULL;
		while (cur != NULL)
		{
			post = cur->next;
			cur->next = prv;
			prv = cur;
			cur = post;
		}

		head2 = prv;


		ListNode*p1, *p2;
		p1 = head1;
		p2 = head2;
		ListNode *tmp1, *tmp2;
		while (p2 != NULL)
		{
			tmp1 = p1->next;
			tmp2 = p2->next;

			p1->next = p2;
			p2->next = tmp1;

			p1 = tmp1;
			p2 = tmp2;
		}
	
	}
};


int main()
{

	vector<int> nums = {1, 2 };

	ListNode *head, *tail, *pNode;
	for (int i = 0; i < nums.size(); i++)
	{
		pNode = new ListNode(nums[i]);
		if (i == 0)
		{
			head = pNode;
			tail = head;
		}
		else
		{
			tail->next = pNode;
			tail = tail->next;
		}
	}

	Solution testCase;
	testCase.reorderList(head);
	getchar();
	return 0;
}