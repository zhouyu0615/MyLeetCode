#include <iostream>
#include <vector>

using namespace std;

/* Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) { ; };
 };

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* TNode = root;
		TreeNode* lastCheckNode=root;
		while (TNode!=NULL)
		{
			bool existp = checkNodes(TNode, p);
			bool existq = checkNodes(TNode, q);

			if (existp&&existq)
			{
				lastCheckNode = TNode;
			}
			else
			{
				return lastCheckNode;
			}
			
			if (checkNodes(root->left, p) && checkNodes(root->left, q))
			{
				TNode = TNode->left;
			}
			else
			{
				TNode = TNode->right;
			}

		}
		return lastCheckNode;
	}

private:
	bool checkNodes(TreeNode* root,TreeNode* targetNode)
	{
		if (root==NULL)
		{
			return false;
		}
		if (root==targetNode)
		{
			return true;
		}
		return (checkNodes(root->left, targetNode) || checkNodes(root->right, targetNode));
	}
};



class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root==NULL)
		{
			return NULL;
		}

		if (root==p||root==q)
		{
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left!=NULL&&right!=NULL)
		{
			return root;
		}
		return left == NULL ? right : left;
	}
};


int main()
{


	getchar();
	return 0;
}