#include <iostream>
#include <vector>


using namespace std;

/* Definition for a binary tree node.*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isBalanced(TreeNode* root) {

		if (root == NULL)
		{
			return true;
		}

		int depthOfLeft = GetDepth(root->left, 1);
		int depthOfRigth = GetDepth(root->right, 1);

		if (abs(depthOfLeft-depthOfRigth)>1)
		{
			return false;
		}
		else
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}

private:
	int GetDepth(TreeNode* TNode,int CureentDepth)
	{
		if (TNode==NULL)
		{
			return CureentDepth;
		}

		int leftDepth = GetDepth(TNode->left, CureentDepth + 1);
		int rightDepth = GetDepth(TNode->right, CureentDepth + 1);

		return  leftDepth > rightDepth ? leftDepth : rightDepth;
	}
};



class Solution2 {
public:
	bool isBalanced(TreeNode* root) {

		if (CheckNode(root)==-1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
public:
	int CheckNode(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return 0;
		}

		int left = CheckNode(TNode->left);

		if (left==-1)
		{
			return -1;
		}

		int right = CheckNode(TNode->right);
		if (right==-1)
		{
			return -1;
		}


		if (abs(left-right)>1)
		{
			return -1;
		}
		return (left > right ? left : right) + 1;
	}
};




int main()
{
	TreeNode *root = new TreeNode(1);
	
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);

	Solution2 testCase;
	cout << testCase.isBalanced(root);

	
	getchar();
	
	delete root;
	return 0;
}