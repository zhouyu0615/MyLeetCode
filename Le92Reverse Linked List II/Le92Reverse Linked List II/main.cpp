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
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		
		ListNode* fake = new ListNode(0);
		fake->next = head;
		ListNode *pNode,*preStart,*postEnd;
		pNode = fake;
		preStart = fake;
		while (pNode!=NULL)
		{

			if (m == 1)
			{
				preStart = pNode;
				startNode = pNode->next;
			}
			if (n==0)
			{
				endNode = pNode;
				postEnd = pNode->next;
				break;
			}
			m--;
			n--;
			pNode = pNode->next;

		}

		reverseList();

		preStart->next =startNode ;
		endNode->next = postEnd;
		
		return fake->next;
	}

private:

	ListNode *startNode, *endNode;
	void reverseList() {
		if (startNode == endNode || startNode->next == endNode->next)
		{
			return;
		}
		ListNode *restHead, *Pre, *Cur;
		Pre = startNode;
		Cur = startNode->next;
		restHead = startNode->next->next;
		Pre->next = NULL;

		while (restHead != endNode->next)
		{
			Cur->next = Pre;
			Pre = Cur;
			Cur = restHead;
			restHead = restHead->next;
		}

		Cur->next = Pre;
	    
		endNode = startNode;
		startNode = Cur;
	}
};


class Solution2 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head)   return NULL;
		ListNode* fake = new ListNode(0), *cur;
		fake->next = head;
		cur = fake;
		for (int i = 0; i < m - 1; i++){
			cur = cur->next;
		}
		reverseList(cur, n - m + 1);
		return fake->next;
	}

	void reverseList(ListNode* head, int k){
		ListNode* start = head->next, *cur = start->next, *temp;
		int i = 1;
		while (i < k){
			i++;
			start->next = cur->next;
			temp = head->next;
			head->next = cur;
			cur->next = temp;
			cur = start->next;
		}
		return;
	}
};


int main()
{

	vector<int> nums = { 3,5};

	ListNode *head,*tail, *pNode;
	for (int i = 0; i < nums.size();i++)
	{
		pNode = new ListNode(nums[i]);
		if (i==0)
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
	testCase.reverseBetween(head, 1, 1);
	getchar();
	return 0;
}
