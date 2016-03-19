#include <iostream>
#include <stack>
#include <vector>

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
	int kthSmallest(TreeNode* root, int k) {
		
		int NumCount = 0;
		stack<TreeNode*> TNodesStack;

		TreeNode* Tnode = root;
		while (Tnode!=NULL||!TNodesStack.empty())
		{
			while (Tnode!=NULL)
			{
				TNodesStack.push(Tnode);
				Tnode = Tnode->left;
			}

			Tnode = TNodesStack.top();
			
			TNodesStack.pop();
			NumCount++;

			if (NumCount==k)
			{
				return Tnode->val;
			}

			Tnode = Tnode->right;
		}
	}
};



class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {

		key = k;
		
		Inorder(root);

	}

private:
	int NumOfCount = 0;
	int key=0;
	int result = 0;

	void Inorder(TreeNode* tnode)
	{
		if (tnode==NULL)
		{
			return;
		}

		Inorder(tnode->left);
		NumOfCount++;
		if (NumOfCount==key)
		{
			result = tnode->val;
			return;
		}
		Inorder(tnode->right);

	}
};


int main()
{

	getchar();
	return 0;
}
