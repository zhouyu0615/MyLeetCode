#include <iostream>
#include <vector>

using namespace std;


/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* pFirst = new ListNode(0);
		ListNode* pSecond = pFirst;
		ListNode* fake = pFirst;
		pFirst->next = head;

		int i = 1;
        while (pFirst->next!=NULL)
        {
			pFirst = pFirst->next;
			if (i>n)
			{
				pSecond = pSecond->next;
			}
			i++;
        }

		pSecond->next = pSecond->next->next;
		return fake->next;
	}
};




int main()
{
	Solution test;


	getchar();
	return 0;
}
