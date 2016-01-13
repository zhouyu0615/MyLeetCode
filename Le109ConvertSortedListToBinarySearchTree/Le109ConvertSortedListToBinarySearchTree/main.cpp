#include <iostream>
#include <vector>


using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/*Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {

		if (head==NULL)
		{
			return NULL;
		}

		vector<TreeNode*> TreeNodes;
		ListNode* p1 = head;

		while (p1!=NULL)
		{
			TreeNode* TNode = new TreeNode(p1->val);
			TreeNodes.push_back(TNode);
			p1 = p1->next;
		}
		return GenBST(0, TreeNodes.size() - 1, TreeNodes);
	}

private:
	TreeNode* GenBST(int left, int right, vector<TreeNode*> &TreeNodes)
	{

		if (left>right)
		{
			return NULL;
		}
		else if (left==right)
		{
			return TreeNodes[left];
		}
		else
		{
			int mid = (left + right) / 2;
			TreeNodes[mid]->left = GenBST(left, mid - 1, TreeNodes);
			TreeNodes[mid]->right = GenBST(mid + 1, right, TreeNodes);
			return TreeNodes[mid];
		}
	}

};

