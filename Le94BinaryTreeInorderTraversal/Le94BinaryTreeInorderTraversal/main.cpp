#include <iostream>
#include <vector>
#include <stack>


using namespace std;

/*Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {

		Inorder(root);
		
		return result;
	}

private:
	vector<int> result;
	
	void Inorder(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return;
		}
		Inorder(TNode->left);
		result.push_back(TNode->val);
		Inorder(TNode->right);
	}
};



class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> TNodeStack;

		TreeNode* TNode = root;
		while (TNode!=NULL||!TNodeStack.empty())
		{
			while (TNode!=NULL)
			{
				TNodeStack.push(TNode);
				TNode = TNode->left;
			}

			TNode = TNodeStack.top();
			TNodeStack.pop();

			result.push_back(TNode->val);

			TNode = TNode->right;
		}
		return result;
	}
};



int main()
{

	getchar();
	return 0;
}



