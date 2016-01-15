#include <iostream>


using namespace std;


/* Definition for a binary tree node*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {

		target = sum;
		DfsFind(root, 0);

		return result;

	}

private:
	int target = 0;
	bool result = false;

	void DfsFind(TreeNode* TNode,int addSum)
	{

		if (result||TNode==NULL)
		{
			return;
		}
		int sum = addSum + TNode->val;
		if (TNode->left==NULL&&TNode->right==NULL&&sum==target)
		{
			result = true;
			return;
		}

		if (TNode->left!=NULL)
		{
			DfsFind(TNode->left, sum);
		}
		if (TNode->right!=NULL)
		{
			DfsFind(TNode->right, sum);
		}
	}
};


int main()
{

	getchar();
	return 0;
}

