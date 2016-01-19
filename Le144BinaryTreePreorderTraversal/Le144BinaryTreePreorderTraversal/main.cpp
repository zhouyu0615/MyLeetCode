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
	vector<int> preorderTraversal(TreeNode* root) {

		Preoredr(root);

		return result;
	}
private:
	vector<int> result;
	void Preoredr(TreeNode* TNode)
	{		
		if (TNode==NULL)
		{
			return;
		}
		result.push_back(TNode->val);
		Preoredr(TNode->left);
		Preoredr(TNode->right);
	}
};




class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> result;
		stack<TreeNode*> TNodeStack;
		TreeNode* TNode = root;

		while (TNode!=NULL||!TNodeStack.empty())
		{

			while (TNode!=NULL)
			{
				TNodeStack.push(TNode);
				result.push_back(TNode->val);
				TNode = TNode->left;
			}

			TNode = TNodeStack.top();
			TNodeStack.pop();
			
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
