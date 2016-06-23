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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0 || inorder.size() != preorder.size())
		{
			return NULL;
		}

		return Construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

	}
private:
	TreeNode* Construct(vector<int>& preorder,int preStart,int preEnd,
		vector<int>& inorder, int inStart, int inEnd)
	{
		if (preEnd<preStart||inEnd<inStart)
		{
			return NULL;
		}

		TreeNode* root=new TreeNode(preorder[preStart]);

		if (preStart == preEnd&&inStart == inEnd&&preorder[preStart] == inorder[inStart])
		{
			return root;
		}

		int rootInorder = 0;
		for (int i = inStart; i <= inEnd; i++)
		{
			if (inorder[i] == preorder[preStart])
			{
				rootInorder = i;
				break;
			}
		}

		int leftLen = rootInorder - inStart;
		if (leftLen>0)
		{
			root->left = Construct(preorder, preStart + 1, preStart + leftLen,
				inorder, inStart, rootInorder - 1);
		}
		if (leftLen<preEnd-preStart)
		{
			root->right = Construct(preorder, preStart + leftLen+1, preEnd,
				inorder, rootInorder + 1, inEnd);
		}
		return root;
	}
};




int main()
{

	getchar();
	return 0;
}


