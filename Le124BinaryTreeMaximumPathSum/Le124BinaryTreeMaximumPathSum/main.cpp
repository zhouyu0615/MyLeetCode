#include <iostream>


/* Definition for a binary tree node.*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int maxPathSum(TreeNode* root) {

		 DfsMaxPathSum(root);
		 return MaxSum;
	}
private:
	int MaxSum=INT_MIN;

	int DfsMaxPathSum(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return 0;
		}

		int left = DfsMaxPathSum(TNode->left);
		int right = DfsMaxPathSum(TNode->right);

		int sum = TNode->val;
		if (left>0)
		{
			sum += left;
		}
		if (right>0)
		{
			sum += right;
		}
		MaxSum = max(MaxSum, sum);
	
		return max(left, right) > 0 ? max(left, right) + TNode->val : TNode->val;
	}

	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}

};
