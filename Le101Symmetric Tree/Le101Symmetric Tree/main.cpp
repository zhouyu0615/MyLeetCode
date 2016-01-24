#include <vector>

using namespace std;


/* Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//有漏洞，可以混淆树，骗过该种检查//
class Solution {
public:
	bool isSymmetric(TreeNode* root) {

		Inorder(root);

		int i = 0;
		int j = vTNodes.size() - 1;
		while (i<j)
		{
			if (vTNodes[i]!=vTNodes[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
private:
	vector<int> vTNodes;
	void Inorder(TreeNode* TNode)
	{
		if (TNode==NULL)
		{
			return;
		}
		if (TNode->left!=NULL)
		{
			Inorder(TNode->left);
		}		
		vTNodes.push_back(TNode->val);
		if (TNode->right!=NULL)
		{ 
			Inorder(TNode->right);
		}		
	}
};



class Solution {
public:
	bool isSymmetric(TreeNode* root) {

		if (root==NULL)
		{
			return true;
		}
		return isSymmetricNode(root->left, root->right);
	}

	bool isSymmetricNode(TreeNode* left, TreeNode* right)
	{
		
		if (left==NULL&&right==NULL)
		{
			return true;
		}else if (left==NULL||right==NULL)
		{
			return false;
		}


		if (left->val != right->val)
		{
			return false;
		}
		return(isSymmetricNode(left->left, right->right) && isSymmetricNode(left->right, right->left));

	}
};

