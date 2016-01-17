#include <iostream>


using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
	
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {

		ListNode *pSlow, *pFast;
		pSlow = head;
		pFast = head;

		while (pFast!=NULL)
		{
			if (pFast->next==NULL)
			{
				return NULL;
			}

			pFast = pFast->next->next;
			pSlow = pSlow->next;
			
			if (pFast==NULL)
			{
				return NULL;
			}

			if (pSlow==pFast)  //ÓÐ»·//
			{
				break; 
			}
		}

		pSlow = head;
		while (pSlow != pFast)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
		}
		return pSlow;
	}
};

int main()
{

	getchar();
	return 0;
}