#include <iostream>
#include <vector>
#include <stack>



using namespace std;


/**
* Definition for a binary tree node.*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {


		postOrder(root);
		return result;
	}

private:
	vector<int> result;
	void  postOrder(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return;
		}

		postOrder(TNode->left);
		postOrder(TNode->right);

		result.push_back(TNode->val);
	}

};


class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {

		vector<int> result;
		stack<TreeNode*> TNodeStack;

		TreeNode* TNode = root;

		if (TNode==NULL)
		{
			return result;
		}
		TNodeStack.push(TNode);
		while (!TNodeStack.empty())
		{
			TNode = TNodeStack.top();
			TNodeStack.pop();

			result.push_back(TNode->val);

			if (TNode->left!=NULL)
			{
				TNodeStack.push(TNode->left);
			}
			if (TNode->right!=NULL)
			{
				TNodeStack.push(TNode->right);
			}
		}

		reverse(result.begin(), result.end());

		return result;
	}
};