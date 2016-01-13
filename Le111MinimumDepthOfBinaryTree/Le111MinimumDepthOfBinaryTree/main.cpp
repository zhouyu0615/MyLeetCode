#include <iostream>
#include <vector>



/* Definition for a binary tree node.*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int minDepth(TreeNode* root) {

	   return	GetMinDepth(root);
	}

	int GetMinDepth(TreeNode* TNode)
	{
		if (TNode == NULL)
		{
			return 0;
		}

		if ((TNode->left == NULL) && (TNode->right == NULL))
		{
			return 1;
		}else if (TNode->left==NULL)
		{
			return GetMinDepth(TNode->right) + 1;
		}else if (TNode->right==NULL)
		{
			return GetMinDepth(TNode->left) + 1;
		}
		else
		{
			int left = GetMinDepth(TNode->left);
			int right = GetMinDepth(TNode->right);

			return (left < right ? left : right) + 1;
		}
	}
};



int main()
{




	getchar();
	return 0;
}