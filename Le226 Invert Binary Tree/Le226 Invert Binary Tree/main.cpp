#include <iostream>


/** Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {


		if (root==NULL||(root->left==NULL&&root->right==NULL))
		{
			return root;
		}

		TreeNode* TNode = root;

		if ((TNode->left!=NULL)||(TNode->right!=NULL))
		{
			InvertChildNodes(TNode);
		}

		invertTree(TNode->left);
		invertTree(TNode->right);
		return root;
	}


private:
	void InvertChildNodes(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return ;
		}

		TreeNode* tmpNode = TNode->left;
		TNode->left = TNode->right;
		TNode->right = tmpNode;
	   
		return;
	}
};


int main()
{



	getchar();
	return 0;
}
