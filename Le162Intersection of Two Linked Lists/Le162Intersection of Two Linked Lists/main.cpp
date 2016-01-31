#include <iostream>
#include <vector>


using namespace std;

/*Definition for singly-linked list.*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		ListNode *pA = headA;
		ListNode *pB = headB;

		if (headA==NULL||headB==NULL)
		{
			return NULL;
		}
		int lenA = 1;
		while (pA->next!=NULL)
		{
			lenA++;
			pA = pA->next;
		}
		int lenB = 1;
		while (pB->next!=NULL)
		{
			lenB++;
			pB = pB->next;
		}
		if (pA!=pB)
		{
			return NULL;
		}

		int diff = abs(lenA - lenB);

		ListNode* s = lenA <= lenB ? headA : headB;
		ListNode* l = lenA > lenB ? headA : headB;

		while (diff--)
		{
			l = l->next;
		}

		while (l!=s)
		{
			l = l->next;
			s = s->next;
		}

		return s;
	}
};


ListNode* CreateLinkList(vector<int>& nums)
{
	ListNode* head, *tail;

	head = tail = new ListNode(nums[0]);
	
	for (int i = 1; i < nums.size();i++)
	{
		tail->next = new ListNode(nums[i]);
		tail = tail->next;
	}

	return head;
}

int main()
{
	vector<int> listA = { 1 };
	vector<int> listB = { 1, 2, 3, 4, 5 };

	
	ListNode *headB = CreateLinkList(listB);
	ListNode* headA = headB;

	Solution testCase;
	
	testCase.getIntersectionNode(headA, headB);

	getchar();
	return 0;
}