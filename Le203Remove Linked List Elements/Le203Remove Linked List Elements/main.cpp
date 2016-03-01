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
	ListNode* removeElements(ListNode* head, int val) {
		if (head==NULL)
		{
			return head;
		}
		ListNode* pFake = new ListNode(0);
		pFake->next = head;
		ListNode *pPrv, *pCur,*pDel;
		pPrv = pFake;
		pCur = pFake->next;

		while (pCur!=NULL)
		{
			pDel = NULL;
			if (pCur->val==val)
			{
				pPrv->next = pCur->next;
				pDel = pCur;
				pCur = pCur->next;
				free(pDel);
				continue;
			}
			else
			{
				pPrv = pPrv->next;
				pCur = pCur->next;				
			}
		}
		return pFake->next;
	}
};




int main()
{

	getchar();
	return 0;
}