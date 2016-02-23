#include <iostream>
#include <queue>

using namespace std;


/*Definition for binary tree*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		Inorder(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return  !BstNodes.empty();
	}

	/** @return the next smallest number */
	int next() {
		CurTNode = BstNodes.front();
		BstNodes.pop();
		return CurTNode->val;
	}
private:
	queue<TreeNode* > BstNodes;
	TreeNode* CurTNode;
	void Inorder(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return;
		}
		Inorder(TNode->left);
		BstNodes.push(TNode);
		Inorder(TNode->right);
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/


int main()
{

	getchar();
	return 0;
}
