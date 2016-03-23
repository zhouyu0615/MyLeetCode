#include <iostream>
#include <vector>

using namespace std;

/**Definition for singly-linked list.*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



class Solution {
public:
	bool isPalindrome(ListNode* head) {

		if (head==NULL)
		{
			return true;
		}

		ListNode *pNode = head;
		vector<int> Vals;
		while (pNode!=NULL)
		{
			Vals.push_back(pNode->val);
			pNode = pNode->next;
		}
		int len = Vals.size();
		int start = 0;
		int end = len - 1;
		while (start<end)
		{
			if (Vals[start]!=Vals[end])
			{
				return false;
			}
			++start;
			--end;
		}
		return true;

	}
};


class Solution2 {
public:
	bool isPalindrome(ListNode* head) {
		if (head==NULL||head->next==NULL)
		{
			return true;
		}

		ListNode *fastNode = head;
		ListNode *slowNode = head;

		while (fastNode->next!=NULL&&fastNode->next->next!=NULL)
		{
			fastNode = fastNode->next->next;
			slowNode = slowNode->next;
		}

		ListNode* phead2 = reverseList(slowNode->next);

		ListNode* phead1 = head;

		while (phead2!=NULL)
		{
			if (phead1->val!=phead2->val)
			{
				return false;
			}
			phead2 = phead2->next;
			phead1 = phead1->next;
		}
		return true;
	}

private:
	ListNode* reverseList(ListNode* head)
	{
		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		ListNode* pre = head;
		ListNode* cur = head->next;
		ListNode *pos;
		pre->next = NULL;
		while (cur!=NULL)
		{
			pos = cur->next;
			cur->next = pre;
			pre = cur;
			cur = pos;
		}
		return pre;	
	}
};

int main()
{
	vector<int> nums = { 1, 2,};

	ListNode*head;
	ListNode*p=NULL;
	for (int i = 0; i < nums.size();++i)
	{
		if (i==0)
		{
			p = new ListNode(nums[i]);
			head = p;
		}
		else
		{
			p->next = new ListNode(nums[i]);
			p = p->next;
		}	
	}


	Solution2 testCase;

	cout<<testCase.isPalindrome(head)<<endl;
	getchar();
	return 0;

}

