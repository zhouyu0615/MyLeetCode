#include <iostream>
#include <vector>

using namespace std;


/**
* Definition of TreeNode:*/
class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
};

class Solution {
public:
	/**
	* @param root: The root of the binary search tree.
	* @param A and B: two nodes in a Binary.
	* @return: Return the least common ancestor(LCA) of the two nodes.
	*/
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
		// write your code here

		if (root==NULL||root==A||root==B)
		{
			return root;
		}

		TreeNode* tNode = root;
		TreeNode* preNode = root;

		while (tNode!=NULL)
		{		

			int left = hasNode(tNode->left, A) || hasNode(tNode->left, B);
			int right = hasNode(tNode->right, A) || hasNode(tNode->right, B);

			if ((tNode==A||tNode==B)&&(left||right))
			{
				return tNode;
			}
			if (left&&right)
			{
				return tNode;
			}
			preNode = tNode;
			if (left)
			{
				tNode = tNode->left;
			}
			else
			{
				tNode = tNode->right;
			}
		}
		return preNode;
	}
private:
	bool hasNode(TreeNode* root, TreeNode* tNode)
	{
		if (root==NULL)
		{
			return false;
		}
		if (root==tNode)
		{
			return true;
		}
		return hasNode(root->left, tNode)||hasNode(root->right,tNode);
	}
};

int main()
{

	Solution testCase;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	TreeNode* A = root->left->left;
	root->left->left->left = new TreeNode(4);
	root->left->left->left->left = new TreeNode(5);
	TreeNode* B = root->left->left->left->left;


	testCase.lowestCommonAncestor(root, A, B); 


	getchar();
	return 0;
}