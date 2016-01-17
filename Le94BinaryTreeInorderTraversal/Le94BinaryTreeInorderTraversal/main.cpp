#include <iostream>
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



int main()
{

	getchar();
	return 0;
}



