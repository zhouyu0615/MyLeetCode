#include <iostream>


/**Definition for singly-linked list.*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void deleteNode(ListNode* node) {

		if (node==NULL||node->next==NULL)
		{
			return;
		}
		ListNode *NextNode = node->next;
		node->val = NextNode->val;
		node->next = NextNode->next;

		free(NextNode);	
	}
};