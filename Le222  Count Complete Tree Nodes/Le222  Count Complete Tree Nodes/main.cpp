#include <iostream>
#include <math.h>

using namespace std;



/** Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {

		if (root==0)
		{
			return 0;
		}

		int leftNum = GetLeftNodes(root);
		int rightNum = GetRightNodes(root);
		if (leftNum==rightNum)
		{
			return pow(2,leftNum) - 1;
		}
		else
		{
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}
private:
	int GetLeftNodes(TreeNode* TNode)
	{
		int count = 0;
		while (TNode!=NULL)
		{
			TNode = TNode->left;
			count++;
		}
		return count;
	}

	int GetRightNodes(TreeNode* TNode)
	{
		int count = 0;
		while (TNode != NULL)
		{
			TNode = TNode->right;
			count++;
		}
		return count;
	}
};




int main()
{

	getchar();
	return 0;
}